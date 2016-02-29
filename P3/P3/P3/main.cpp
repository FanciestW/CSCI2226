//
//  main.cpp
//  P3
//
//  Created by William Lin on 2/13/16.
//  Copyright © 2016 William Lin. All rights reserved.
//

#include "List.hpp"

int main(){
    banner();
    string fileName;
    cout << "File Name: ";
    cin >> fileName;
    List list = *new List();
    ifstream input(fileName);
    if(input.is_open()){
        for(;;){
            string line;
            getline(input, line);
            if(input.eof()) break;
            list.insert(line);
        }
    }
    else cout << "File Error" << endl;
    input.close();
    list.print(cout);
    bye();
}
