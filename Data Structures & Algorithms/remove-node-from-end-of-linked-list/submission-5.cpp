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
        ListNode* temp=head;
       
        int k=0;
        if(!head->next) return nullptr;
        while(temp){
            k++;
            temp=temp->next;
        }
        if(n == k){ return head->next;}
    
        int i =1;
        temp =head;
        while(i<k-n){
            temp = temp->next;
            i++;
        }
        temp->next = temp->next->next;
        return head;
    }
};
