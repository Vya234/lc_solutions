class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        long long low = 1;
        long long high = 1LL * *min_element(coins.begin(), coins.end()) * k;
        long long ans = high;
        auto count = [&](long long M) -> long long {
            long long total = 0;
            for (int mask = 1; mask < (1 << n); ++mask) {
                long long current_lcm = 1;
                int bits_set = 0;
                bool overflow = false;
                for (int i = 0; i < n; ++i) {
                    if ((mask >> i) & 1) {
                        bits_set++;
                        long long g = gcd(current_lcm, (long long)coins[i]);
                        current_lcm = (current_lcm / g) * coins[i];
                        if (current_lcm > M) {
                            overflow = true;
                            break;
                        }
                    }
                }
                if (overflow) continue;
                if (bits_set % 2 == 1) total += M / current_lcm;
                else total -= M / current_lcm;
            }
            return total;
        };
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (count(mid) >= k) {
                ans = mid;
                high = mid - 1;
            } 
            else low = mid + 1;
        }
        return ans;
    }
};