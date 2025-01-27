#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    string addString(string s, string t) {//两数相加
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        int n = (s.length() <= t.length() ? s.length() : t.length());
        string ret = "";
        int temp = 0;
        int i;
        for (i = 0;i < n;i++) {
            temp += (s[i] - '0') + (t[i] - '0');
            if (temp >= 10) {
                ret += to_string(temp - 10);
                temp /= 10;
            }
            else {
                ret += to_string(temp);
                temp = 0;
            }
        }
        while (i < s.length()) {
            temp += (s[i] - '0');
            if (temp >= 10) {
                ret += to_string(temp - 10);
                temp /= 10;
            }
            else {
                ret += to_string(temp);
                temp = 0;
            }
            i++;
        }
        while (i < t.length()) {
            temp += (t[i] - '0');
            if (temp >= 10) {
                ret += to_string(temp - 10);
                temp /= 10;
            }
            else {
                ret += to_string(temp);
                temp = 0;
            }
            i++;
        }
        if (temp != 0)
            ret += '1';
        reverse(ret.begin(), ret.end());
        return ret;
    }
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int temp = 0;//记录中间的进位
        vector<string> v;
        string t;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0;i < num2.size();i++) {
            t = "";
            temp = 0;
            for (int j = 0;j < num1.size();j++) {
                temp += (num2[i] - '0')* (num1[j] - '0');
                if (temp >= 10) {
                    t += to_string(temp % 10);
                    temp /= 10;
                }
                else {
                    t += to_string(temp);
                    temp = 0;
                }
            }
            if (temp != 0)
                t += to_string(temp);
            reverse(t.begin(), t.end());
            v.push_back(t);
        }
        string s = v[0];
        string c;
        for (int i = 1;i < v.size();i++) {
            t = v[i];
            c = s.substr(s.length() - i);
            s = addString(s.substr(0, s.size() - i), t);
            s += c;
        }
        return s;
    }
};
//int main()
//{
//    string s = Solution().multiply("9","99");
//    cout << s << endl;
//	return 0;
//}