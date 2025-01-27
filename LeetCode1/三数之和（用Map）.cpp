#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            map<int, int> map;
            vector<vector<int>> ret;
            sort(nums.begin(), nums.end());
            int target;
            for (int i = 0;i < nums.size();i++) {
                //map.insert({nums[i],i});
                map[nums[i]] = i;
            }
            for (int i = 0;i < nums.size();i++) {
                if (i != 0 && nums[i] == nums[i - 1]){
                    continue;
                }
                for (int j = i + 1;j < nums.size();j++) {
                    if (j != i+1 && nums[j] == nums[j - 1]) {
                        continue;
                    }
                    target = nums[i] + nums[j];
                    if (map.count(-target) != 0 && map[-target] > j) {
                        ret.push_back({ nums[i],nums[j],-target});
                    }

                }
            }
            return ret;
        }
};/*
int main()
{
    vector<int> nums = { 0,0,0 };
    Solution s = Solution();
    vector<vector<int>> v = s.threeSum(nums);
    for (auto s : v) {
        for (int i = 0;i < s.size();i++) {
            cout << s[i] << " ";
        }cout << endl;
    }
    
	return 0;
}

map<int, int> map;
            for (int i = 0;i < nums.size();i++) {
                map.insert({nums[i],i});
            }
            int sum,index;
            for (int i = 0;i < nums.size();i++) {
                for (int j = i+1;j < nums.size();j++) {
                    sum = nums[i] + nums[j];
                    index = map[-sum];
                    if (index != -1 && index != i && index != j) {
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(-sum);
                        t.push_back(v);
                    }
                    v.clear();
                }
            }
*/