#include<iostream>
#include<map>
#include<vector>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> map;//记录元素值与元素出现的位置
        int t;
        int x;
        for (int i = 0;i < nums.size();i++) {
            x = nums[i];
            if (map.find(x) != map.end()) {//元素本来就存在
                t = map.find(x)->second;
                if (i - t <= k) return true;
                else map[x] = i;
            }
            else {
                map.insert({ x,i });
            }
        }
        return false;
    }
};
//int main()
//{
//    vector<int> v = { 1,0,1,1 };
//    int k = 1;
//    cout << Solution().containsNearbyDuplicate(v,k);
//    return 0;
//}