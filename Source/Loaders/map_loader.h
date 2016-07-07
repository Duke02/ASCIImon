#ifndef MAP_LOADER_H
#define MAP_LOADER_H

#include "../Game/Map/map.h"

#include "b_loader.h"


class Map_Loader : private Loader_Base
{
    Map* m_p_map = nullptr;

    public:
        Map_Loader      ();

        void load       ( Map* p_map );

    private:
        void getName        ();

        void readMapChars       ();

        void countPortalsOnLine     ();

        void readPortal                 ();

        void readEncounterableAsciimon  ();

        const std::string getFileName   () const override;

};

#endif // MAP_LOADER_H
