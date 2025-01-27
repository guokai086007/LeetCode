#include<iostream>
using namespace std;
class Solution {
    public:
        int lengthOfLastWord(string s) {
            if (s[s.length() - 1] == ' ') {
                int i, j;
                for (i = s.length() - 1;i >= 0;i--) {
                    if (s[i] != ' ') {
                        for (j = i;j >= 0;j--) {
                            if (s[j] == ' ')
                                return s.substr(j + 1, i-j).length();
                        }
                        if (j < 0)
                            return s.substr(0, i - j).length();
                    }
                }
            }
            else {
                int index = s.rfind(' ');
                if (index == -1) {
                    return s.length();
                }
                else {
                    return s.substr(index + 1).length();
                }
            }
            return 0;
        }
};
//int main()
//{
//    Solution solution = Solution();
//    string s = " abcd ";
//    int len = solution.lengthOfLastWord(s);
//    cout << len;
//    /*string s = "luffy";
//    int index = s.rfind(' ');
//    cout << index;*/
//	return 0;
//}