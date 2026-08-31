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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) return {-1, -1};
        int first_idx = -1;
        int prev_idx = -1;
        int min_dist = INT_MAX;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int idx = 1;
        while (curr->next) {
            ListNode* next = curr->next;
            bool is_max = (curr->val > prev->val && curr->val > next->val);
            bool is_min = (curr->val < prev->val && curr->val < next->val);
            if (is_max || is_min) {
                if (first_idx == -1) first_idx = idx;
                else min_dist = min(min_dist, idx - prev_idx);
                prev_idx = idx;
            }
            prev = curr;
            curr = next;
            idx++;
        }
        if (first_idx == -1 || first_idx == prev_idx) return {-1, -1};
        return {min_dist, prev_idx - first_idx};
    }
};