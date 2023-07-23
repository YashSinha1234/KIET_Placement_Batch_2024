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
    bool isPalindrome(ListNode* head) {
        if(head -> next ==NULL) return true;
        ListNode *temp = head;
        vector<int> v;
        while (temp){
            v.push_back(temp->val);
            temp = temp->next;
        }
            int s = 0, l = v.size()-1;
            while (s < l)
            {
                if (v[s] != v[l])
                    return false;
                s++;
                l--;
            }
            return true;
    }
};