#include "bitChar.hpp"


bitChar::bitChar()
    {
        shift_count = 0;
        c = (unsigned char*)calloc(1, sizeof(char));
    }

string bitChar::readByBits(ifstream& inf)
    {
        string s ="";
        char buffer[1];
        while (inf.read (buffer, 1))
        {
            s += getBits(*buffer);
        }
        return s;
    }

void bitChar::setBITS(string X)
    {
        BITS = X;
    }

int bitChar::insertBits(ofstream& outf)
    {
        int total = 0;

        while(BITS.length())
        {
            if(BITS[0] == '1')
                *c |= 1;
            *c <<= 1;
            ++shift_count;
            ++total;
            BITS.erase(0, 1);

            if(shift_count == 7 )
            {
                if(BITS.size()>0)
                {
                    if(BITS[0] == '1')
                        *c |= 1;
                    ++total;
                    BITS.erase(0, 1);
                }

                writeBits(outf);
                shift_count = 0;
                free(c);
                c = (unsigned char*)calloc(1, sizeof(char));
            }
        }

        if(shift_count > 0)
        {
            *c <<= (7 - shift_count);
            writeBits(outf);
            free(c);
            c = (unsigned char*)calloc(1, sizeof(char));
        }
        outf.close();
        return total;
    }

string bitChar::getBits(unsigned char X)
    {
        stringstream itoa;
        for(unsigned s = 7; s > 0 ; s--)
        {
            itoa << ((X >> s) & 1);
        }

        itoa << (X&1) ;
        return itoa.str();
    }

void bitChar::writeBits(ofstream& outf)
    {
        outf << *c;
    }

bitChar::~bitChar()
    {
        if(c)
            free(c);
    }
