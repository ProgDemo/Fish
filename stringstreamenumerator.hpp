//Készítette:    Várkonyi Teréz Magda
//Dátum:         2018.05.03.
//Feladat:       Szövegfolyam felsorolóinak ősosztálya

#pragma once

#include <typeinfo>
#include <sstream>

#include "enumerator.hpp"

//Szövegfolyam elemeinek felsorolását definiáló osztály-sablon
//Műveletek: first(), next(), end(), current()
//Reprezentáció: _ss - a felsorolni kívánt szövegfolyam
//               _df  - az éppen felsorolt Item típusú elem
template <typename Item>  // Item implementálja az operator>>-t
class StringStreamEnumerator : public Enumerator<Item>
{
    protected:
        std::stringstream _ss;
        Item              _df;

    public:
        StringStreamEnumerator(std::stringstream& ss) {
            _ss<<ss.rdbuf();
        }

        void first()         final override { next();}
        void next()          final override { _ss >> _df; }
        bool end()     const final override { return !_ss;}
        Item current() const final override { return _df; }
};

