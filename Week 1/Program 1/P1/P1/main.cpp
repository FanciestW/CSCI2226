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
    if(input && output){
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
    } else cout << "File Error" << endl;
    input.close();
    output.close();
    bye();
}

/*=============================================================================
This works
=============================================================================*/
void compress(ifstream& input, ofstream& output){
    char c, k;
    int counter = 1;
    input.get(c);
    for(;;){
        input.get(k);
        if(input.eof()) break;
        if(c == k){
            if(counter >= 255){
                output << (unsigned char)255 << c << (unsigned char)counter;
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
                output << (unsigned char)255 << c << (unsigned char)counter;
                c = k;
                counter = 1;
            }
            
        }
    }
    output << c;
}

/*=============================================================================
This does NOT work
=============================================================================*/
void decompress(ifstream& input, ofstream& output){
    cout << "De-compression non-functional" << endl;
    char c, ch, count;
    for(;;){
        input.get(c);
        if(input.eof()) break;
        if(c == (char)255){
            input.get(ch);
            input.get(count);
            output << string((int)count, (int)ch);
        }
        else output << c;
    }
}