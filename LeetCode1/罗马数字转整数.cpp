#include<iostream>
#include<map>
using namespace std;
class Solution {
    public:
        int romanToInt(string s) {
            map<char, int> romanMap;
            romanMap.insert({'I',1});
            romanMap.insert({ 'V',5 });
            romanMap.insert({ 'X',10 });
            romanMap.insert({ 'L',50 });
            romanMap.insert({ 'C',100 });
            romanMap.insert({ 'D',500 });
            romanMap.insert({ 'M',1000 });
            char ch = s[0];
            int sum = 0;
            for (int i = 1;s[i];i++) {
                if (romanMap[s[i]] > romanMap[ch]) {
                    sum -= romanMap[ch];
                }
                else {
                    sum += romanMap[ch];
                }
                ch = s[i];
            }
            sum += romanMap[ch];
            return sum;
        }
};
//int main()
//{
//    Solution s = Solution();
//    cout<< s.romanToInt("MCMXCIV");
//	return 0;
//}