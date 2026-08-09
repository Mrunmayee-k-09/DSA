#include <vector>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        int i;
        int n = nums.size();
        int answer = 0;
        

        for(i=0; i<n; i++) {
            int digits = 0;
            int temp = nums[i];
        
       

        while(temp != 0) {
        
            temp /= 10;  // temp = temp / 10
            digits++;
            
        }
        

        if(digits % 2 == 0) {
            answer++;

        }
        }
        return answer;
    }
};