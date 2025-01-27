#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode* next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
    public:
        int getLength(ListNode* head) {
            ListNode* p = head;
            int i = 0;
            while (p) {
                i++;
                p = p->next;
            }return i;
        }
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            int len = getLength(head);
            int cnt = len - n + 1;
            ListNode* p = head;
            ListNode* q = p;
            while (--cnt) {
                q = p;
                p = p->next;
            }
            q->next = p->next;
            if(p!=head)
                delete p;
            else {
                head = p->next;
                delete p;
            }
            return head;
        }
};
static void insertTail(ListNode* L) {
    int x;
    cin >> x;
    ListNode* p = L;
    while (x != 9999) {
        p->val = x;
        cin >> x;
        if (x != 9999) {
            p->next = new ListNode();
            p = p->next;
        }
    }
    p->next = NULL;
}
static void printList(ListNode* L) {
    ListNode* p = L;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
}
//int main()
//{
//    ListNode* L = new ListNode();
//    insertTail(L);
//    //printList(L);
//    ListNode* head = Solution().removeNthFromEnd(L,2);
//    printList(head);
//    return 0;
//}