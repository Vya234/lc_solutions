class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> values(n, 1); 
        int min_price = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            min_price = min(min_price, items[i][1]);
        for (int j = 0; j < n; j++) {
            if (i != j && items[j][0] % items[i][0] == 0) {
                    values[i]++;
                }
            }
        }
       
        vector<int> dp(budget + 1, -1);
        dp[0] = 0; 
        
        for (int i = 0; i < n; i++) {
            int cost = items[i][1];
            int val = values[i];
          
            for (int w = budget; w >= cost; w--) {
                if (dp[w - cost] != -1) {
                    dp[w] = max(dp[w], dp[w - cost] + val);
                }
            }
        }
        int max_total_items = 0;
        
        for (int w = 0; w <= budget; w++) {
            if (dp[w] != -1) { 
                int remaining_budget = budget - w;
                int extra_items = remaining_budget / min_price; 
                max_total_items = max(max_total_items, dp[w] + extra_items);
            }
        }
        
        return max_total_items;
    }
};