#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> arr1(26);
        vector<int> arr2(26);

        for(int i=0; i<s.length(); i++) {
            arr1[s[i]-'a']++;
        }

        for(int i=0; i<t.length(); i++) {
            arr2[t[i]-'a']++;
        }

        return arr1 == arr2;

    }
};

/* There's one more approach 
vector<int> count(26);

for(int i = 0; i < s.length(); i++) {
    count[s[i] - 'a']++;
}

for(int i = 0; i < t.length(); i++) {
    count[t[i] - 'a']--;
}

for(int i = 0; i < 26; i++) {
    if(count[i] != 0)
        return false;
}

return true;

The idea is:

s → +1
t → -1

If they're anagrams, everything cancels to zero.

But both are O(n) time and O(1) space.
*/