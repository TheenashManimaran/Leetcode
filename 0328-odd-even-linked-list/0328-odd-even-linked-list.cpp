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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;  
        ListNode* mover = head;

        ListNode* dummyhead = new ListNode(-1);
        ListNode* cur = dummyhead;

        while(mover != NULL){
            ListNode* newNode = new ListNode(mover->val);
            cur->next = newNode;
            cur = newNode;
            
            if(mover->next == NULL) break;
            mover = mover->next->next;
        }

        mover = head->next;
        
        while(mover != NULL){
            ListNode* newNode = new ListNode(mover->val);
            cur->next = newNode;
            cur = newNode;

            if(mover->next == NULL) break;
            mover = mover->next->next;
        }

        return dummyhead->next;


    }
};