/*
 * CPersistentStorage.h
 *
 *  Created on: Dec 7, 2016
 *      Author: avina
 */

#ifndef CPERSISTENTSTORAGE_H_
#define CPERSISTENTSTORAGE_H_
#include "CPoiDatabase.h"
#include"CWpDatabase.h"
#include <iostream>
#include "CNavigationSystem.h"
#include<string>
#include <fstream>

class CPersistentStorage
{
private:

//           CNavigationSystem linkCNavigationSystem;




public:
			/**
			* Set the name of the media to be used for persistent storage.
			* The Exact interpretation of the name depends on the implementation
			* of the component.
			*
			* @param name the media to be used
			*/
		    virtual void setmediaName(std::string name)=0;

			/**
			 * write the data to the persistent storage
			 *
			 * @param waypointDb the database with way points
			 * @param poiDb the database with points of interest
			 * @return true if the data could be saved successfully
			 */

			virtual bool writeData(const CWpDatabase& waypointDb,const CPoiDatabase& poiDb)=0;
			/**
			 * The mode to be used when reading the databases
			 */
			enum MergeMode{MERGE,REPLACE};
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
			virtual bool readData (CWpDatabase& waypointDb,CPoiDatabase& poiDb,MergeMode mode)=0;
        	/*Default constructor of the class*/

		    /*Default destructor of the class*/
	        virtual ~CPersistentStorage();
};


#endif /* CPERSISTENTSTORAGE_H_ */
