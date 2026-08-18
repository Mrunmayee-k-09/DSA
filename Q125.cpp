#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
      int n = s.length();
        int left = 0;
        int right = n-1;

        
    while(left<right)  {  

        while(!isalnum(s[left])) {           // check whether a character is a letter or number
             left++;
        }           
        while(!isalnum(s[right])) {
             right--;
        }

        if(tolower(s[left]) != tolower(s[right])) {
           return false;
           

        }
           left++;
            right--;
    }

    return true;
    }
};