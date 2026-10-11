#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list. */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0); //creates a helper node with value 0.
        ListNode * tail = &dummy; //makes tail point to that helper node.


        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) { /* list1's value is smaller or equal */
            
            tail->next = list1; // Attach list1's node
            tail = tail->next;      // Move tail forward
            list1 = list1->next;    // Move list1 forward
    }
            else {
                tail->next = list2;     // Attach list2's node
                tail = tail->next;          // Move tail forward
                list2 = list2->next;         // Move list2 forward
    }
}

// Attach the remaining list
tail->next = (list1 != NULL) ? list1 : list2;

 // Return the actual head, skipping dummy
return dummy.next;

    }
};