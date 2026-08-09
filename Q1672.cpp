#include<vector>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int i, j, n;
        n = accounts.size();
        int maxWealth = 0;
       

        for(i=0; i<n; i++) {
            int sum = 0;
            for(j=0; j<accounts[i].size(); j++) {
                    sum += accounts[i][j];

                    if(sum > maxWealth) {
                        maxWealth = sum;
                    }
            }
        }

        return maxWealth;
        
    }
};
