#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {

/*number → push it into stack
operator → take the top two numbers, perform the operation, and push the result back*/

    stack<int> st;
        for(string token : tokens) {
            if(token != "+" && token != "-" && token != "*" && token != "/") {
               st.push(stoi(token));     // stoi() = string to integer
            }
            else{ 
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();  

                if(token == "+") {
                    st.push(b+a);
                }
                else if(token == "-") {
                    st.push(a-b);
                }   
                else if(token == "*") {
                    st.push(b*a);
                }  
                else {
                    st.push(a/b);
                }
            }
        }
        return st.top();
    }
};