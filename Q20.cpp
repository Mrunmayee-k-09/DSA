#include<stack>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s) {

            // Opening bracket → push
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            }

            // Closing bracket
            else {
                // Nothing to match
                if(st.empty())
                    return false;

                // Wrong opening bracket
                if(c == ')' && st.top() != '(')
                    return false;

                if(c == ']' && st.top() != '[')
                    return false;

                if(c == '}' && st.top() != '{')
                    return false;

                // Correct match → remove opening bracket
                st.pop();
            }
        }

        return st.empty();  //Return TRUE if the stack is empty. Otherwise return FALSE.
    }
};


// KEY POINTS: 
/*
1. st.top() means the opening bracket we last pushed

Suppose:

s = "({["

As we go:

(  → push
{  → push
[  → push

Stack conceptually looks like:

       TOP
        ↓
      [ 
      {
      (

So:

st.top()

gives:

[*/