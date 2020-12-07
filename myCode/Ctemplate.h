/*
 * Ctemplate.h
 *
 *  Created on: Jan 17, 2017
 *      Author: Avinash
 */

#ifndef CTEMPLATE_H_
#define CTEMPLATE_H_
/*
#include "CPoiDatabase.h"
#include "CWpDatabase.h"
*/
#include <map>
template<class ttemplate_type,class ttemplate_Route>

class Ctemplate
{
private:
	std::map<ttemplate_type,ttemplate_Route>m_wayp_poi;
	//std:: map<std:: string,CPOI>m_POI;
public:
// Constructor of the class
	Ctemplate();
//	It adds the new waypoints sand the POI's according to the database
    void add_wayp_poi(ttemplate_Route const &object_wayp_poi);
//  To search in the database and return the pointer
    ttemplate_Route* getPointerToWayp_poi(ttemplate_type name);
//    It clears the database
    bool isClearwaypPoiDatabaseWayp_poi();
//   To link the database to the persistance classes.
     const std::map<ttemplate_type,ttemplate_Route> &getWayp_poi()const;
	/*virtual ~Ctemplate();*/
};
/*
 * Definitions of the corresponding methods
 */

template<class ttemplate_type, class ttemplate_Route>
void Ctemplate<ttemplate_type, ttemplate_Route>::add_wayp_poi(ttemplate_Route const &object_wayp_poi)
		{
	m_wayp_poi[object_wayp_poi.getName()]=object_wayp_poi;
		}


template<class ttemplate_type, class ttemplate_Route>
Ctemplate<ttemplate_type, ttemplate_Route>::Ctemplate()
{
}

template<typename ttemplate_type, typename ttemplate_Route>
ttemplate_Route* Ctemplate<ttemplate_type, ttemplate_Route>::getPointerToWayp_poi(
        ttemplate_type name)
        {
    typedef typename std::map<ttemplate_type, ttemplate_Route>::iterator itWayp_poi;

    for (itWayp_poi iterator = m_wayp_poi.begin();iterator != m_wayp_poi.end(); iterator++)
    {
        if (name == m_wayp_poi[name].getName())
        {
            return (&m_wayp_poi[name]);
        }
    }

    std::cout<< "Warning: it Could not find the Waypoints or Poi, something not in the POOl"
                << std::endl;

    return (NULL);

    }
	/*return (&m_wayp_poi[name]);
		}
*/
template<class ttemplate_type, class ttemplate_Route>
bool Ctemplate<ttemplate_type, ttemplate_Route>::isClearwaypPoiDatabaseWayp_poi()
{
	m_wayp_poi.clear();
	return false;
}





template<class ttemplate_type, class ttemplate_Route>
inline const std::map<ttemplate_type, ttemplate_Route>& Ctemplate<
		ttemplate_type, ttemplate_Route>::getWayp_poi() const
{
	return m_wayp_poi;
}

#endif /* CTEMPLATE_H_ */
