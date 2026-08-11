#include<vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maximum = *max_element(candies.begin(), candies.end());
        int n = candies.size();
        vector<bool>answer;

        for(int i=0; i<n; i++) {
            if(candies[i] + extraCandies >= maximum) {
                answer.push_back(true);
            }
            else{
                answer.push_back(false);
            }
        }
         return answer;;
    }
};