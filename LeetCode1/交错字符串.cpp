#include<iostream>
#include<stack>
using namespace std;
class Solution {
    public:
        bool ok1(string s1, string s2, string s3) {
            if (s1.length() + s2.length() != s3.length()) return false;
            if (s1 == "" && s2 == "" && s3 == "") return true;
            // int l1 = s1.length(), l2 = s2.length();
            int i, j, cnt1 = 0, cnt2 = 0;
            while (1) {
                cnt1 = 0, cnt2 = 0;
                i = 0;
                while (i < s1.length() && (s1[i] == s3[i])) {
                    cnt1++;
                    i++;
                }
                j = 0;
                while (j < s2.length() && (s2[j] == s3[j])) {
                    cnt2++;
                    j++;
                }
                if (cnt1 == 0 && cnt2 == 0) return false;
                if (cnt1 > cnt2) {
                    s1 = s1.substr(cnt1);
                    s3 = s3.substr(cnt1);
                }
                else {
                    s2 = s2.substr(cnt2);
                    s3 = s3.substr(cnt2);
                }
                if (s3.length() == 0) return true;
            }
            return true;
        }
        bool ok2(string s1, string s2, string s3) {
            if (s1.length() + s2.length() != s3.length()) return false;
            stack<char> stack1, stack2;
            for (int i = s1.length() - 1;i >= 0;i--) {//s1中的所有字符倒着压入stack1这个栈里面
                stack1.push(s1[i]);
            }
            for (int i = s2.length() - 1;i >= 0;i--) {//s2中的所有字符倒着压入stack2这个栈里面
                stack2.push(s2[i]);
            }
            for (int i = 0;i < s3.size();i++) {
                if ((!stack1.empty() && s3[i] == stack1.top()) || (!stack2.empty() && s3[i] == stack2.top())) {
                    if ((!stack1.empty() && s3[i] == stack1.top())) {
                        stack1.pop();
                    }
                    else {
                        stack2.pop();
                    }
                }
                else {
                    return false;
                }
            }
            return true;
        }
        bool ok3(string s1, string s2, string s3) {
            if (s1.length() + s2.length() != s3.length()) return false;
            stack<char> stack1, stack2;
            for (int i = s1.length() - 1;i >= 0;i--) {//s1中的所有字符倒着压入stack1这个栈里面
                stack1.push(s1[i]);
            }
            for (int i = s2.length() - 1;i >= 0;i--) {//s2中的所有字符倒着压入stack2这个栈里面
                stack2.push(s2[i]);
            }
            for (int i = 0;i < s3.size();i++) {
                if ((!stack1.empty() && s3[i] == stack1.top()) || (!stack2.empty() && s3[i] == stack2.top())) {
                    if ((!stack2.empty() && s3[i] == stack2.top())) {
                        stack2.pop();
                    }
                    else {
                        stack1.pop();
                    }
                }
                else {
                    return false;
                }
            }
            return true;
        }
        bool isInterleave(string s1, string s2, string s3) {
            return (ok1(s1, s2, s3) || ok2(s1, s2, s3) || ok3(s1, s2, s3));
        }
};
int main()
{
    cout << Solution().isInterleave("aa", "ab", "aaba");
	return 0;
}
/*
map<char, int> countMap;//记录每个字母的次数
            char ch;
            for (int i = 0;i < s1.size();i++) {
                ch = s1[i];
                if (countMap.find(ch) != countMap.end()) {//map里面本来就有该字符
                    countMap[ch]++;
                }
                else {
                    countMap.insert({ch,1});
                }
            }
            for (int i = 0;i < s2.size();i++) {
                ch = s2[i];
                if (countMap.find(ch) != countMap.end()) {//map里面本来就有该字符
                    countMap[ch]++;
                }
                else {
                    countMap.insert({ ch,1 });
                }
            }
            for (int i = 0;i < s3.size();i++) {
                ch = s3[i];
                if (countMap.find(ch) != countMap.end()) {//map里面本来就有该字符
                    countMap[ch]--;
                    if (countMap[ch] < 0)return false;
                }
                else {
                    return false;
                }
            }
*/
