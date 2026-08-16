#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;

        int n = strs.size();
        for(int i=0; i<n; i++) {
            string key = strs[i];
            sort(key.begin(), key.end()); // Sort mean here we are putting the string in alphabetical order.
            mp[key].push_back(strs[i]);
        }

        vector<vector<string>>ans;
        for(auto &pair : mp) {
            ans.push_back(pair.second);
        }

        return ans;
    }
};

/*pair.first  → key
pair.second → value
*/