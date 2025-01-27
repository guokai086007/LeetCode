#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() <= 1) return;
        vector<int> v;
        int cnt = 0;
        for (auto i : nums) {
            if (i != 0) {
                v.push_back(i);
            }
            else {
                cnt++;
            }
        }
        while (cnt--) {
            v.push_back(0);
        }
        nums.assign(v.begin(), v.end());
    }
};
//int main()
//{
//    vector<int> nums = { 0,1,0,3,12 };
//    Solution().moveZeroes(nums);
//    for (auto i : nums) {
//        cout << i << " ";
//    }
//    return 0;
//}