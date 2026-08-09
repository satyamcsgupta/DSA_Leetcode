class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       int count =0;
        ListNode *temp = head;
        while (temp ){
            count++;
            temp= temp->next;
        }
        if(count == n  ){
           return head->next;
        }
        int x= count - n;
        temp=head ;
        ListNode * prev=head;
        while(x>1){
            x--;
            temp=temp->next;
            prev=prev->next;

        }
        ListNode *delete_node=prev->next;
        prev=prev->next->next;
        temp->next=prev;
        delete delete_node;
        return head;

    }
};