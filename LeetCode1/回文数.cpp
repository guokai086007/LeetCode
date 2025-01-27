#include<iostream>
#include<string>
using namespace std;
class Solution {
    public:
        bool isPalindrome(int x) {
            string s = to_string(x);
            string t = s;
            reverse(t.begin(), t.end());
            if (s.compare(t) == 0)return true;
            return false;
        }
};
/*
int main()
{
    int ss = 1221;
    Solution s = Solution();
    cout<<(s.isPalindrome(ss)?"true":"false");
    //string t = "123";
   // reverse(t.begin(),t.end());
   // cout << t;
    return 0;
}*/