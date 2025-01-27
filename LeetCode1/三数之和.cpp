#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            set<vector<int>> set;
            vector<int> t;
            for (int i = 0;i < nums.size();i++) {
                for (int j = i + 1;j < nums.size();j++) {
                    for (int k = j + 1;k < nums.size();k++) {
                        if (nums[i] + nums[j] + nums[k] == 0) {
                            t.push_back(nums[i]);
                            t.push_back(nums[j]);
                            t.push_back(nums[k]);
                            sort(t.begin(), t.end());
                            set.insert(t);
                        }
                        t.clear();
                    }
                }
            }
            vector<vector<int>> v(set.begin(), set.end());
            return v;
        }
};
//int main()
//{
//    vector<int> nums = { 0,1,1 };
//    Solution s = Solution();
//    vector<vector<int>> v = s.threeSum(nums);
//    for (auto s : v) {
//        for (int i = 0;i < s.size();i++) {
//            cout << s[i] << " ";
//        }cout << endl;
//    }
//	return 0;
//}