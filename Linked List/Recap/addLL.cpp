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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead; // for Linked-List ques always make this curr ptr to iterate over.
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;

        int leftOver, carryOver = 0;

        while(curr1 and curr2){
            leftOver = (curr1->val + curr2->val + carryOver)%10;
            carryOver = (curr1->val + curr2->val + carryOver)/10;

            ListNode* newNode = new ListNode(leftOver);
            curr->next = newNode;
            curr = newNode;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        while(curr1){
            leftOver = (curr1->val + carryOver)%10;
            carryOver = (curr1->val + carryOver)/10;

            ListNode* newNode = new ListNode(leftOver);
            curr->next = newNode;
            curr = newNode;
            curr1 = curr1->next;
        }

        while(curr2){
            leftOver = (curr2->val + carryOver)%10;
            carryOver = (curr2->val + carryOver)/10;

            ListNode* newNode = new ListNode(leftOver);
            curr->next = newNode;
            curr = newNode;
            curr2 = curr2->next;
        }

        if(carryOver!=0){
            ListNode* newNode = new ListNode(carryOver);
            curr->next = newNode;
            curr = newNode;
        }

        return dummyHead->next;
    }
};
