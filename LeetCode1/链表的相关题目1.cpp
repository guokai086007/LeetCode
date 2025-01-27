#include<iostream>
#include<map>
#include<stack>
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
        ListNode* rotateRight(ListNode* head, int k) {//向右旋转链表每个元素k次
            if (k == 0) return head;
            int len = getLength(head);
            if (len <= 1) return head;
            int t = k % len;
            if (t == 0) return head;
            else {
                int m = len - t;
                ListNode* p = head;
                while (--m) {
                    p = p->next;
                }
                ListNode* q = head;
                int n = len;
                while (--n) {
                    q = q->next;
                }
                ListNode* r = p->next;
                p->next = NULL;
                q->next = head;
                head = r;
                return head;
            }
        }
        ListNode* removeDuplicateNodes(ListNode* head) {//删除无序链表重复元素
            map<int, int> map;
            ListNode* p = head,*q = p;
            int t;
            while (p) {
                if (map.find(p->val) != map.end()) {//map里面本来就有该元素
                    t = map[p->val];
                    map[p->val] = ++t;
                    q->next = p->next;
                    delete p;
                    p = q->next;
                }
                else {
                    map.insert({p->val,1});
                    q = p;
                    p = p->next;
                }
            }
            return head;
        }
        ListNode* deleteDuplicates(ListNode* head) {//删除有序链表重复元素
            ListNode* p = head, * q = p;
            while (q) {
                if (p->val != q->val) {
                    p->next = q;
                    p = q;
                }
                else {
                    q = q->next;
                }
            }
            if(p!=NULL)
                p->next = NULL;
            return head;
        }
        ListNode* removeElements(ListNode* head, int val) {//删除链表中值为val的元素
            ListNode* p = head,*q = p;
            while (p) {
                if (p->val == val) {
                    if (p == q) {
                        p = p->next;
                        q->next = NULL;
                        head = p;
                        q = p;
                    }
                    else {
                        q->next = p->next;
                        delete p;
                        p = q->next;
                    }
                }
                else {
                    q = p;
                    p = p->next;
                }
            }
            return head;
        }
        bool isPalindrome(ListNode* head) {//判断是否是回文链表
            stack<int> s;
            ListNode* p = head;
            while (p) {
                s.push(p->val);
                p = p->next;
            }
            p = head;
            while (p) {
                if (p->val != s.top()) return false;
                p = p->next;
                s.pop();
            }return true;
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
//    ListNode* head = Solution().removeElements(L,6);
//    printList(head);
//    return 0;
//}