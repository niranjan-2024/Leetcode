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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int t = 0;
        
        ListNode* temp = head;
        
        while(temp){
            t++;
            temp = temp->next;
        }
        
        int nodeDeleted = t-n;
        
        if(nodeDeleted == 0){
            head = head->next;
            return head;
        }
        
        int p = 0;
        
        temp = head;
        
        while(p < nodeDeleted-1){
            temp = temp->next;
            p++;
        }
        
        temp->next = temp->next->next;
        
        return head;
    }
};