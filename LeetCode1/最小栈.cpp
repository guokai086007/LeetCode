#include<iostream>
#include<vector>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    int minValue;
    vector<int> s;
    int topp;
    vector<pair<int,int>> record;
    MinStack() {
        this->s = vector<int>(100);
        this->minValue = 2147483647;
        this->topp = -1;
        this->record = vector<pair<int, int>>(100);
    }

    void push(int x) {
        this->s[++this->topp] = x;
        if (this->getMin() >= x) {
            //this->t = this->minValue;
            this->record[this->topp] = {x,x};
            this->minValue = x;
        }
        else {
            this->record[this->topp] = { x,this->getMin() };
        }
    }

    void pop() {
        if (this->s[this->topp] == this->minValue)
            if (this->topp != 0)
                this->minValue = this->record[this->topp - 1].second;
            /*else
                this->minValue = this->s[this->topp];*/
        this->topp--;
        if (topp == -1) {
            this->minValue = 2147483647;
        }
    }

    int top() const {
        return this->s[this->topp];
    }

    int getMin() const {
        return this->minValue;
    }
};
//int main()
//{
//    MinStack minStack = MinStack();
//    minStack.push(2147483646);
//    minStack.push(2147483646);
//    minStack.push(2147483647);
//    cout<<minStack.top()<<" ";
//    minStack.pop();
//    cout << minStack.getMin() << " ";
//    minStack.pop();
//    cout<< minStack.getMin() << " ";
//    minStack.pop();
//    minStack.push(2147483647);
//    cout << minStack.top() << " ";
//    cout << minStack.getMin() << " ";
//    minStack.push(-2147483648);
//    minStack.top();      
//    cout<< minStack.getMin() << " ";
//    minStack.pop();
//    cout << minStack.getMin() << " ";
//    return 0;
//}
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */