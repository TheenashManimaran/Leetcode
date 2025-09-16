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
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // reversing the linked from tail to middle
        ListNode* prev = NULL;
        ListNode* cur = slow;
        ListNode* front = slow;

        while(cur != NULL){
            front = front->next;
            cur->next = prev;
            prev = cur;
            cur = front;

        }
        // head2
        cout<<prev->val<<endl;

        ListNode* mover1 = head;
        ListNode* mover2 = prev;

        // while(mover1 != NULL){
        //     cout<<mover1->val<<"-->";
        //     mover1 = mover1->next;
        // }cout<<endl;
        // while(mover2 != NULL){
        //     cout<<mover2->val<<"-->";
        //     mover2 = mover2->next;
        // }cout<<endl;

        // mover1 = head;
        // mover2 = prev;

        while(mover1 != NULL && mover2 != NULL){
            if(mover1->val != mover2->val) return false;
            mover1 = mover1->next;
            mover2 = mover2->next;
        }
        
        return true;
    }
};