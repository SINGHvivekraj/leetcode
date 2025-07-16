// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/?envType=daily-question&envId=2025-07-14
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
        ListNode* temp=head;
        int sz=0;
        while(temp){
            sz++;
            temp=temp->next;
        }
        int placeValue=(1<<(sz-1));
        temp=head;
        int ans=0;
        while(temp){
            int value=temp->val;
            ans+=placeValue*value;
            placeValue/=2;
            temp=temp->next;
        }
        return ans;
    }
};