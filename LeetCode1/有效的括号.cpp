#include<iostream>
#include<stack>
using namespace std;
class Solution {
    public:
        bool isValid(string s) {
            stack<char> st;
            for (int i = 0;s[i];i++) {
                if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
                    st.push(s[i]);
                }
                else {
                    if (!st.empty()) {
                        if (s[i] == ')' && st.top() != '(') {
                            return false;
                        }
                        else if (s[i] == ']' && st.top() != '[') {
                            return false;
                        }
                        else if (s[i] == '}' && st.top() != '{') {
                            return false;
                        }
                        else {
                            st.pop();
                        }
                    } 
                    else return false;
                }
            }
            if (st.size() > 0) return false;
            return true;
        }
};
//int main()
//{
//    cout << Solution().isValid("{ [");
//	return 0;
//}