#ifndef FISHREADER_H_INCLUDED
#define FISHREADER_H_INCLUDED
#include "summation.hpp"
#include "Fish.hpp"
#include <vector>

class FishReader : public Summation<Fish, std::vector<Fish> > {

    void init() {
        _result->clear();
    }

    void add(const Fish& e) {
        _result->push_back(e);
    }

};

#endif // FISHREADER_H_INCLUDED
