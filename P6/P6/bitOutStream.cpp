/*
 * bitOutStream.cpp
 *
 *  Created on: Apr 26, 2016
 *      Author: jdham_000
 */

#include "bitOutStream.hpp"


void BitOutStream::createCode(Node* scan , string code){
	if(scan->getChar() != '*'){
		codeTable[scan->getChar()] = code;
	}
	if(scan->getLeft() != nullptr)createCode(scan->getLeft(), code + "0");
	if(scan->getRight() != nullptr)createCode(scan->getRight(), code + "1");
}

void BitOutStream::printCode(){
	cout << "===========================================================================" << endl;
	cout << "Character Codes:" << endl;
	for(auto it : codeTable) {
		if(isprint(it.first))cout << it.first << ": " << it.second << '\n';
		else cout << (int)it.first << ": " << it.second << '\n';
	}
	cout << "===========================================================================" << endl;
}

void BitOutStream::insertCode(){
	map <char, string>::iterator p;
	char inputChar;
	ifstream infile("test.txt");
	if (!infile.is_open()) fatal("test.txt did not open. \n");
	infile >> noskipws;
	for(;;){
		inputChar = infile.get();
		if(infile.eof()) break;
		p = codeTable.find(inputChar);
		string s = p->second;
		size_t n = s.length();
		for(size_t k = 0; k < n; ++k){
			insertBit(s[k] - '0');
		}
	}
}

void BitOutStream::insertBit ( int c ){
    bits <<= 1;         // Make space for new bits.
    bits |= (c & 1);    // OR in the single low order bit.
    len ++;             // This BitStream is now longer.
    if (len == 8) {
        if ( bits==0 ) cout <<"About to write a zero byte." << endl;
       // cout <<"Writing 8 bits: " <<hex << (unsigned)bits <<endl;
        bytecount++;
        cout << "byte count: " << bytecount << endl;
        bitOut << bits;
        len = bits = 0;
    }
}

void BitOutStream::flushByte(){
	if (len != 0) {
		cout << "About to write padded byte" << endl;
	    bitOut << bits;
	}
	else cout << "No padding needed" << endl;
	cout << "Flushing bitOStream, wrote " << bytecount <<" bytes\n";
}

void BitOutStream::writeCount() {
    cout <<"Writing length byte: " << len <<endl;
    bytecount++;
    bitOut << (char) len;
}
