/*=============================================================================
 Created By: William Lin
 CSCI 2226 Data Structures and Algorithms
 Program 1
=============================================================================*/

#include "tools.hpp"

void compress(ifstream& input, ofstream& output);
void decompress(ifstream& input, ofstream& output);

int main() {
    banner();
    string fileName, targetName;
    int choice;
    cout << "1. Compress\n2. De-compress\nYour Choice: ";
    cin >> choice;
    cout << "File Name: ";
    cin >> fileName;
    cout << "Target Location: ";
    cin >> targetName;
    ifstream input = ifstream(fileName);
    ofstream output = ofstream(targetName);
    if(input.is_open() && output.is_open()){
        switch(choice){
            case 1:
                compress(input, output);
                break;
            case 2:
                decompress(input, output);
                break;
            default:
                cout << "Invalid Choice" << endl;
                break;
        }
    }
    input.close();
    output.close();
    bye();
}

void compress(ifstream& input, ofstream& output){
    char c, k;
    int counter = 1;
    input.get(c);
    while(!input.eof()){
        input.get(k);
        if(c == k){
            if(counter >= 255){
                output << (char)127 << c << counter;
                counter = 1;
            }
            else counter++;
        }
        if(c != k){
            if(counter < 4){
                output << string(counter, c);
                c = k;
                counter = 1;
            }
            else{
                output << (char)127 << c << counter;
                c = k;
                counter = 1;
            }
            
        }
    }
}

void decompress(ifstream& input, ofstream& output){
    char c, ch, count;
    while(!input.eof()){
        input.get(c);
        if(c == (char)127){
            input.get(ch);
            input.get(count);
            output << string(count, (int)ch);
        }
        else output << c;
    }
}