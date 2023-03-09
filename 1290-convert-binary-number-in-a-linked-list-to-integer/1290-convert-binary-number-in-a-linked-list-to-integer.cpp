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
    int getDecimalValue(ListNode* head) {
        if(head == NULL){
            return 0;
        }
        
        int count = 0;
        ListNode* st = head;
        while(st!=NULL){
            st = st->next;
            count++;
        }
        
        int ans = 0;
        int curr = 1;
        ListNode* check = head;
        
        while(check != NULL){
            if(check->val){
               ans += pow(2,count-curr);
            }
            curr++;
            check = check->next;
        }
        
        return ans;
    }
};