#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int countStudents(vector<int>& students, vector<int>& sandwiches) {
            int t, n, cnt = 0;//cnt用于判断下面的无限循环是不是该退出了！
            while(1){
                if (students[0] == sandwiches[0]) {
                    students.erase(students.begin(), students.begin()+1);
                    sandwiches.erase(sandwiches.begin(), sandwiches.begin() + 1);
                    if (students.empty()) {
                        return 0;
                    }
                    cnt = 0;
                }
                else {
                    n = students.size();
                    t = students[0];
                    for (int i = 0;i < n - 1;i++) {
                        students[i] = students[i + 1];
                    }
                    students[n - 1] = t;
                    cnt++;
                    if (cnt > n)
                        break;
                }
            }
            return students.size();
        }
};
//int main()
//{
//    vector<int> students = { 1, 1, 1, 0, 0, 1 }, sandwiches = { 1, 0, 0, 0, 1, 1 };
//    cout << Solution().countStudents(students,sandwiches);
//	return 0;
//}