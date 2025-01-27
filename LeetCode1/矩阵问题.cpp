#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int i, j, r,l;
        bool bo = false;
        for (i = 0;i < board.size();i++) {
            for (j = 0;j < board.size();j++) {
                if (board[i][j] == 'R') {
                    bo = true;
                    break;
                }     
            }
            if (bo) break;
        }
        r = i, l = j;//R��r��l��
        int cnt = 0;
        //�ȿ�R���ڵ���һ�д�l��һ����������
        for (j = l-1;j >=0 ;j--) {
            if (board[r][j] == 'p') {
                cnt++;
                break;
            }
            else if (board[r][j] == 'B')
                break;
        }
        //�ٿ�R���ڵ���һ�д�l��һ�����ҵ����
        for (j = l + 1;j < board.size();j++) {
            if (board[r][j] == 'p') {
                cnt++;
                break;
            }
            else if (board[r][j] == 'B')
                break;
        }
        //Ȼ��R���ڵ����д�r��һ�����ϵ����
        for (i = r-1;i >= 0;i--) {
            if (board[i][l] == 'p') {
                cnt++;
                break;
            }
            else if (board[i][l] == 'B')
                break;
        }
        //���R���ڵ����д�r��һ�����µ����
        for (i = r + 1;i<board.size();i++) {
            if (board[i][l] == 'p') {
                cnt++;
                break;
            }
            else if (board[i][l] == 'B')
                break;
        }
        return cnt;
    }
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {//ת�þ���
        vector<vector<int>> v;
        vector<int> t;
        int n = matrix[0].size();
        for (int j = 0;j < n ;j++) {
            for (int i = 0;i < matrix.size();i++) {
                t.push_back(matrix[i][j]);
            }
            v.push_back(t);
            t.clear();
        }
        return v;
    }
};
//int main()
//{
//    vector<vector<int>> v = { {1,2} ,{4,5},{7,8} };
//    vector<vector<int>> ret = Solution().transpose(v);
//    for (auto v1 : ret) {
//        for (int i = 0;i < v1.size();i++) {
//            cout << v1[i] << " ";
//        }cout << endl;
//    }
//	return 0;
//}