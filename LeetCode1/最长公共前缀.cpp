#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string getCommPrefix(string s, string t) {
        int n = (s.length() < t.length() ? s.length() : t.length());
        int i;
        for (i = 0;i < n;i++) {
            if (s[i] != t[i]) break;
        }
        return s.substr(0, i);
    }
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
        string s = strs[0], ss = strs[1], t;
        t = getCommPrefix(s, ss);
        if (t.empty()) return "";
        for (int i = 2;i < strs.size();i++) {
            s = strs[i];
            t = getCommPrefix(s, t);
            //if (ss.length() < t.length()) t = ss;
        }
        return t;
    }
};
//int main() 
//{
//    vector<string> strs = { "" };
//    Solution s = Solution();
//    cout<<s.longestCommonPrefix(strs);
//	return 0;
//}