class Solution {
    struct Segment {
        long long val;
        long long count;
    };
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long cost = 0;
        int r = n - 1;
        deque<Segment> dq;
        
        for (int l = n - 1; l >= 0; --l) {
            long long curr_val = nums[l];
            long long curr_count = 1;
            while (!dq.empty() && dq.front().val < curr_val) {
                auto [prev_val, prev_count] = dq.front();
                dq.pop_front();
                cost += (curr_val - prev_val) * prev_count;
                curr_count += prev_count;
            }
            
            dq.push_front({curr_val, curr_count});
            while (cost > k) {
                cost -= (dq.back().val - nums[r]);
                dq.back().count--;
                if (dq.back().count == 0) {
                    dq.pop_back();
                }
                --r;
            }
            ans += (r - l + 1);
        }
        return ans;
    }
};