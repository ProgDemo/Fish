#include <iostream>
#include "seqinfileenumerator.hpp"
#include "Fisherman.h"
#include "MaxFish.h"

using namespace std;

int main()
{
    /*SeqInFileEnumerator<Fishermann> fisherman("test.txt");
    for (fisherman.first(); !fisherman.end(); fisherman.next()) {
        std::cout << fisherman.current() << endl;
    }*/

    SeqInFileEnumerator<Fishermann> fisherman("test.txt");
    MaxFish maxFish;
    maxFish.addEnumerator(&fisherman);
    maxFish.run();
    cout << maxFish.opt() << endl;
    return 0;
}
