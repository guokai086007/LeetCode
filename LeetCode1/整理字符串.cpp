#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isEqualChar(char a, char b) {
        if ((a >= 'a' && a <= 'z') && (b>='A' && b<='Z')) {
            b = (char)(b + 32);
            if (a == b) return true;
        }
        else if ((a >= 'A' && a <= 'Z') && (b >= 'a' && b <= 'z')) {
            a = (char)(a + 32);
            if (a == b) return true;
        }
        return false;
    }
    string makeGood(string s) {
        if (s.length() <= 1) return s;
        string t = "";
        bool b = false;
        while (1) {
            b = false;
            t = "";
            for (int i = 0;i < s.size();i++) {
                if (isEqualChar(s[i], s[i + 1])) {
                    i = i + 1;
                    b = true;
                }
                else {
                    t += s[i];
                }
            }
            if (!b) {
                return t;
            }
            else {
                s = t;
            }
        }
    }
};
//int main()
//{
//    /*string s = "leEeetcode";
//    cout << Solution().makeGood(s);*/
//    int n = 45;
//    vector<int> v;
//    v.push_back(1);
//    v.push_back(2);
//    int i = 2, t = 0;
//    while (i < n) {
//        t = v[i - 1] + v[i - 2];
//        v.push_back(t);
//        i++;
//    }
//    cout << v[n - 1];
//	return 0;
//}