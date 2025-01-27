#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
            vector<int> ret;
            int cnt;
            for (int i = 0;i < queries.size();i++) {
                cnt = 0;
                if (queries[i] > nums.size()) {
                    ret.push_back(-1);
                    continue;
                }
                for (int j = 0;j < nums.size();j++) {
                    if (nums[j] == x) {
                        cnt++;
                        if(cnt == queries[i])
                            ret.push_back(j);
                    }  
                }
                if(cnt<queries[i])
                    ret.push_back(-1);
            }
            return ret;
        }
};
//int main()
//{
//    vector<int> nums = { 1, 2, 3, 2}, queries = { 1, 3, 2, 4 };
//    int x = 2;
//    vector<int> ret = Solution().occurrencesOfElement(nums, queries, x);
//    for (auto x : ret) {
//        cout << x << " ";
//    }
//	return 0;
//}