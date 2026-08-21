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
    ListNode* deleteMiddle(ListNode* head) {
        if(head ==NULL ||head->next == NULL){
            return NULL ;
        }
       ListNode *count =head;
        int index =0;
        while(count != NULL){
            count =count->next;
            index++;

        }
        int mid =index/2;
        count =head;
         while(mid !=0 ){
            count =count->next;
            mid--;
         }
        ListNode *temp = count->next;
        if(temp == NULL){
            head ->next= NULL;
            delete count;
        }else{
             count->val = temp->val;
        count->next=temp->next;
        delete temp;
        }
       
        

        return head;
    }
};