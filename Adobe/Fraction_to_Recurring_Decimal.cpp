#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        
        long long quotient, remainder;

        long long num = numerator;
        long long den = denominator;

        bool neg = (num < 0 && den > 0) || (num > 0 && den < 0);

        num = abs(num);
        den = abs(den);
        quotient = num / den;
        remainder = num % den;

        string ret = (neg) ? "-" : "";

        ret += to_string(quotient);

        if (!remainder) {
            return ret;
        }

        ret += ".";

        unordered_map<long long,int> rmap;

        int strpos = ret.size();

        while (remainder != 0 && rmap.count(remainder) == 0){
            rmap[remainder] = strpos++;

            remainder *= 10;
            quotient = remainder / den;

            remainder -= den * quotient;
            ret.push_back('0' + quotient); 
        }
        if (remainder) {
            ret.insert(rmap[remainder], "(");
            ret.push_back(')');
        }

        return ret;
    }
};
