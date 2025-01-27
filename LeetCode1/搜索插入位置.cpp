#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int i = 0;
            int j = nums.size() - 1;
            int mid;
            while (i <= j) {
                mid = (i + j) / 2;
                if (nums[mid] == target) return mid;
                else if (nums[mid] > target) {
                    j = mid - 1;
                }
                else {
                    i = mid + 1;
                }
            }
            return i;
        }
};
//int main()
//{
//    vector<int> nums = { 1,3,5,6 };
//    int target = 4;
//    Solution s = Solution();
//    cout<< s.searchInsert(nums, target);
//	return 0;
//}