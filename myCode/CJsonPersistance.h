/*
 * CJsonPersistance.h
 *
 *  Created on: Jan 17, 2017
 *      Author: Avinash
 */

#ifndef CJSONPERSISTANCE_H_
#define CJSONPERSISTANCE_H_


#include "string.h"
#include "fstream"
#include"CPersistentStorage.h"
//using namespace APT;


class CJsonPersistance: public CPersistentStorage
{

private:
    std::fstream m_WpName;
	std::fstream m_poiname;
	std::string wppoiFileName;
//    CJsonScanner lnkCJsonScanner;
public:
	//States are declared here.
	enum states{WAITING_FOR_NEXT_TOKEN,WAITING_FOR_THE_NAME_SEPARATOR,WAITING_FOR_THE_ATTRIBUTE,
		WAITING_FOR_THE_DB_NAME,WAITING_FOR_DB_TO_START,WAITING_FOR_THE_ATTRIBUTE_OBJECT};


/**
			* Set the name of the media to be used for persistent storage.
			* The Exact interpretation of the name depends on the implementation
			* of the component.
			*
			* @param name the media to be used
			*/
		     void setmediaName(std::string name);

			/**
			 * write the data to the persistent storage
			 *
			 * @param waypointDb the database with way points
			 * @param poiDb the database with points of interest
			 * @return true if the data could be saved successfully
			 */

			 bool writeData(const CWpDatabase& waypointDb,const CPoiDatabase& poiDb);
			/**
			 * The mode to be used when reading the databases
			 */
			/**
			 * Fill the databases with the data from persistent storage.If merge mode is MERGE,the content in the persistent
			 * storage will be merged with any content already existing in the data bases.If merge mode is REPLACE,already
			 * existing content will be removed before inserting the content from the persistent storage.
			 *
			 * @param waypointDb the the database with waypoints
			 * @param poiDb the database with points of interest
			 * @param mode the merge mode
			 * @return true if the data could be read successfully
			 */
			 bool readData (CWpDatabase& waypointDb,CPoiDatabase& poiDb,MergeMode mode);

        	/*Default constructor of the class*/

			 CJsonPersistance (){

			 }

			~ CJsonPersistance(){

			 			 }


		    /*Default destructor of the class*/

};

#endif /* CJSONPERSISTANCE_H_ */
