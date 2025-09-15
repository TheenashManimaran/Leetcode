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
    ListNode* removeElements(ListNode* head, int val) {

        while(head != NULL && head->val == val){
            cout<<head->val<<" ";
            head = head->next;
        }
        if(head == NULL) return NULL;

        ListNode* prev = NULL;
        ListNode* mover = head;

        while(mover != NULL){
            if(mover->val == val){
                prev->next = prev->next->next;
                mover = mover->next;
                continue;
            }
            cout<<mover->val<<" ";
            prev = mover;
            mover = mover->next;
        }
        return head;

    }
};