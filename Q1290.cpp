
#include<iostream>
#include <cmath>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution {
public:
    int getDecimalValue(ListNode* head) {
        

        // Step 1: Find the length
        int n = 0;
        ListNode* ptr = head;

        while(ptr != NULL) {
            n++;
            ptr = ptr->next;
        }

        // Step 2: Start again from the beginning
        ptr = head;

        int power = n - 1;
        int ans = 0;

        // Step 3: Traverse the list
        while(ptr != NULL) {

            if(ptr->val == 1) {
                ans = ans + pow(2, power);
            }

            power--;
            ptr = ptr->next;
        }

        return ans;
    }
};

    