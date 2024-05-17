/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp1 = list1;

        // Find the node just before the a-th node (athNode)
        for (int i = 0; i < a - 1; ++i) {
            temp1 = temp1->next;
        }
        ListNode* athNode = temp1;

        // Continue from athNode to find the b-th node (bthNode)
        for (int i = a - 1; i < b; ++i) {
            temp1 = temp1->next;
        }
        ListNode* bthNode = temp1->next;

        // Reconnect list1
        athNode->next = list2;

        // Traverse list2 to find its last node
        while (list2->next) {
            list2 = list2->next;
        }

        // Connect the last node of list2 to the node after bthNode
        list2->next = bthNode;

        return list1;
    }
};

