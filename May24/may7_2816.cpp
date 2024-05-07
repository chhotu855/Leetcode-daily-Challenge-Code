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
    ListNode* doubleIt(ListNode* head) {
     ListNode*newhead = reverseList(head);
     ListNode*temp = newhead;
     int carry = 0;
     while(temp){
        int value = temp->val * 2+carry;
        temp->val = value%10;
        carry = (value)/10;
        if(temp->next == nullptr && carry != 0){
            temp->next = new ListNode(carry);
            break;
        }
        temp = temp->next;
     } 
     ListNode*curr = reverseList(newhead);
      return curr;
    }
    ListNode* reverseList(ListNode*head){
        ListNode*prev = nullptr;
        ListNode*temp = head;
        while(temp){
            ListNode*curr = temp->next;
            temp->next = prev;
            prev = temp;
            temp = curr;
        }
        return prev;
    }
};
