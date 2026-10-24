#include<iostream>
using namespace std;
/**
 * Definition for singly-linked list.*/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);  // creates an actual node with value 0.
        dummy->next = head;
        
        //Finding the length of the list 
        int length = 0;
        ListNode *curr = head;

        while(curr != NULL) {
            length++;
            curr = curr->next; }

            int steps = length - n; // From the start how many steps till we reach 'n' to remove it.

            ListNode *prev = dummy;
            for(int i=0; i<steps; i++) {
                prev = prev->next; 
            }
            prev->next = prev->next->next; // The logic of previous->next = target->next

            return dummy->next; //returns the updated head. This is important because the original head might have been removed!  
        

    }
};

/*Before
30 40 50 
After removing 40
30 50
We change the next pointer of node 30 so that it points directly to node 50.

In C++, the key operation is:
previous->next = target->next;*/