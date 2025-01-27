#include<iostream>
using namespace std;
class Solution {
    public:
        int countKeyChanges(string s) {
            int cnt = 0;
            for (int i = 0;i < s.size();i++) {
                if (s[i] >= 'A' && s[i] <= 'Z') {
                    s[i] = (char)((int)(s[i]) + 32);
                }
            }
            for (int i = 1;i < s.size();i++) {
                if (s[i] != s[i - 1])
                    cnt++;
            }
            return cnt;
        }
};
//int main()
//{
//    /*Solution S = Solution();
//    cout<< S.countKeyChanges("aAaAaA");*/
//    char a = ('A' + 32);
//    cout<< a;
//	return 0;
//}