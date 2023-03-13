/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;
        Node* temp;
        Node* rest;
        
        while(curr){
            if(curr->child){
                
                temp = curr->next;
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = NULL;
                
                rest = curr->next;
                while(rest->next){
                    rest = rest->next;
                }
                rest->next = temp;
                if(rest->next){
                    rest->next->prev = rest;
                }
            }
            curr = curr->next;
        }
        
        return head;
    }
};