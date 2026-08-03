class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int next1 = 0, next2 = 0, next3 = 0;
        for (int i = n - 1; i >= 0; --i) {
            int current_take_sum = 0;
            int max_diff = INT_MIN;
            for (int k = 1; k <= 3 && i + k - 1 < n; ++k) {
                current_take_sum += stoneValue[i + k - 1];
                int opp_diff = 0;
                if (k == 1) opp_diff = next1;
                else if (k == 2) opp_diff = next2;
                else if (k == 3) opp_diff = next3;

                max_diff = max(max_diff, current_take_sum - opp_diff);
            }
            next3 = next2;
            next2 = next1;
            next1 = max_diff;
        }
        if (next1 > 0) return "Alice";
        if (next1 < 0) return "Bob";
        return "Tie";
    }
};