#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = nums[0];
        for (int i = 1;i < nums.size();i++) {
            ret ^= nums[i];
        }
        return ret;
    }
};
//int main()
//{
//    vector<int> nums = { 4,1,2,1,2 };
//    Solution s = Solution();
//    cout<< s.singleNumber(nums);
//	return 0;
//}