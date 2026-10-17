class Solution {
private:
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        struct Element {
            int digit_sum;
            int val;
            int original_idx;
        };
        vector<Element> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {getDigitSum(nums[i]), nums[i], i};
        }
        sort(arr.begin(), arr.end(), [](const Element& a, const Element& b) {
            if (a.digit_sum != b.digit_sum) {
                return a.digit_sum < b.digit_sum;
            }
            return a.val < b.val;
        });
        vector<bool> visited(n, false);
        int swaps = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i] || arr[i].original_idx == i) {
                continue;
            }
            int cycle_size = 0;
            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = arr[curr].original_idx;
                cycle_size++;
            }
            if (cycle_size > 1) {
                swaps += (cycle_size - 1);
            }
        }
        return swaps;
    }
};