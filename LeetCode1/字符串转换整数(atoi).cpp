#include<iostream>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int ret = 0;
        int i = 0;
        bool isPositiveNumber = true;
        while (s[i] == ' ') {
            i++;
        }
        if (s[i] == '-') {
            isPositiveNumber = false;
            i++;
        }
        else if (s[i] == '+') {
            i++;
        }
        int j = i;
        for (;j < s.size();j++) {
            if (!(s[j] >= '0' && s[j] <= '9')) {
                break;
            }
        }
        if (i == j) return 0;
        else {
            string t = s.substr(i, j - i);
            i = 0;
            while (t[i] == '0') {
                i++;
            }
            t = t.substr(i);
            if (t.size() > 10 && isPositiveNumber) return 2147483647;
            else if(t.size() > 10 && !isPositiveNumber) return -2147483648;
            else if (isPositiveNumber && t.length()==10 && t > "2147483647") return 2147483647;
            else if (!isPositiveNumber && t.length() == 10 && t >= "2147483648") return -2147483648;
            for (int k = 0;k < t.size();k++) {
                ret += t[k] - '0';
                if(k!=t.length()-1)
                    ret *= 10;
            }
            if (!isPositiveNumber) return -ret;
            return ret;
        }
    }
};
//int main()
//{
//    string s = "-2147483648";
//    cout << Solution().myAtoi(s);
//    return 0;
//}