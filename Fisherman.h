#ifndef FISHERMAN_H_INCLUDED
#define FISHERMAN_H_INCLUDED
#include <vector>
#include <istream>
#include <sstream>
#include <ostream>
#include "stringstreamenumerator.hpp"
#include "Fish.hpp"
#include "FishReader.h"
#include "arrayenumerator.hpp"
#include "SumFish.h"

struct Fishermann {
    std::string name;
    std::vector<Fish> fish;

    friend std::istream& operator >> (std::istream& input, Fishermann& fishermann) {
        std::string line;
        getline(input, line);
        std::stringstream tmp;
        tmp << line;
        tmp >> fishermann.name;
        StringStreamEnumerator<Fish> enor(tmp);
        FishReader fishReader;
        fishReader.addEnumerator(&enor);
        fishReader.run();
        fishermann.fish = fishReader.result();
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, const Fishermann& fisherman) {
        output << fisherman.name << ": ";
        for (int i = 0; i < fisherman.fish.size(); ++i) {
            output << "\n\t" << fisherman.fish[i] << "\n";
        }
        return output;
    }

    double sum() const {
        std::vector<Fish> tmp = fish;
        ArrayEnumerator<Fish> arrayEnum(&tmp);
        SumFish sumFish;
        sumFish.addEnumerator(&arrayEnum);
        sumFish.run();
        return sumFish.result();
    }

    bool operator < (const Fishermann& rhs) {
        return sum() < rhs.sum();
    }

    bool operator > (const Fishermann& rhs) {
        return sum() > rhs.sum();
    }

    friend bool operator > (const Fishermann lhs, const Fishermann& rhs) {
        return lhs.sum() > rhs.sum();
    }

    friend bool operator < (const Fishermann lhs, const Fishermann& rhs) {
        return lhs.sum() < rhs.sum();
    }
};

#endif // FISHERMAN_H_INCLUDED
