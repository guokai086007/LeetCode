#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
    public:
        vector<string> split(string s,char ch){
            vector<string> ss;
            int index = 0, i = 0, k = 0;
            char c;
            for (auto c : s) {
                k++;
                if (c == ch) {
                    ss.push_back( s.substr(index, k-1) );
                    index += k;
                    k = 0;
                }
            }
            ss.push_back(s.substr(index));
            return ss;
        }
        int convertInteger(string s) {
            int sum = 0;
            for (int i = 0;s[i];i++) {
                sum += (s[i] - '0');
                if(i!=s.size()-1)
                    sum *= 10;
            }
            return sum;
        }
        string convertBinary(int x) {
            if (x < 2) return to_string(x);
            else {
                return convertBinary(x >> 1)+ to_string(x % 2);
            }
        }
        string convertDateToBinary(string date) {
            vector<string> ss = split(date, '-');
            string year = ss[0];
            string month = ss[1];
            string day = ss[2];
            string s = "";
            s += convertBinary(convertInteger(year));
            s += "-";
            s += convertBinary(convertInteger(month));
            s += "-";
            s += convertBinary(convertInteger(day));
            return s;
        }
};

/*int main()
{
    string s = "1900-01-01";
    Solution S = Solution();
    s = S.convertDateToBinary(s);
    cout << s;

    return 0;
}*/
/*
示例 1：

输入： date = "2080-02-29"

输出： "100000100000-10-11101"

解释：

100000100000, 10 和 11101 分别是 2080, 02 和 29 的二进制表示。


*/