#include<iostream>
#include<vector>
using namespace std;
class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			vector<int> result;
			for (int i = 0;i < nums.size();i++) {
				for (int j=i+1;j < nums.size();j++) {
					if (nums[i] + nums[j] == target) {
						result.push_back(i);
						result.push_back(j);
						break;
					}
				}
				if (result.size() > 0) break;
			}
			return result;
		}
};
//int main()
//{
//	Solution S = Solution();
//	vector<int> nums = { 3,2,4 };
//	int target = 6;
//	vector<int> result = S.twoSum(nums, target);
//	cout << result[0] << " , " << result[1] << endl;
//	return 0;
//}