// APPROACH 2
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

/* Hamare stack me abhi jo bhi minimum value chal rahi hai, for eg. -2; and after that jab -3
push karne ki baari aayegi, we won't be pushing -3 directly. Because if we create a global 
variable like minVal and ham usme hamesha new jo bhi minimum value hogi usko store karenge. 
But jar ata minVal = -2 asel and then later ti -3 zali, and then jar mi -3 la pop kela tar we 
want ki apli minVal parat -2 var revert back vhavi. 
So, for that apan ek formula vapru. 
See, jar already tuzi minVal = -2 stored ahe and you wanna push val = -3, you won't direcrly push it.
You'll do val' = 2*val(New wali) - minVal
               = 2*(-3) -(-2) = -4. 
You'll push -4 ! So, minVal = val (-4).

Ata revert back karayla, we will reverse this same formula. 
(OLD) minVal = 2* (NEW) minVal - val'
-2 = 2*(-3) - (-4) . Satisfied. 
*/
// S.C. = O(2*n)
class MinStack {
public:
    stack<long long int> s;
    long long int minVal;
    MinStack() {
        
    }
    ;
    void push(int val) {
        if(s.empty()) {
            s.push(val) ;
            minVal = val;
        }

        else {
            if(val < minVal) {
                s.push((long long)2*val - minVal);
                minVal = val;
            }
            else{
                s.push(val);
            }
        }
}
    
    void pop() {
        if(s.top() < minVal) {
            minVal = 2*minVal - s.top();

        }
        s.pop();
    }
    
    int top() {
        if(s.top() < minVal) {
            return minVal;
        }
        else{
            return s.top();
        }
    }
    
    int getMin() {
          return minVal;
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