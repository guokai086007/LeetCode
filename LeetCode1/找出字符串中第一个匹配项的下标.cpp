#include<iostream>
using namespace std;
class Solution {
    public:
        int strStr(string haystack, string needle) {
            return haystack.find(needle);
        }
};
//int main()
//{
//    cout<< Solution().strStr("sadbutsad","dbut");
//	return 0;
//}