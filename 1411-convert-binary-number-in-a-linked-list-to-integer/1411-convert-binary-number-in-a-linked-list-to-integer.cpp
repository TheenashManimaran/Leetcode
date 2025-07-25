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
    int getDecimalValue(ListNode* head) {
        ListNode* i = head;

        int sum = 0;
        while(i != nullptr){
            sum = (sum * 2) + i->val;
            cout<<sum<<endl;
            i = i->next;
        }
        return sum;
    }
};