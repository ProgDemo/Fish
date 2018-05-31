#ifndef MAXFISH_H_INCLUDED
#define MAXFISH_H_INCLUDED
#include "Fisherman.h"
#include "maxsearch.hpp"

class MaxFish : public MaxSearch<Fishermann, Fishermann> {

    Fishermann func(const Fishermann& fishermann) const {
        Fishermann tmp(fishermann);
        return tmp;
    }
};

#endif // MAXFISH_H_INCLUDED
