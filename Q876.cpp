#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
};

class Solution
{
public:

    ListNode* middleNode(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

int main()
{
    // Creating the linked list
    ListNode* head = new ListNode{1, NULL};

    head->next = new ListNode{2, NULL};
    head->next->next = new ListNode{3, NULL};
    head->next->next->next = new ListNode{4, NULL};
    head->next->next->next->next = new ListNode{5, NULL};

    // Find middle
    Solution obj;
    ListNode* middle = obj.middleNode(head);

    cout << "Middle node: " << middle->val << endl;

    return 0;
}