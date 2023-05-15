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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* start_k = head;
        ListNode* end_k = head;
        
        int counter = 1;
        
        while(curr != NULL){
            if(counter<k){
                start_k = start_k->next;
            }
            if(counter>k){
                end_k = end_k->next;
            }
            curr = curr->next;
            counter++;
        }
        
        swap(start_k->val,end_k->val);
        
        return head;
    }
};