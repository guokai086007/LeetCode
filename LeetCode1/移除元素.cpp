#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0;i < nums.size();i++) {
            if (nums[i] == val) {
                nums.erase(nums.begin()+i, nums.begin() + i+1);
                cnt++;
                i--;
            }
        }
        return n-cnt;
    }
};
//int main()
//{
//    vector<int> num = { 0,1,2,2,3,0,4,2 };
//    /*num.erase(num.begin()+1,num.begin()+3);
//    for (auto x : num) {
//        cout << x << " ";
//    }*/
//    cout<< Solution().removeElement(num, 2);
//	return 0;
//}