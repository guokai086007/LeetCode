#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        bool isPossibleToSplit(vector<int>& nums) {
            if (nums.size() == 2) return true;
            sort(nums.begin(),nums.end());
            int k = 1, i;
            bool flag = false;
            for (i = 1;i < nums.size();i++) {
                if (nums[i] == nums[i - 1]) {
                    k++;
                }
                else {
                    if (k  > 2)
                        return false;
                    k = 1;
                    flag = true;
                }
            }
            if (k > 2)
                return false;
            if (!flag) return false;
            return true;
        }
};
//int main()
//{
//    vector<int> nums = { 5,9,5,5,6,8,6,1,5,7 };
//    cout << (Solution().isPossibleToSplit(nums)?"true":"false");
//	return 0;
//}