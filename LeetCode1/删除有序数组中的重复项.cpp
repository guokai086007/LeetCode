#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int k = 0;
            for (int i = 1;i < nums.size();i++) {
                if (nums[i] != nums[i - 1]) {
                    nums[++k] = nums[i];
                }
            }
            return k + 1;
        }
};
//int main()
//{
//    Solution solution = Solution();
//    vector<int> v = { 0,0,1,1,1,2,2,3,3,4 };
//    int x = solution.removeDuplicates(v);
//    cout << x;
//	return 0;
//}