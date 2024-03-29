#ifndef BIG_NUMBER_H
#define BIG_NUMBER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdlib.h>

class BigNumber {
    private:
        const int whole_size = 13;
        const int fraction_size = 27;
        const int chunk = 100000000;
        int sign;
        std::vector <int> whole_part;
        std::vector <int> fraction;
        
    public:
        BigNumber(std::string s);
        BigNumber();

        std::string to_string () const;
        void change_sign();
        int get_sign () const;
        int get_whole_number (int index) const;
        int get_fraction_number (int index) const;
        int get_whole_size () const;
        int get_fraction_size () const;

        BigNumber operator- () const;
        BigNumber& operator+= (const BigNumber&);
        BigNumber& operator-= (const BigNumber&);
        BigNumber& operator*= (const BigNumber&);
        BigNumber& operator/= (const BigNumber&);
};

BigNumber operator+ (BigNumber first, const BigNumber& second);
BigNumber operator- (BigNumber first, const BigNumber& second);
BigNumber operator* (BigNumber first, const BigNumber& second);
BigNumber operator/ (BigNumber first, const BigNumber& second);

bool operator== (const BigNumber& first, const BigNumber& second);
bool operator!= (const BigNumber& first, const BigNumber& second);
bool operator< (const BigNumber& first, const BigNumber& second);
bool operator> (const BigNumber& first, const BigNumber& second);
BigNumber abs(const BigNumber& argument);

#endif 