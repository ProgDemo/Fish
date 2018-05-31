#ifndef FISH_HPP_INCLUDED
#define FISH_HPP_INCLUDED
#include <istream>
#include <ostream>

struct Fish {
    std::string name;
    double weight;

    friend std::istream& operator >> (std::istream& input, Fish& fish) {
        input >> fish.name >> fish.weight;
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, const Fish& fish) {
        output << fish.name << " (" << fish.weight << ")";
        return output;
    }
};


#endif // FISH_HPP_INCLUDED
