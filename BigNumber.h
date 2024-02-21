#ifndef BIG_NUMBER_H
#define BIG_NUMBER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdlib.h>

class BigNumber{
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
        std::string to_string_with_zeros () const;
        void change_sign();
        int get_sign() const;

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