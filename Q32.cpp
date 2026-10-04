#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*See, we'll have 3 variables. 'l' - Stores the left part of the parenthesis
'r' - Stores the right part of the parenthesis and 'm' - maximum value
Initially we'll keep all of these = 0. Then as we move through the string, we'll increment 
these values of l and r. 
Jab r = l hoga, then we'll be having those many valid parenthesis
And fir max = max(m, l+r)
if(r=l) {
m = max(m, l+r)}
else if(r>l) Eg. - ()))
{r=0, l=0; }  Becaise, isme ab () inn dono ki ba gayi aur )) ye dono reh gaye.. aage kitne 
bhi (), () add honge fir bhi ye dono aise hi akele rahenge.So, we do l=0, r=0.

Eg. (() Ans should be 2
l = 0,1,2
r = 0,1
m = 0,2 
Ab ye ham gaye the left -> right. Jahape if there was (r>l), we did l=0, r=0.
Now, here in this eg, we'll do right -> left / left <- right.
Jahape if there's l>r, we'll put l=0 and r=0.

So, m = max(0, 1+1) = 2

 */
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() == 0 || s.length() == 1) {
            return 0;
        }   
        int l=0, r=0, m=0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') {
                l++;
            }
            else {
                r++;
            }
            if(l==r) {
                m = max(m, l+r); 
                }
            else if(r>l) {
                r=0; 
                l=0;
            }
        
            }
            r=0;
            l=0;
            for(int i=s.length()-1; i>=0; i--) {
                if(s[i] == '(') {
                    l++;
                }
                else {
                    r++;
                }
                if(l==r) {
                    m = max(m, l+r);
                }
                else if(l>r) {
                    r=0;
                    l=0;
                }
            }
            return m;
        
    }
};