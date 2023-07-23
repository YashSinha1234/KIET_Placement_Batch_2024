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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode*> vn;
    ListNode* a = headA;
    while (a != nullptr) {
        vn.insert(a);
        a = a->next;
    }

    ListNode* b = headB;
    while (b != nullptr) {
        if (vn.find(b) != vn.end()) {
            return b;
        }
        b = b->next;
    }

    return nullptr;
    }
};