#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

/*ans = 0;
for(int i=0; i<n; i++) {
currArea = height[i]*(r-l-1)   right-left-1
ans = max(ans, currArea)
}
return ans

Okay, so we'll go to the left till we get a smaller height than the current bar. And same for the right side.
This is to get a rectangle you know. Smaller value bhetli, ki boundry thambel.
For eg. [2, 1, 5, 6, 2, 3] madhe if we take 5, left la it will stop lagech at 1. And at right, lagech 2 chya adhi. 
So, we get that 5 ani 6 cha rectangle as largest for index 2 which is 5. 

Step 1 - Right smaller nearest (We'll traverse in reverse order in the array till we get to the current element to 
get the smallest of the right side.)
Step 2 - Left Smaller nearest

So, ek stack me ham, hamare current element se jitni bhi smaller values hongi, unko ham iss stack me dal denge.
Larger values ko ham stack se remove karte chale jayenge.
Start the stack with -1 if its empty. 
Index Store karane hai stack me. 
For eg. let's start with 3 which has index 5. 
So, before adding the index of 3, stack is at -1. 
So now, stack index - (Read it backwards from 5 to 0)
0 - Now finally 2. 2 se smaller abhi stack me 1 hai. So, rsi ke index 0 pe jayega 1 ka index, which is 1.
1 - Now 1. 1 se small stack me kuch nahi hai. So, pop everything from stack and put 1 in there. So, -1 at index 1 
of rsi
2 - Now 5. 5 kelie next smaller is 2. Toh ab 6 ko udado stack se. So, 2 ka index goes index 2 of rsi.
3 - Now 6, uska next smaller 2 hai, so hamare stack me available hai. So, 4 at index 3 of rsi.And 6 in stack.
4 - Next ham 2 pe gaye(index 4). Uske right me toh 3 hai. So, for 2, right smaller doesn't exist.So, 3 remove
karke, 2 in the stack. 
5 - (-1)
\
right smaller index    0  1 2 3  4 5 
(rsi)                  1 -1 4 4 -1-1

PSEUDOCODE 
stack<int> s;
right[n] array of size n
for(int i =n-1; i>=0; i--) {
Iska use ham stack se jo badi values hai, unhe nikalne na kaam karenge}
while(s.size() > 0 && ht[s.top()] >= ht[i]) {
s.pop(); }

right[i] = s.empty() ? n : s.top();
s.push(i);

Bro now left smaller !
Ab normal forward loop lagayenge.  [2, 1, 5, 6, 2, 3]
1. Put 2 ka index(0) in the stack. lsi index 0 - (-1) 
2. Stack me abhi 2 hai. Jo 1 se smaller nahi hai. SO, pop 2 and put 1(1) ka index in the stack. 
And lsi index 1 - (-1)
3. Now 5. 5 kelie left me nearest 1 hi smaller hai and it is in the stack already. SO, lsi index 2 - (1). Put 5(2) 
ka index in stack,. 
4. Now 6. 6 kelie 5 nearest smallest hai. So, 6 ke index(3) ko bhi stack me daldo. And lsi index 3 - (2) 
index of 6.
5. Now 2. 2 kelie ab nearest smallest leftside me direct 1 hai. So, we'll pop 6 & 5 and push 2 ka index(4)
 in the stack. 
And lsi index 4 - (1) index of 1. 
6. Now 3. 3 kelie 2 is nearest smallest to its left. So , push 3 ka index(5) in stack and lsi index 5 - (4) index 
of 2.

PSEUDOCODE 
stack<int> s;
left[n] array of size n
for(int i =0; i<n; i++) {
Iska use ham stack se jo badi values hai, unhe nikalne na kaam karenge}
while(s.size() > 0 && ht[s.top()] >= ht[i]) {
s.pop(); }

left[i] = s.empty() ? -1 : s.top();
s.push(i);
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> left(n);
        vector<int> right(n);

        stack<int> s;

        // RSN
        for(int i = n - 1; i >= 0; i--) {

            while(!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            right[i] = s.empty() ? n : s.top();

            s.push(i);   // <-- missing before
        }

        while(!s.empty()) {
            s.pop();
        }

        // LSN
        for(int i = 0; i < n; i++) {

            while(!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            left[i] = s.empty() ? -1 : s.top();

            s.push(i);   // <-- missing before
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int currArea = heights[i] * width;
            ans = max(ans, currArea);
        }

        return ans;
    }
};



