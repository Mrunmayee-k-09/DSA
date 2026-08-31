#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;Q3

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = INT_MIN;
        int buy = INT_MAX;

        int n = prices.size();

        for(int i = 0; i < n; i++) {

            buy = min(buy, prices[i]);

            int sell = prices[i];

            maxProfit = max(maxProfit, sell - buy);
        }

        return maxProfit;
    }
};