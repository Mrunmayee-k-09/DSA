// APPROACH 1

#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

class MinStack {
public:
    stack<pair<int, int>> s;  // 1st int is the values that we are pushing (like -2, 0, 3) and 2nd int is for the minimum value  that will be stored simultaneously. 
    MinStack() {
        
    }
    ;
    void push(int val) {
        if(s.empty()) {
            s.push({val, val});
        }

        else {
            int minVal = min(val, s.top().second);  // pushed value and the seocnd value from our pair stack is comapred here.
            s.push({val, minVal});
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first; // from our 'pair' stack, this will return the first value of the pair; which we have pushed.
    }
    
    int getMin() {
        return s.top().second;  // from our 'pair' stack, this will return the second value of the pair; which we have already compared.
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

