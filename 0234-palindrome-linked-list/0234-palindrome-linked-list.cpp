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
        if(head==NULL ||head->next==NULL){
            return true ;
        }
       int count =0;
       ListNode *temp=head;
       while(temp){
        temp=temp->next;
        count++;
       }
       count /=2;
       temp=head;
       while(count>1){
        temp=temp->next;
        count--;
       }
       ListNode *curr=temp->next;
       temp->next=NULL;
       temp=head ;
       ListNode *prev=NULL;
       ListNode *temp2 = curr;
       while(curr){
        temp2=temp2->next;
        curr->next=prev;
        prev=curr;
        curr=temp2;
       }
      temp2=prev;
       while(temp){
        if(temp->val != temp2->val){
            return false ;
        }
        temp=temp->next;
        temp2=temp2->next;
       }
       return true;
       
    }
};