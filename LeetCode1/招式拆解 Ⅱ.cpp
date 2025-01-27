#include<iostream>
#include<map>
using namespace std;
class Solution {
    public:
        char dismantlingAction(string arr) {
            map<char, pair<int,int>> map;//��¼�ַ����е��ַ��Լ���Ӧ���ִ�����λ��
            int t;
            char c;
            for (int i = 0;i < arr.size();i++) {
                c = arr[i];
                if (map.find(c)!=map.end()) {
                    t = map[c].first;
                    t++;
                    map[c].first = t;
                }
                else {
                    map.insert({ c,{1,i} });
                }
            }
            c = ' ';
            int min = 50001;
            for (auto p : map) {
                if (p.second.first == 1) {
                    if (p.second.second < min) {
                        min = p.second.second;
                        c = p.first;
                    }
                }    
            }
            if (c != ' ') return c;
            return ' ';
        }
};
//int main()
//{
//    cout << Solution().dismantlingAction("itwqbtcdprfsuprkrjkausiterybzncbmdvkgljxuekizvaivszowqtmrttiihervpncztuoljftlxybpgwnjb");
//	return 0;
//}