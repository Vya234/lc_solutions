class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        const uint64_t BASE1 = 1315423911ULL;
        const uint64_t BASE2 = 2654435761ULL;
        const uint64_t MOD1 = 1000000007ULL;
        const uint64_t MOD2 = 1000000009ULL;

        vector<uint64_t> p1(n + 1, 1), p2(n + 1, 1);
        vector<uint64_t> h1(n + 1, 0), h2(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            uint64_t val = static_cast<uint64_t>(static_cast<long long>(nums[i]) + 1000000005LL);
            p1[i + 1] = (p1[i] * BASE1) % MOD1;
            p2[i + 1] = (p2[i] * BASE2) % MOD2;
            h1[i + 1] = (h1[i] * BASE1 + val) % MOD1;
            h2[i + 1] = (h2[i] * BASE2 + val) % MOD2;
        }
        auto hasUnique = [&](int len) -> bool {
            int m = n - len + 1;
            vector<pair<uint64_t, uint64_t>> hashes;
            hashes.reserve(m);
            for (int i = 0; i < m; ++i) {
                uint64_t x1 = (h1[i + len] + MOD1 - (h1[i] * p1[len]) % MOD1) % MOD1;
                uint64_t x2 = (h2[i + len] + MOD2 - (h2[i] * p2[len]) % MOD2) % MOD2;
                hashes.emplace_back(x1, x2);
            }
            sort(hashes.begin(), hashes.end());
            for (int i = 0; i < m; ++i) {
                bool sameLeft = (i > 0 && hashes[i] == hashes[i - 1]);
                bool sameRight = (i + 1 < m && hashes[i] == hashes[i + 1]);
                if (!sameLeft && !sameRight) return true;
            }
            return false;
        };
        int low = 1, high = n, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (hasUnique(mid)) {
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return ans;
    }
};