#include "List.hpp"

List::~List(){
    
    for(;;){
        scan = head;
        if(scan == NULL) break;
        head = head->next;
        delete scan;
    }
    
}

void List::print(ostream& out){
    out << "---------------\n";
    scan = head;
    while(scan != nullptr){
        out << scan->data << endl;
        scan = scan->next;
    }
    out << "================\n";
}

void List::remove(string str){
    find(str);
    if(scan == nullptr || scan->data != str)
        cout << endl << str << " is not in the list.\n\n";
    else{
        --count;
        if(follow == nullptr){
            head = head->next;
            delete scan;
        }
        else{
            follow->next = scan->next;
            delete scan;
        }
    }
}

const string* List::next(){
    if(scan == nullptr) return nullptr;
    else{
        //return scan&;
        follow = follow->next;
        scan = scan->next;
    }
    return nullptr;
}

void List::insert(string str){
    Cell *cell = new Cell(str);
    if(head == nullptr) head = cell;
    else{
        follow = scan;
        scan = head;
        while(scan != nullptr){
            if(scan->data >= str){
                if(scan == head){
                    head = cell;
                    cell->next = scan;
                }
                else{
                    follow->next = cell;
                    cell->next = scan;
                }
                break;
            }
            follow = scan;
            scan = scan->next;
        }
        if(scan == nullptr) follow->next = cell;
        scan = follow = nullptr;
    }
    count++;
}

void List::find(string str){
    if(count < 0) cout << "Error" << endl;
    else{
        scan = head;
        while(scan != nullptr){
            if(scan->data == str) break;
            else scan = scan->next;
        }
    }
}