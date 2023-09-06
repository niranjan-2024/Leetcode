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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k,NULL);
        
        int nodes = 0;
        ListNode* node = head;
        
        while(node != NULL){
            node = node->next;
            nodes++;
        }
        
        int NodesInEvery = nodes/k;
        int remainingNode = nodes>k ? nodes%k : 0 ;
        
        node = head;
        int i = 0;
        
        while(node != NULL){
            ListNode* temp = node;
            int nodesTemp = 1;
            ans[i] = temp;
            
            while(nodesTemp < NodesInEvery && temp->next != NULL ){
                temp = temp->next;
                nodesTemp++;
            }
            
            if(remainingNode > 0 && temp->next != NULL){
                temp = temp->next;
                remainingNode--;
            }
            
            node = temp->next;
            temp->next = NULL;
            
            i++;
        }
        
        return ans;
    }
};