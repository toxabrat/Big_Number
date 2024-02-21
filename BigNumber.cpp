#include "BigNumber.h"
void Big0 (int& sign, std::vector <int> &whole_part, std::vector <int> &fraction, 
                                                    const int whole_size, const int fraction_size, const int chunk)
{
    sign = 1;
    std::fill_n(whole_part.begin(), whole_size, chunk - 1);
    std::fill_n(fraction.begin(), fraction_size, chunk - 1);
}

void MAXBigNumber (int& sign, std::vector <int>& whole_part, std::vector <int>& fraction, 
                                                    const int whole_size, const int fraction_size, const int chunk)
{
    sign = 1;
    std::fill_n(whole_part.begin(), whole_size, chunk - 1);
    std::fill_n(fraction.begin(), fraction_size, chunk - 1);
}

BigNumber BigNumber::operator- () const 
{
    BigNumber copy = *this;
    copy.sign = -sign;
    return copy;
}

BigNumber abs(const BigNumber& argument)
{
    if(argument.sign == 1) {
        return argument;
    } else {
        return -argument;
    }
}

void str_make_vec(int point_pos, std::vector<int>& aray, const std::string& s, int vector_type, const int& chunk) 
{ // vector_type: 0 - whole_part, 1 - fraction
    int number = 0;
    int degre10 = 1;
    int i = point_pos;
    if(vector_type) {
        degre10 = chunk / 10;
        i = point_pos + 2;
    }

    while((!vector_type && i > -1 && s[i] != '-') || (vector_type && i < static_cast<int>(s.size()))) {
        if(!vector_type) {
            if(number + degre10 >= chunk){
                aray.push_back(number);
                number = 0;
                degre10 = 1;
            }
            number += (s[i] - '0') * degre10;
            degre10 *= 10;
            i--;
        } else {
            if(degre10 == 0){
                aray.push_back(number);
                number = 0;
                degre10 = chunk / 10;
            }
            number += (s[i] - '0') * degre10;
            degre10 /= 10;
            i++;
        }
    }
    if (number > 0) {
        aray.push_back(number);
    }
}

BigNumber::BigNumber(std::string s)
{
    if(s.size() == 0) {
        return;
    }
    
    if(s[0] == '-') {
        sign = -1;
    } else {
        sign = 1;
    }
    
    int point_pos = 0;
    while(point_pos + 1 < static_cast<int>(s.size()) && s[point_pos + 1] != '.') {point_pos ++;}

    str_make_vec(point_pos, whole_part, s, 0, chunk);
    str_make_vec(point_pos, fraction, s, 1, chunk);
    whole_part.resize(static_cast<size_t>(whole_size));
    fraction.resize(static_cast<size_t>(fraction_size));
}

std::string BigNumber::to_string() const
{
    std::string s = "";
    int last_whole_chunk = 0, last_fract_chunk = 0; 
    for(int i = 0; i < whole_size; i++) {
        if(whole_part[i]) {last_whole_chunk = i;}
    }
    for(int i = 0; i < fraction_size; i++) {
        if(fraction[i]) {last_fract_chunk = i;}
    }

    if(!(last_fract_chunk == 0 && fraction[last_fract_chunk] == 0)) {
        s.push_back('.');
        for(int i = 0; i <= last_fract_chunk; i++) {
            if(i != last_fract_chunk) {
                int degre10 = chunk;
                while(degre10 > 1) {
                    s.push_back((fraction[i] % degre10) / (degre10 / 10) + '0');
                    degre10 /= 10;
                }
            } else {
                int degre10 = chunk;
                while(degre10 > 1 && fraction[i] % degre10 != 0) {
                    s.push_back((fraction[i] % degre10) / (degre10 / 10) + '0');
                    degre10 /= 10;
                }
            }
        }
        std::reverse(s.begin(), s.end());
    }
    
    if(last_whole_chunk == 0 && whole_part[0] == 0) {
        s.push_back('0');
    }
    for(int i = 0; i <= last_whole_chunk; i++){
        if(i != last_whole_chunk) {
            int degre10 = chunk;
            int number = whole_part[i];
            while(degre10 > 1) {
                s.push_back('0' + number % 10);
                number /= 10;
                degre10 /= 10;
            }
        } else {
            int number = whole_part[i];
            while(number > 0) {
                s.push_back('0' + number % 10);
                number /= 10;
            }
        }
    }

    if(sign == -1) {
        s.push_back('-');
    }

    std::reverse(s.begin(), s.end());
    return s;
}

bool operator== (const BigNumber& first, const BigNumber& second)
{
    return (first.sign == second.sign && first.whole_part == second.whole_part 
                                                            && first.fraction == second.fraction);
}

bool operator!= (const BigNumber& first, const BigNumber& second)
{
    return !(first == second);
}

bool operator< (const BigNumber& first, const BigNumber& second)
{
    if(first.sign != second.sign)
    {
        return first.sign < second.sign;
    } 

    int flag = 0;
    for(int i = first.whole_size - 1; i > -1 && !flag; i--) {
        if(first.whole_part[i] < second.whole_part[i]) {
            flag = 1;
        } else if(first.whole_part[i] > second.whole_part[i]) {
            flag = -1;
        }
    }
    for(int i = 0; i < first.fraction_size && !flag; i++) {
        if(first.fraction[i] < second.fraction[i]) {
            flag = 1;
        } else if(first.fraction[i] > second.fraction[i]) {
            flag = -1;
        }
    }
    if((flag == 1 && first.sign == 1) || (flag == -1 && first.sign == -1)){
        return true;
    }
    return false;
}

bool operator> (const BigNumber& first, const BigNumber& second)
{
    return (second < first && second != first);
}

BigNumber& BigNumber::operator+= (const BigNumber& other) 
{
    if(sign == other.sign && abs(sign) == 1) {
        long long total = 0;
        for (int i = fraction_size - 1; i > -1; i--) {
            total += fraction[i] + other.fraction[i];
            fraction[i] = total % chunk;
            total /= chunk;
        }

        for (int i = 0; i < whole_size; i++) {
            total += whole_part[i] + other.whole_part[i];
            whole_part[i] = total % chunk;
            total /= chunk;
        }
        
        if(total > 0) {
            MAXBigNumber(sign, whole_part, fraction, whole_size, fraction_size, chunk);
        }
        return *this;
    } else if(sign == -1) {
        sign = 1;
        *this -= other;
        if(*this != BigNumber("0")) {
            sign *= -1;
        }
        return *this;
    } else {
        *this -= -other;
        return *this;
    }
}

BigNumber& BigNumber::operator-= (const BigNumber& other) 
{
    if(sign == other.sign) {
        if(*this == other){
            sign = 1;
            Big0(sign, whole_part, fraction, whole_size, fraction_size, chunk);
            return *this;
        }

        int comparison = 0;
        if(abs(*this) > abs(other)) {
            comparison = 1;
        }

        for(int i = whole_size - 1; i > -1; i--) {
            if(comparison) {
                whole_part[i] -= other.whole_part[i];
            } else {
                whole_part[i] = other.whole_part[i] - whole_part[i];
            }
            if (whole_part[i] < 0) {
                whole_part[i] = chunk + whole_part[i];
                whole_part[i + 1] -= 1;
            }
        }

        for(int i = 0; i < fraction_size; i++) {
            if(comparison) {
                fraction[i] -= other.fraction[i];
            } else {
                fraction[i] = other.fraction[i] - fraction[i];
            }
            if(fraction[i] < 0) {
                if(i == 0) {
                    whole_part[0] -= 1;
                    fraction[i] = chunk + fraction[i];
                } else {
                    fraction[i - 1] -= 1;
                    fraction[i] = chunk + fraction[i];
                }
            }
        }

        if((comparison && other.sign == 1) || (!comparison && other.sign == -1)){
            sign = 1;
        } else {
            sign = -1;
        }
        return *this;
    } else {
        *this += -other;
        return *this;
    }
}

BigNumber& BigNumber::operator*= (const BigNumber& other)
{
    if(*this == BigNumber("0")) {
        return *this;
    } else if(other == BigNumber("0")) {
        Big0(sign, whole_part, fraction, whole_size, fraction_size, chunk);
        return *this;
    }

    std::vector <long long> mult_whole (whole_size);
    std::vector <long long> mult_fraction (fraction_size);
    for(int i = -fraction_size; i < whole_size; i ++) {
        for(int i1 = std::max(-fraction_size, -fraction_size - i); i + i1 < whole_size && i1 < whole_size; i1++) {
            long long value1, value2;
            if (i >= 0) {
                value1 = whole_part[i];
            } else {
                value1 = fraction[-i - 1];
            }

            if(i1 >= 0) {
                value2 = other.whole_part[i1];
            } else {
                value2 = other.fraction[-i1 - 1];
            }

            if(i + i1 >= 0) {
                mult_whole[i + i1] += value1 * value2;
            } else {
                mult_fraction[-(i + i1) - 1] += value1 * value2;
            }
        }
    }

    long long total = 0;
    for(int i = fraction_size - 1; i > -1; i--) {
        total += mult_fraction[i];
        fraction[i] = total % chunk;
        total /= chunk;
    }
    for(int i = 0; i < whole_size; i++) {
        total += mult_whole[i];
        whole_part[i] = total % chunk;
        total /= chunk;
    }

    if(sign != other.sign) {
        sign = -1;
    } else {
        sign = 1;
    }
    if(total > 0) {
        sign = 1;
        MAXBigNumber(sign, whole_part, fraction, whole_size, fraction_size, chunk);
    }
    return *this;
}

BigNumber& BigNumber::operator/= (const BigNumber& other)
{
    if(other == BigNumber("0")) {
        std::cerr<<"ошибка во время деления!";
        exit(1);
    }

    if(*this == BigNumber("0")) {
        return *this;
    }

    BigNumber dividend = BigNumber(*this);
    Big0(sign, whole_part, fraction, whole_size, fraction_size, chunk);

    for(int i = whole_size - 1; i > -1; i--) {
        int left = -1, right = chunk - 1;
        while(right - left > 1) {
            int x = (left + right) / 2;
            whole_part[i] = x;
            if (abs(*this * other) > abs(dividend) || abs(*this * other) == abs(dividend)) {
                right = x;
            } else {
                left = x;
            }
        }
        whole_part[i] = right;
    }
    for(int i = 0; i < fraction_size; i++) {
        int left = -1, right = chunk - 1;
        while(right - left > 1) {
            int x = (left + right) / 2;
            fraction[i] = x;
            if (abs(*this * other) > abs(dividend) || abs(*this * other) == abs(dividend)) {
                right = x;
            } else {
                left = x;
            }
        }
        fraction[i] = right;
    }

    if(sign == other.sign) {
        sign = 1;
    } else {
        sign = -1;
    }
    return *this;
}

BigNumber operator+ (BigNumber first, const BigNumber& second)
{
    first += second;
    return first;
}

BigNumber operator- (BigNumber first, const BigNumber& second)
{
    first -= second;
    return first;
}

BigNumber operator*  (BigNumber first, const BigNumber& second)
{
    first *= second;
    return first;
}

BigNumber operator/ (BigNumber first, const BigNumber& second)
{
    first /= second;
    return first;
}
