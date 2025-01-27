#include<iostream>
#include<map>
#include<vector>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> map;//��¼Ԫ��ֵ��Ԫ�س��ֵ�λ��
        int t;
        int x;
        for (int i = 0;i < nums.size();i++) {
            x = nums[i];
            if (map.find(x) != map.end()) {//Ԫ�ر����ʹ���
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