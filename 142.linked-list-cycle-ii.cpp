/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            slow = head;
            while(slow != fast){
                slow= slow->next;
                fast= fast->next;
            }
            return slow;
        }
    } 
    return nullptr;
    }
};
// @lc code=end

