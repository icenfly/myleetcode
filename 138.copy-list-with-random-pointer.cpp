/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* node = head;
        while(node){
            Node* temp = node->next;
            node->next = new Node(node->val);
            node->next->next = temp;
            node = temp;
        }
        node = head;
        while(node){
            if(node->random){
                node->next->random = node->random->next;
            }
            node = node->next->next;
        }
        Node* ans = new Node(0);
        node = ans;
        while(head){
            node->next = head->next;
            node = node ->next;
            head->next = head->next->next;
            head = head->next;
        }
        return ans->next;
    }
};
// @lc code=end

