#ifndef floor_h
#define floor_h

#include "tree.h"

class Floor
{
    static const int LENGTH = 5;
    string *tab;
    int Snows;

public:
    Floor();
    ~Floor();
    void displayFloor();
    void exportFloor(string card);
    void addSnowman();
};

#endif // floor_h
