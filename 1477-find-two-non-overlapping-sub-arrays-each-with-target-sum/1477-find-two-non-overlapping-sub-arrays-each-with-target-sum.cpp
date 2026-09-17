class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n, INT_MAX / 2);
        int left = 0, current_sum = 0;
        int ans = INT_MAX / 2;
        int best_so_far = INT_MAX / 2;
        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];
            while (current_sum > target && left <= right) {
                current_sum -= arr[left];
                left++;
            }
            if (current_sum == target) {
                int current_len = right - left + 1;
                if (left > 0 && min_len[left - 1] < INT_MAX / 2) {
                    ans = min(ans, current_len + min_len[left - 1]);
                }
                best_so_far = min(best_so_far, current_len);
            }
            min_len[right] = (right > 0) ? min(min_len[right - 1], best_so_far) : best_so_far;
        }
        return ans >= INT_MAX / 2 ? -1 : ans;
    }
};