#ifndef CPOIDATABASE_H
#define CPOIDATABASE_H
#include "CPOI.h"
#include <map>
#include"Ctemplate.h"
class CPoiDatabase:public Ctemplate<std::string,CPOI>
{
private:
	//map STL container is used here to store the data dynamically.
	//std:: map<std:: string,CPOI>m_POI;
public:
    //used to add the POI[point of interest into the database]
    CPoiDatabase();

    //used to find the POI into,the data base that is being added to the CRoute
    void addPoi(CPOI const & poi);

    // it points to the data of string type to the CPOI class and also searches for a POI with the provided name.
      CPOI* getPointerToPoi(std::string name);
    // It will return the constant map containing poi
     const std::map<std::string, CPOI>& getPoi() const;
    // For freeing up the database and clearing the memory.
      bool isClearPoiDatabase();
      virtual~CPoiDatabase();
 };
/********************
**  CLASS END
*********************/
#endif /* CPOIDATABASE_H */
