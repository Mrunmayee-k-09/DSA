#include <vector>
#include<string>
using namespace std;


class Solution {
public:
    int findNumbers(vector<int>& nums) {
       
        int i;
        int n = nums.size();
        int answer = 0;
        

        for(i=0; i<n; i++) {
            if(to_string(nums[i]).length() % 2 == 0) {
                answer++;
            }
        }
        return answer;
           
    }
};
