
#ifndef CCSV_H_
#define CCSV_H_
#include<string>
//#include "CPoiDatabase.h"
//#include"CWpDatabase.h"
//#include"CNavigationSystem.h"
#include "CPersistentStorage.h"
#include <iostream>
#include<fstream>
#include<sstream>
#include<vector>


class CCSV: public CPersistentStorage
{
private:

	std::fstream m_WpName;
	std::fstream m_poiname;
	std::string wpFileName, poiFileName;
public:
	 CCSV();
	//virtual ~CCSV();

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
	 bool readData (CWpDatabase& waypointDb,CPoiDatabase& poiDb,MergeMode mode);

};


#endif /* CCSV_H_ */
