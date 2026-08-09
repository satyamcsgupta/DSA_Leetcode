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
        ListNode* rotateRight(ListNode* head, int k) {
       if (head == NULL || head->next == NULL || k == 0){
            return head;
        }
            
            int count =0;
            ListNode *temp=head;
            ListNode *tail=NULL;
            while(temp){
                if(temp->next == NULL){
                    tail=temp;
                }
                temp=temp->next;
                count++;
            }
          if(count < k){
                k=k%count;
            }
            if(count == count - k  || (count - k) == 0 ){
                return head ;
            }
          
            int x=count-k;
            temp=head;
            while(x>1){
            temp=temp->next;
            x--;
            }
            ListNode *st_rot=temp->next;
            temp->next=NULL;
            tail->next=head;
            
            return st_rot;

        }
    };