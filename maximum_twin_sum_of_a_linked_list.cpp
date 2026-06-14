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
    int pairSum(ListNode* head) {
        int length = 0;
        ListNode* temp = head;
        while(temp){
            length++;
            temp = temp->next;
        }
        int half = length/ 2;
        ListNode* head2 = head;
        while(half--){
            head2 = head2->next;
        }
        //reverse this part
        ListNode* prev = NULL;
        while(head2){
            ListNode* front = head2->next;
            head2->next = prev;
            prev = head2;
            head2 = front;
        }
        int maxSum = 0;
        ListNode* newHead = head;
        while(prev){
            int sum = newHead->val + prev->val;
            maxSum = max(maxSum,sum);
            newHead = newHead->next;
            prev = prev->next;
        }
        return maxSum;
    }
};