#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        bool isArraySpecial(vector<int>& nums) {
            bool b = true;
            for (int i = 1;i < nums.size();i++) {
                if (((nums[i] % 2) ^ (nums[i - 1] % 2)) == 0) {
                    b = false;
                    break;
                }
            }
            return b;
        }
};
//int main()
//{
//    vector<int> num = { 2,1,4 };
//    cout << Solution().isArraySpecial(num);
//    return 0;
//}