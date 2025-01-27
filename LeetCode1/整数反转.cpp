#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
    public:
        int convertInteger(string s) {
            int sum = 0;
            for (int i = 0;s[i];i++) {
                sum += (s[i] - '0');
                if (i != s.size() - 1)
                    sum *= 10;
            }
            return sum;
        }
        int reverse(int x) {
            if (x == -2147483648) return 0;
            string s;
            if (x < 0) { 
                int y = -x;
                s = to_string(y);
                if (s.length() > 10) return 0;
            }
            else {
                s = to_string(x);
                if (s.length() > 10) return 0;
            }
            std::reverse(s.begin(),s.end());
            if (x>0 && s.length()==10 && s > "2147483647") {
                return 0;
            }
            else if (x<0 && s.length() == 10 && s >= "2147483648")
                return 0;
            int k = convertInteger(s);
            return x >= 0 ? k : -k;
        }
};
//int main()
//{
//    cout << Solution().reverse(1463847412);
//    return 0;
//}