// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         ListNode* ptr1=list1;
//         ListNode* ptr2=list2;
//         ListNode* head=new ListNode();
//         ListNode* ptr3=head;
//         while(ptr1!=NULL && ptr2!=NULL){
//             if(ptr1==NULL && ptr2!=NULL){
//                 ptr3->next = new ListNode(ptr2->val);
//                 ptr3=ptr3->next;
//                 ptr2=ptr2->next;
//                 continue;
//             }
//                if(ptr2==NULL && ptr1!=NULL){
//                 ptr3->next = new ListNode(ptr1->val);
//                 ptr3=ptr3->next;
//                 ptr1=ptr1->next;
//                 continue;
//             }
//             if(ptr1==NULL && ptr2==NULL){
//                 break;
//             }



//             if (ptr1->val<ptr2->val){
//                 ptr3->next = new ListNode(ptr1->val);
//                 ptr3=ptr3->next;
//                 ptr1=ptr1->next;
//                 continue;
//             }
//             if (ptr2->val<ptr1->val){
//                 ptr3->next = new ListNode(ptr2->val);
//                 ptr3=ptr3->next;
//                 ptr2=ptr2->next;
//                 continue;
//             }
//             if (ptr2->val==ptr1->val){
//                 ptr3->next = new ListNode(ptr2->val);
//                 ptr3=ptr3->next;
//                 ptr3->next = new ListNode(ptr1->val);
//                 ptr3=ptr3->next;
//                 ptr2=ptr2->next;
//                 ptr1=ptr1->next;
//                 continue;
//             }
//         }
//         ListNode* mergedList=head->next;
//         delete head;
//         return mergedList;
        
//     }
// };
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(); // dummy node to simplify code
        ListNode* current = dummy; // pointer to current node in merged list

        // Traverse both lists until one of them becomes nullptr
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        // Attach the remaining nodes of the non-empty list
        if (l1 != nullptr) {
            current->next = l1;
        } else {
            current->next = l2;
        }

        ListNode* mergedList = dummy->next; // head of the merged list
        delete dummy; // delete the dummy node

        return mergedList;
    }
};
