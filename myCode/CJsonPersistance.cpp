/*
 * CJsonPersistance.cpp
 *
 *  Created on: Jan 17, 2017
 *      Author: Avinash
 */

#include "CJsonPersistance.h"
#include "CJsonScanner.h"
#include "string.h"
using namespace std;
using namespace APT;



void CJsonPersistance::setmediaName(std::string name)
{
	wppoiFileName= name + "-Jasonwp_poi.json";
	m_WpName.open(wppoiFileName.c_str(), fstream:: out);
}

bool CJsonPersistance::writeData(const CWpDatabase& waypointDb,const CPoiDatabase& poiDb)
{
	string name,description;
		t_poi type;
		double latitude,longitude;
		map<string,CWaypoint> ptr_wayp;
		ptr_wayp=waypointDb.getWp();

		ofstream navigation_wayp;
		navigation_wayp.open((wppoiFileName+"-jasonwp_poi.jason").c_str(),fstream::out);
		m_WpName.open(wppoiFileName.c_str(), fstream:: out);

		navigation_wayp<<"{"<<endl;
		navigation_wayp<<"  \"waypoints\":  ["<<endl;
		for(map<string,CWaypoint>::iterator it_wp =ptr_wayp.begin();it_wp != ptr_wayp.end();++it_wp)
		{
			(*it_wp).second.getAllDataByReference(name,latitude,longitude);

			navigation_wayp<<"    {"<<endl;
			navigation_wayp<<"      \"name\":\""<<name<<"\","<<endl;
			navigation_wayp<<"      \"latitude\":"<<latitude<<","<<endl;
			navigation_wayp<<"      \"longitude\":"<<longitude<<endl;
			navigation_wayp<<"    }";
			if(it_wp == --ptr_wayp.end())
			{
				navigation_wayp<<"";
			}
			else
			{
				navigation_wayp<<",";
			}
			navigation_wayp<<endl;
		}
		navigation_wayp<<"  ],";
		navigation_wayp<<endl;



		map<string,CPOI> ptr_point;
		ptr_point=poiDb.getPoi();

		navigation_wayp<<"  \"pois\":  ["<<endl;
		for(map<string,CPOI>::iterator it_poi =ptr_point.begin();it_poi != ptr_point.end();++it_poi)
		{
			(*it_poi).second.getAllDataByReference(name,latitude,longitude,type,description);
			navigation_wayp<<"    {"<<endl;
			navigation_wayp<<"      \"name\":\""<<name<<"\","<<endl;
			navigation_wayp<<"      \"latitude\":"<<latitude<<","<<endl;
			navigation_wayp<<"      \"longitude\":"<<longitude<<","<<endl;
			switch(type) //Used for defining the enum type
			{
			case 1:
				navigation_wayp<<"      \"type\":"<<"\"Restaurant\""<<","<<endl;
				break;
			case 0:
				navigation_wayp<<"      \"type\":"<<"\"Sight seeing\""<<","<<endl;
				break;
			case 2:
				navigation_wayp<<"      \"type\":"<<"\"Shopping complex\""<<","<<endl;
				break;
			case 3:
				navigation_wayp<<"      \"type\":"<<"\"No Type\""<<","<<endl;
				break;
			default:
				break;
			}

			navigation_wayp<<"      \"description\":\""<<description<<"\""<<endl;
			navigation_wayp<<"    }";
			if(it_poi == --ptr_point.end())
			{
				navigation_wayp<<"";
			}
			else
			{
				navigation_wayp<<",";
			}
			navigation_wayp<<endl;
		}
		navigation_wayp<<"  ]"<<endl;
		navigation_wayp<<"}";

		navigation_wayp.close();
	return true;
}

bool CJsonPersistance::readData(CWpDatabase& waypointDb, CPoiDatabase& poiDb,MergeMode mode)
{

	std::map <string, CWaypoint> tempmap_wayp;

	std::map <string, CWaypoint>::iterator itr_wayp;
	std::map <string, CPOI> temporarymap_POI;
	std::map <string, CPOI>::iterator itr_POINT;

	int count_wayp_attr = 0;
	int count_POINT_attr = 0;

	bool wayp_detection = 0;
	bool POINT_detection = 0;
	//temporary CWaypoint attributes
	string wayp_name;
	double wayp_lat;
	double wayp_long;

	//temporary CPOI attributes
	string POINT_name;
	string POINT_desc;
	string POINT_type;
	double POINT_lat;
	double POINT_long;
	t_poi type_enum;


	std::ifstream navigation("data-Data.json");

	states current_state = WAITING_FOR_NEXT_TOKEN; //initial state
	CJsonScanner scan(navigation);
	CJsonToken *JsonToken;
	CJsonStringToken *StringToken;
	CJsonNumberToken *NumberToken;
	string DBName;
	string attribute_Name;
	string attribute_NameValue;
	double attribute_NumberValue;
	while ((JsonToken = scan.nextToken())!=NULL)

	{
		switch(current_state){
		case WAITING_FOR_NEXT_TOKEN:
			if(JsonToken->getType() == CJsonToken::BEGIN_OBJECT)
			{
				cout << " BEGIN_OBJECT " << endl;
				current_state = WAITING_FOR_THE_DB_NAME;
			}

			break;

		case WAITING_FOR_THE_DB_NAME:
			if(JsonToken->getType() == CJsonToken::STRING)
			{
				StringToken = (CJsonStringToken*)JsonToken;
				DBName = StringToken->getValue();

				if((strcmp(DBName.c_str(),"waypoints"))==0)
				{
					wayp_detection = 1;
					POINT_detection = 0;
					cout << "Waypoint DB" << endl;

				}
				else if((strcmp(DBName.c_str(),"pois"))==0)
				{
					wayp_detection = 0;
					POINT_detection = 1;

					cout << "POI DB" << endl;
				}
				else if((strcmp(DBName.c_str(),"pois"))!=0 && (strcmp(DBName.c_str(),"waypoints"))!=0)
				{
					cout<< "Database name Mismatch"<<endl;
					cerr<<"Error in  Line no "<<scan.scannedLine()<<"/n";
//					wp_detection = 1;
//					POI_detection = 0;
				}

				current_state = WAITING_FOR_THE_NAME_SEPARATOR;
			}
			break;

		case WAITING_FOR_THE_NAME_SEPARATOR:
			if(JsonToken->getType() == CJsonToken::NAME_SEPARATOR)
			{
				//cout << "NAME_SEPARATOR" << endl;
				JsonToken = scan.nextToken();
				if(JsonToken->getType() == CJsonToken::BEGIN_ARRAY)
				{
					//cout << "BEGIN_ARRAY" << endl;
					current_state = WAITING_FOR_DB_TO_START;
				}

				else if(JsonToken->getType() == CJsonToken::STRING)
				{
					//cout << "STRING" << endl;
					StringToken = (CJsonStringToken*)JsonToken;
					attribute_NameValue = StringToken->getValue();
					cout << attribute_NameValue <<" ; "<<endl;
					if(wayp_detection == 1)
					{
						if((strcmp(attribute_Name.c_str(),"name"))==0)
						{
							wayp_name = attribute_NameValue;
							count_wayp_attr++;
						}
						else
						{
							JsonToken = scan.nextToken();
						}

					}
					if(POINT_detection == 1)
					{
						if((strcmp(attribute_Name.c_str(),"name"))==0)
						{
							POINT_name = attribute_NameValue;
							count_POINT_attr++;
						}
						else if((strcmp(attribute_Name.c_str(),"Description"))==0)
						{
							POINT_desc = attribute_NameValue;
							count_POINT_attr++;
						}
						else if((strcmp(attribute_Name.c_str(),"Type"))==0)
						{
							POINT_type = attribute_NameValue;
//							if((strcmp(attribute_NameValue.c_str(),"Restaurant")==0) ||(strcmp(attribute_NameValue.c_str(),"Monument")==0)
//													||(strcmp(attribute_NameValue.c_str(),"Sightseeing")==0)||(strcmp(attribute_NameValue.c_str(),"Notype")==0)
//													)
//							{
//								POI_type = attribute_NameValue;
//
//							}
//							else
//							{
//								POI_type = "INVALID";
//
//							}
								count_POINT_attr++;
						}



					}

					current_state = WAITING_FOR_THE_ATTRIBUTE;
				}

				else if(JsonToken->getType() == CJsonToken::NUMBER)
				{
					NumberToken = (CJsonNumberToken*)JsonToken;
					attribute_NumberValue = NumberToken->getValue();
					if(wayp_detection == 1)
					{
						if((strcmp(attribute_Name.c_str(),"Latitude"))==0)
						{
							wayp_lat = attribute_NumberValue;
							count_wayp_attr++;
						}
						else if((strcmp(attribute_Name.c_str(),"Longitude"))==0)
						{
							wayp_long = attribute_NumberValue;
							count_wayp_attr++;
						}




					}

					if(POINT_detection == 1)
					{
						if((strcmp(attribute_Name.c_str(),"Latitude"))==0)
						{
//
//							if(attribute_NumberValue>=-90 && attribute_NumberValue<=90)
//							{
//
								POINT_lat = attribute_NumberValue;
//							}
//							else
//							{
//								POI_lat=0;
//								cerr<<"Incorrect Latitude Value in line no. "<<scan.scannedLine()<<endl;
//							}

							count_POINT_attr++;
						}
						else if((strcmp(attribute_Name.c_str(),"Longitude"))==0)
						{

//							if(attribute_NumberValue>=-90 && attribute_NumberValue<=90)
//							{
								POINT_long = attribute_NumberValue;
//							}
//							else
//							{
//								POI_long=0;
//								cerr<<"Incorrect Longitude Value in line no. "<<scan.scannedLine()<<endl;
//							}
							count_POINT_attr++;
						}


					}


					if(attribute_NumberValue>=-180 && attribute_NumberValue<=180)
					{
						cout << attribute_NumberValue << " ; "<<endl;
					}
					else
					{
						cout << "Invalid" << " ; "<<endl;
						cerr<<"Error in Scanned Line no. "<<scan.scannedLine()<<"/n";
					}
					current_state = WAITING_FOR_THE_ATTRIBUTE;
				}


			}
			break;

		case WAITING_FOR_DB_TO_START:
			if(JsonToken->getType() == CJsonToken::BEGIN_OBJECT)
			{
				//cout << "BEGIN_OBJECT" << endl;
				current_state = WAITING_FOR_THE_ATTRIBUTE_OBJECT;
			}
			break;


		case WAITING_FOR_THE_ATTRIBUTE_OBJECT:
			if(JsonToken->getType() == CJsonToken::STRING)
			{
				StringToken = (CJsonStringToken*)JsonToken;
				attribute_Name = StringToken->getValue();
				if((strcmp(attribute_Name.c_str(),"latitude")==0) ||(strcmp(attribute_Name.c_str(),"longitude")==0)
						||(strcmp(attribute_Name.c_str(),"name")==0)||(strcmp(attribute_Name.c_str(),"type")==0)
						||(strcmp(attribute_Name.c_str(),"description")==0))
				cout << attribute_Name << " : ";
				else
				{
					attribute_Name="Error";
					cerr<<"Attribute Name mismatch in line no. "<<scan.scannedLine()<<"/n";
					//JsonToken=scan.nextToken();
				}
				current_state = WAITING_FOR_THE_NAME_SEPARATOR;
			}


			else if(JsonToken->getType() == CJsonToken::BEGIN_OBJECT)
			{
				current_state = WAITING_FOR_THE_ATTRIBUTE_OBJECT;
			}
			break;

		case WAITING_FOR_THE_ATTRIBUTE:
			if(JsonToken->getType() == CJsonToken::VALUE_SEPARATOR)
			{
				current_state = WAITING_FOR_THE_ATTRIBUTE_OBJECT;
			}

			else if(JsonToken->getType() == CJsonToken::END_OBJECT)
			{
				if(count_wayp_attr == 3)
				{
					CWaypoint Temp_wp(wayp_name, wayp_lat, wayp_long);

				//	cout << wp_name << " " << wp_lat << " " << wp_long << endl;
					count_wayp_attr = 0;
					switch(mode)
					{
					case(MERGE):
										waypointDb.addWaypoint(Temp_wp);
					break;
					case(REPLACE):
										tempmap_wayp[wayp_name] = Temp_wp;
					break;
					default:
						cout << "ERROR: Invalid MODE" << endl;
					}
				}

				if(count_POINT_attr == 5)
				{
					cout << POINT_name << " " << POINT_lat << " " << POINT_long << " " << POINT_desc << " " << POINT_type << endl;
					count_POINT_attr = 0;
					if(POINT_type == "Restaurant")
						type_enum = restaurant;
					else if(POINT_type == "Sightseeing")
						type_enum = sightseeing;
					else if(POINT_type == "shopping complex")
						type_enum = shoppingcomplex;
					/*else if(POINT_type == "Notype")
						type_enum = NOTYPE;*/

					else
					{

						cerr << "Error: Invalid POI type. Line no. " << scan.scannedLine() << "/n";

					}

					CPOI Temp_POI(type_enum,POINT_name,POINT_desc, POINT_lat, POINT_long);

					switch(mode)
					{
					case(MERGE):
					poiDb.addPoi(Temp_POI);
					break;
					case(REPLACE):
					temporarymap_POI[POINT_name] = Temp_POI;
					break;
					default:
					cout << "ERROR: Invalid MODE" << endl;
					break;
					}
				}
				current_state = WAITING_FOR_THE_ATTRIBUTE;
			}

			else if(JsonToken->getType() == CJsonToken::END_ARRAY)
			{
				JsonToken = scan.nextToken();
				if(JsonToken->getType() == CJsonToken::VALUE_SEPARATOR)
				{
					current_state = WAITING_FOR_THE_DB_NAME;
				}

				else if(JsonToken->getType() == CJsonToken::END_ARRAY)
				{
					current_state = WAITING_FOR_THE_ATTRIBUTE;
				}
			}
			break;



		default:
			break;

		}
	}
	if(mode == REPLACE)
	{

		tempmap_wayp=waypointDb.getWp();
		temporarymap_POI=poiDb.getPoi();
	}

	return true;
}



