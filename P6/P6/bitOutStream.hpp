/*
 * bitOutStream.hpp
 *
 *  Created on: Apr 26, 2016
 *      Author: Stephen Hamilla
 */

#ifndef BITOUTSTREAM_HPP_
#define BITOUTSTREAM_HPP_

#include "node.hpp"
#include "tools.hpp"
#include <map>


class BitOutStream{
private:
	map <char, string> codeTable;
	int bytecount=0;
	ofstream& bitOut;
	int len=0;
	unsigned char bits;

public:
	BitOutStream(ofstream& out) : bitOut(out) {};
	~BitOutStream() = default;
	void createCode(Node* scan , string code);
	void printCode();
	void insertCode();
	void insertBit(int c);
	void writeCount();
	void flushByte();
};



#endif /* BITOUTSTREAM_HPP_ */
