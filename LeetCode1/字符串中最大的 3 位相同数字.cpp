#include<iostream>
#include<set>
using namespace std;
class Solution {
    public:
        string largestGoodInteger(string num) {
            set<string> ss;
            int cnt = 1;
            int i;
            for (i = 1;num[i];i++) {
                if (num[i] == num[i - 1] && cnt<3)
                    cnt++;
                else if (num[i] == num[i - 1] && cnt == 3) {
                    ss.insert(num.substr(i - 3, 3));
                    cnt = 1;
                }
                else {
                    if (cnt == 3) {
                        ss.insert(num.substr(i - 3, 3));
                    }
                    cnt = 1;
                }
            }
            if(cnt==3)
                ss.insert(num.substr(i - 3, 3));
            if (ss.size() == 0) return "";
            string max = "000";
            for (auto s : ss) {
                if (s > max) {
                    max = s;
                }
            }
            return max;
        }
};
//int main()
//{
//    Solution solution = Solution();
//    cout<< solution.largestGoodInteger("42352338");
//	return 0;
//}