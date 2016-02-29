#ifndef LIST
#define LIST

#include "Cell.hpp"

class List{
private:
    Cell* head = nullptr;
    int count = 0;
    Cell* scan = nullptr;
    Cell* follow = nullptr;
    
public:
    List() = default;
    int size(){ return count; }
    bool isempty(){ return count == 0; }
    ~List();
    void start();
    const string* next();
    void find(string str);
    void insert(string str);
    void remove(string str);
    void print(ostream& out);
};

#endif