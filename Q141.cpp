#include<iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};



 /*We'll be taking 2 pointers. A slow pointer and a fast pointer. A slow pointer moves 1 position ahead and a fast one moves 2 positions ahead. When the slow and the fast pointer meet, then we can say there exists a loop*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast =head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                return true;
            }
        }
    return false;
    }
};