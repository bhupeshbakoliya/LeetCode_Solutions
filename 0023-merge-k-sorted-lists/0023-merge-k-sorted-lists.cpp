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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* merged_list=new ListNode(0);
        ListNode* temp=merged_list;
        priority_queue<int,vector<int>,greater<int>> pq;
        int size=lists.size();
        for (int i=0;i<size;i++){
            ListNode* templist=lists[i];
            while(templist){
                pq.push(templist->val);
                templist=templist->next;
            }
            }
        while(!pq.empty()){
            temp->next=new ListNode(pq.top());
            pq.pop();
            temp=temp->next;
            
            
        }
        return merged_list->next;
        
        }
    
};