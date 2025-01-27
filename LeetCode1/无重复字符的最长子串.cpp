#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    static bool cmp(pair<string, int> a, pair<string, int> b) {
        return a.second > b.second;
    }
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        if (s.length() == 1)return 1;
        map<string, int> mm;
        string t = "";
        int index = 0;
        int i=0, j=0;
        int record = i;
        for (i = 0;i < s.length();i++) {
            t = s.substr(i,j-i+1);
            record = i;
            for (j = j+1;j < s.length();j++) {
                index = t.find(s[j]);
                if (index != -1) {
                    i = record + index;
                    break;
                }
                t.push_back(s[j]);
            }
            mm.insert({ t,t.length() });
        }
        if (mm.empty()) return s.length();
        mm.insert({ t,t.length() });
        vector<pair<string, int>> v(mm.begin(), mm.end());
        sort(v.begin(), v.end(), cmp);
        return v.begin()->second;
    }
};
/*int main()
{
     map<string, int> mm;
    mm.insert({ "aaa", 25 });
    mm.insert({ "bbb", 13 });
    mm.insert({ "ccc", 55 });
    mm.insert({ "ddd", 37 });
    map<string, int>::iterator it;
    for (it = mm.begin();it != mm.end();it++) {
        cout << it->first << " " << it->second;
        if (it != (--mm.end())) cout << "\n";
    }
    for (auto p : mm) {
        cout << p.first << " " << p.second;
        cout << "\n";
    }
    cout << "\n";
    vector<pair<string, int>> v(mm.begin(), mm.end());
    sort(v.begin(), v.end(), Solution::cmp);

    for (auto p : v) {
        cout << p.first << " " << p.second;
        cout << "\n";
    }
    string s="abcabcbb";

    Solution so = Solution();
    int l = so.lengthOfLongestSubstring(s);
    cout << l;
    
	return 0;
}*/