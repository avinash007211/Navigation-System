
#include "CCSV.h"
#include<vector>

CCSV::CCSV()
{
	// TODO Auto-generated constructor stub

}
void CCSV::setmediaName(std::string name)
{
	poiFileName = name + "-poi.txt";
	wpFileName  = name + "-wp.txt ";
}

bool CCSV::writeData(const CWpDatabase& waypointDb, const CPoiDatabase& poiDb)
{
	// File opening process
	m_WpName.open(wpFileName.c_str(), std::fstream:: out);
	m_poiname.open(poiFileName.c_str(), std::fstream:: out);

	std::map <std::string, CWaypoint>:: const_iterator i;
	for (i = waypointDb.getWp().begin(); i!= waypointDb.getWp().end(); i++){
		m_WpName << i->second.getName() << ";" << i->second.getLatitude() << ";"
				<< i->second.getLongitude() << std::endl;
	}


	std::map<std::string, CPOI>:: const_iterator p;
	std::string poiType;
	for (p = poiDb.getPoi().begin(); p!= poiDb.getPoi().end(); p++)
	{

		switch(p->second.getPoiType())
		{
		case 0:
			poiType = "restaurant";
			break;

		case 1:
			poiType = "sightseeing";
			break;

		case 2:
			poiType = "shoppingcomplex";
			break;

		case 3:
			poiType = "gasstation";
			break;

		case 4:
			poiType = "bank";
			break;

		default: ;
		}

		m_poiname << poiType << ";" << p->second.getName() << ";"<< p->second.getPoiDescription()
				<< ";" << p->second.getLatitude() << ";"	<< p->second.getLongitude() <<std:: endl;
	}
	if (m_WpName.is_open()) m_WpName.close();
	if (m_poiname.is_open())m_poiname.close();
	return true;
}

CPersistentStorage::~CPersistentStorage(){

}

/*
bool CCSV::readData(CWpDatabase& waypointDb, CPoiDatabase& poiDb, MergeMode mode)
{

	m_WpName.open(wpFileName.c_str(),std:: ifstream::in);
	m_WpName.seekg(0);

    //To read the Waypoint file

	// Clearing the database
	if (mode == REPLACE)
	{
		if(waypointDb.isClearWpDatabase()) std::cout << "Waypoint Database got cleared" << std::endl;
	}

	std::string s, b;
	std::string wpName, restString;
	std::vector<std::string> word;


	while(!m_WpName.eof())
	{
		if (m_WpName.is_open())
	{
			getline(m_WpName, b, '\n');
			word.push_back(b);
	}
		else std::cout << "Problem! file is not open" << std::endl << std::endl;
	}

	std::cout << "No of lines in Waypoint Database file: " << word.size()-1 << "/n";

	for (unsigned int l=0; l < word.size()-1; l++)
	{
		std::size_t found = word[l].find(';');
		wpName = word[l].substr(0, found);
		int wpCounter=0;
		if(ValidityofName(wpName))
	{
			std::cout << wpName <<std:: endl;
			++wpCounter;
	}
		else std::cerr << "Error: Invalid Waypoint name < Line: " << l+1
				<< " >: < Line content: " << word[l] << " >" <<"/n";

		restString = word[l].substr(found+1);
		std::size_t found1 = restString.find(';');
		double latitude, longitude;
		std::stringstream convertLatitude(restString.substr(0, found1));

		if(ValidityofCoordinateValue(restString.substr(0, found1)))
	{
			if(!(convertLatitude >> latitude)) latitude = 0;
			else
	{
				std::cout << "Latitude:" << latitude <<std:: endl;
				++wpCounter;
	}
	}

		else std::cerr << "Error: Invalid Latitude < Line: " << l+1 <<
				" >: > Line Content: " << word[l] << " >" << "/n";

		std::stringstream convertLongitude(restString.substr(found1+1));



		if (ValidityofCoordinateValue(restString.substr(found1+1)))
	{
			if(!(convertLongitude >> longitude)) longitude = 0;
			else
	{
				std::cout << "Longitude:" << longitude << std::endl;
				++wpCounter;
	}
	}
		else std::cerr << "Error: Invalid Longitude < Line: " << l+1 <<
				" >: > Line Content: " << word[l] << " >" << "/n";


		CWaypoint add(wpName, latitude, longitude);
		if(wpCounter == 3)
	{
			waypointDb.addWaypoint(add);
	}
		else std::cerr << "ERROR! Waypoint data is insufficient" << std::endl <<std:: endl;
	}




	m_poiname.open(poiFileName.c_str(),std:: ifstream::in);
	m_poiname.seekg(0);


	//For reading the POI file
	// Clearing the database
	if (mode == REPLACE)
	{
		if(poiDb.isClearPoiDatabase())std::cout << "POI Database is cleared" <<std:: endl <<std:: endl;
	}

	t_poi poiTypeEnum;
	std::string poiType, poiName, poiDescription;
	std::vector <std::string> poiWord;

	while(!m_poiname.eof())
	{
		if (m_poiname.is_open())
	{
			getline(m_poiname, b, '\n');
			poiWord.push_back(b);
	}
		else std::cout << "ERROR! file is not open" <<std:: endl << std::endl;
	}

	std::cout << "No of lines in POI Database file: " << poiWord.size()-1 <<"/n";

	for (unsigned int l=0; l < poiWord.size()-1; l++)
	{
		std::size_t foundp = poiWord[l].find(';');
		poiType = poiWord[l].substr(0, foundp);
		int poiCounter=0;

//		if(ValidityofName (poiType))
	{
			std::cout << "POI Type:" << poiType <<std:: endl;

			if (poiType == "restaurant")
	{
				poiTypeEnum = restaurant;
	}
			else if (poiType == "sightseeing")
	{
				poiTypeEnum = sightseeing;
	}
			else if (poiType == "shoppingcomplex")
	{
				poiTypeEnum = shoppingcomplex;
	}
			else if (poiName == "gasstation")
	{
				poiTypeEnum = gasstation;
	}
			else if (poiName == "bank")
	{
				poiTypeEnum = bank;
				++poiCounter;
	}
	}
			else std::cerr << "Error: Invalid POI type < Line: " << l+1
					<< " >: < Line content: " << poiWord[l] << " >" <<"/n";

			restString = poiWord[l].substr(foundp+1);
			std::size_t foundp1 = restString.find(';');
			double latitude_Poi = 0, longitude_Poi = 0;


			if(ValidityofName (restString.substr(0, foundp1)))
	{
				poiName = restString.substr(0, foundp1);
				std::cout << "POI Name: " << poiName <<std:: endl;
				++poiCounter;
	}


			else std::cerr << "Error: Invalid POI name < Line: " << l+1
					<< " >: < Line content: " << poiWord[l] << " >" <<"/n";


			std::string restStringAfterPoiName = restString.substr(foundp1+1);
			std::size_t foundp2 = restStringAfterPoiName.find(';');


			if (ValidityofName (restStringAfterPoiName.substr(0, foundp2)))
	{
				poiDescription = restStringAfterPoiName.substr(0, foundp2);
				std::cout << "POI description:" << poiDescription <<"/n";
				++poiCounter;
	}


			else std::cerr << "Error: Invalid POI description < Line: " << l+1
					<< " >: < Line content: " << poiWord[l] << " >" <<"/n";


			std::string restStringAfterPoiDescription = restStringAfterPoiName.substr(foundp2+1);
			std::size_t foundp3 = restStringAfterPoiDescription.find(';');
			std::stringstream convertLatitude(restStringAfterPoiDescription.substr(0, foundp3));


			if (ValidityofCoordinateValue(restStringAfterPoiDescription.substr(0, foundp3)))
	{
				if(!(convertLatitude >> latitude_Poi)) latitude_Poi = 0;
				else
	{
					std::cout << "Latitude:" << latitude_Poi <<"/n";
				++poiCounter;
	}
	}
			else std::cerr << "Error: Invalid Latitude < Line: " << l+1 <<
					" >: > Line Content: " << poiWord[l] << " >" <<"/n";


			std::stringstream convertLongitude(restStringAfterPoiDescription.substr(foundp3+1));

			if (ValidityofCoordinateValue(restStringAfterPoiDescription.substr(foundp3+1)))
	{
				if(!(convertLongitude >> longitude_Poi))
	{
					longitude_Poi = 0;
	}
				else
	{
					std::cout << "Longitude:" << longitude_Poi << std::endl <<std:: endl;
					++poiCounter;
	}
	}



			else std::cerr << "Error: Invalid Latitude < Line: " << l+1 <<
					" >: > Line Content: " << poiWord[l] << " >" <<"/n";



			CPOI addPoiFromDatabase(poiTypeEnum, poiName, poiDescription, latitude_Poi, longitude_Poi);
			if(poiCounter == 5)
	{
				poiDb.addPoi(addPoiFromDatabase);
	}
			else std::cerr << "ERROR! POI file data is insufficient" << std::endl << std::endl;

			}

		if (m_WpName.is_open()) m_WpName.close();
		if (m_poiname.is_open()) m_poiname.close();
		return true;
	}*/


/*
bool CCSV::ValidityofName(const std::string name)
{

}

bool CCSV::ValidityofCoordinateValue(const std::string value)
{
}
*/
