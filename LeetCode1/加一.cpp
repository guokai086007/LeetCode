#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = 1,n = digits.size();
        int num = 1;
        while (i <= n) {
            num = digits[n - i] + num;
            if (num < 10) {
                digits[n - i] = num;
                return digits;
            }
            else {
                digits[n - i] = num-10;
                num /= 10;
                
            }
            i++;
        }
        if (num > 0) {
            vector<int> v;
            v.push_back(num);
            for (int i = 0;i < digits.size();i++) {
                v.push_back(digits[i]);
            }
            return v;
        }
        return digits;
    }
};
//int main()
//{
//    vector<int> digits = { 9 ,8 ,7};
//    Solution solution = Solution();
//    vector<int> v = solution.plusOne(digits);
//    for (auto i : v) {
//        cout << i;
//    }
//	return 0;
//}