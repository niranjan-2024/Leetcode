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
        ListNode* tempa = list1;
        int counta = 0;
        
        while(counta<a-1){
            tempa = tempa->next;
            counta++;
        }
        
        ListNode* tempb = list1;
        int countb = 0;
        
        while(countb<=b){
            tempb = tempb->next;
            countb++;
        }
        
        ListNode* end2 = list2;
        
        while(end2->next){
            end2 = end2->next;
        }
        
        tempa->next = list2;
        end2->next = tempb;
        
        return list1;
    }
};