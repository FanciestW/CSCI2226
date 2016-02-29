#ifndef CELL
#define CELL

#include "tools.hpp"

class Cell{
    friend class List;
private:
    string data;
    Cell* next;
    Cell(string dt, Cell* nx = nullptr) : data(dt), next(nx){}
};

#endif