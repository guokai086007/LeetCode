#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string ret = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int x, y, temp = 0;
        for (;i >= 0 && j >= 0;j--, i--) {
            x = a[i] - '0';
            y = b[j] - '0';
            temp = x + y + temp;
            if (temp >= 2) {
                if(temp==2)
                  ret += to_string(0);
                else
                  ret += to_string(1);
                temp = 1;
            }
            else {
                ret += to_string(temp);
                temp = 0;
            }
        }
        while (i>=0) {
            x = a[i] - '0';
            temp = x + temp;
            if (temp >= 2) {
                if (temp == 2)
                    ret += to_string(0);
                else
                    ret += to_string(1);
                temp = 1;
            }
            else {
                ret += to_string(temp);
                temp = 0;
            }
            i--;
        }
        while(j>=0){
            x = b[j] - '0';
            temp = x + temp;
            if (temp >= 2) {
                if (temp == 2)
                    ret += to_string(0);
                else
                    ret += to_string(1);
                temp = 1;
            }
            else {
                ret += to_string(temp);
                temp = 0;
            }
            j--;
        }
        if (temp > 0)
            ret += to_string(temp);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
//int main()
//{
//    Solution s = Solution();
//    cout<< s.addBinary("1111", "1111");
//	return 0;
//}
/*
 while ((--i)>=0) {
                x = a[i] - '0';
                temp = x + temp;
                ret += x;
            }
*/