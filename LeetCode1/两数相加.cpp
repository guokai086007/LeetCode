#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    int getLength(ListNode* L) {
        int i = 0;
        ListNode* p = L;
        while (p) {
            i++;
            p = p->next;
        }
        return i;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode();
        int temp = 0;//ÔÝ´æ½øÎ»
        int m1 = getLength(l1);
        int m2 = getLength(l2);
        ListNode* p,*q,*k = sum;
        if (m1 <= m2) {
            p = l1;
            q = l2;
        }
        else {
            p = l2;
            q = l1;
        }
        while (p) {
            temp += p->val + q->val;
            if (temp >= 10) {
                k->val = temp % 10;
                temp = temp / 10;
            }
            else {
                k->val = temp;
                temp = 0;
            }
            if (q->next) {
                k->next = new ListNode();
                k = k->next;
            }
            p = p->next;
            q = q->next;
        }
        while (q) {
            temp += 0 + q->val;
            if (temp >= 10) {
                k->val = temp % 10;
                temp = temp / 10;
            }
            else {
                k->val = temp;
                temp = 0;
            }
            if (q->next) {
                k->next = new ListNode();
                k = k->next;
            }
            q = q->next;
        }
        if (temp >= 1) {
            k->next = new ListNode();
            k = k->next;
            k->val = temp;
        }
        return sum;
    }
};

void insertTail(ListNode *L){
    int x;
    cin >> x;
    ListNode* p = L;
    while (x != 9999) {
        p->val = x;
        cin >> x;
        if (x == 9999) p->next = NULL;
        else {
            p->next = new ListNode();
            p = p->next;
        }
    }
}
void printList(ListNode* L) {
    ListNode* p = L;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }cout << "\n";
}
/*int main()
{
    ListNode* L1 = new ListNode();
    ListNode* L2 = new ListNode();
    insertTail(L1);
    insertTail(L2);
   
    Solution S = Solution();
    ListNode* sum = S.addTwoNumbers(L1, L2);
    printList(sum);
    return 0;
}*/
