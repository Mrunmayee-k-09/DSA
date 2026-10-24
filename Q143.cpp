#include<iostream>
using namespace std;

/*
Definition for singly-linked list. */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Now we have to separate the list in two parts 
        ListNode *second = slow->next; //saves the beginning of the second half, node 4. For 1 2 3 4 5. 
        slow->next = nullptr; // disconnects node 3 from node 4.

        //Reverse the second half
        ListNode *prev = nullptr;
        ListNode *curr = second;

        while(curr != nullptr) {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        second = prev;

        // Step 4: Merge the two halves alternately
        ListNode* first = head;

        while (second != nullptr) {
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;

            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext;
        }
    }
};


/*- slow walks 1 metre per second.
- fast walks 2 metres per second.
- Both start at the same point.
Whenever fast covers 2 nodes, slow covers only 1.

Therefore, by the time fast has covered the entire list, slow has covered approximately half of it.*/