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
    ListNode* sortList(ListNode* head) {
         vector<int> nums;
         ListNode *temp=head;
         while(temp != NULL ){
            nums.push_back(temp->val);
            temp =temp->next;

         }
         sort(nums.begin(),nums.end());
         int n=nums.size();
         ListNode *head1 = NULL;
         ListNode *tail =head1;
         for(int i=0;i<n;i++){
            if(head1 ==NULL ){
                head1 = new ListNode(nums[i]);
                tail =head1;
            }else {
                ListNode *temp = new ListNode(nums[i]);
                tail->next =  temp;
                tail =temp;
            }
         }
         return head1;
    }
};