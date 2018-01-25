#ifndef BITCHAR_HPP
#define BITCHAR_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

class bitChar{
public:
    unsigned char* c;
    int shift_count;
    string BITS;

    bitChar();

    string readByBits(ifstream& inf);

    void setBITS(string X);

    int insertBits(ofstream& outf);

    string getBits(unsigned char X);

    void writeBits(ofstream& outf);

    ~bitChar();
};

#endif
