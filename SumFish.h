#ifndef SUMFISH_H_INCLUDED
#define SUMFISH_H_INCLUDED
#include "Fish.hpp"
#include "summation.hpp"

class SumFish : public Summation<Fish, double> {

    void init() {
        *_result = 0.0;
    }

    void add(const Fish& e) {
        *_result += e.weight;
    }

};


#endif // SUMFISH_H_INCLUDED
