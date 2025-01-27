#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
    public:
        bool isPalindrome(string s) {
            string t = "";
            for (auto c : s) {
                if (c >= '0' && c <= '9') {
                    t += c;
                }
                else if (c >= 'A' && c <= 'Z') {
                    t += (char)(c + 32);
                }
                else if (c >= 'a' && c <= 'z') {
                    t += c;
                }
            }
            string k = t;
            reverse(t.begin(), t.end());
            if (k == t) return true;
            return false;
        }
};
//int main()
//{
//    string t = "";
//    cout<< Solution().isPalindrome(t);
//	return 0;
//}