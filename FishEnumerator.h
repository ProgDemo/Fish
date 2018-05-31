#ifndef FISHENUMERATOR_H_INCLUDED
#define FISHENUMERATOR_H_INCLUDED
#include "enumerator.hpp"
#include "Fisherman.h"
#include "stringstreamenumerator.hpp"
#include <sstream>

class FishEnumerator : public Enumerator<Fish> {

    private:
        StringStreamEnumerator<* stringStreamEnumerator;
        Fish fish;

    public:
        FishEnumerator(std::stringstream& sstream) {
            StringStreamEnumerator = new StringStreamEnumerator(sstream);
        }

        void first() {

        }

        void next() {

        }

        bool end() const {

        }

        Item current() const {

        }

        ~Enumerator(){
            delete stringStreamEnumerator;
        }
};

#endif // FISHENUMERATOR_H_INCLUDED
