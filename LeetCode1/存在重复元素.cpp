#include<iostream>
#include<map>
#include<vector>
using namespace std;
class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            map<int, int> map;
            int t;
            for (auto x : nums) {
                if (map.find(x) != map.end()) {//元素本来就存在
                    t = map.find(x)->second;
                    t++;
                    map[x] = t;
                }
                else {
                    map.insert({ x, 1 });
                }
            }
            for (auto pa : map) {
                if (pa.second > 1)
                    return true;
            }
            return false;
        }
};
//int main()
//{
//    vector<int> v = { 1,2,3,4};
//    cout << Solution().containsDuplicate(v);
//    return 0;
//}