#include<iostream>
using namespace std;
class Solution {
    public:
        string clearDigits(string s) {
            for (int i = 0;i < s.size();i++) {
                if (s[i] >= '0' && s[i] <= '9') {
                    if (i - 1 >= 0 && !(s[i-1] >= '0' && s[i-1] <= '9')) {
                        s.erase(i-1,2);
                    }
                    else {
                        s.erase(i, 1);
                    }
                    i = 0;
                }
            }
            return s;
        }
};
//int main()
//{
//    cout << Solution().clearDigits("abc");
//    return 0;
//}