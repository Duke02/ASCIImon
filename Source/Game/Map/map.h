#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include <map>

#include "../Maths/vector2.h"

#include "portal.h"
#include "person.h"
#include "../Asciimon/encounterable_asciimon.h"

class Map
{
    friend class Map_Loader;
    //These maps are defined in "d_tiles.h"

    public:
        Map         ( const int x, const int y );

        void draw   ( const Vector2i& fieldLocation );

        const Vector2i& getLocation () const;

        void setLocation    ( const Vector2i& location );

        char at             ( const unsigned x, const unsigned y) const;
        char at             ( const Vector2i& location ) const;

        void moveMap        ( const Vector2i& amount );

        const Vector2i& getSize     () const;

        const Portal& getPortalAt   ( const Vector2i& location ) const;
        Person& getPersonAt   ( const Vector2i& location );

        unsigned getTotalAsciimonWeight  () const;

        const std::vector<Encounterable_ASCIImon>& getEncounterableAsciimon () const;

    private:
        void  setTileColour         ( const char tile );

        void getMapDrawStartAndEnd  ( const Vector2i& fieldLocation,
                                     int& xStart, int& yStart,
                                     int& xEnd,   int& yEnd );

        Vector2i                m_location;
        Vector2i                m_size;
        std::string             m_currentArea;
        std::string             m_currentAreaName   = "Unnamed";
        std::vector<Portal>     m_portals;
        std::vector<Person>     m_people;

        std::vector<Encounterable_ASCIImon>  m_encounterableASCIImon;

};

#endif // MAP_H
