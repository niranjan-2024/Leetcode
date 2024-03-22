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
    bool isPalindrome(ListNode* head) {
        queue<int> q;
        stack<int> s;

        ListNode* curr = head;

        while(curr != NULL){
            q.push(curr->val);
            s.push(curr->val);
            curr = curr->next;
        }

        while(!q.empty()){
            if(s.top() != q.front()){
                return false;
            }
            s.pop();
            q.pop();
        }

        return true;
    }
};