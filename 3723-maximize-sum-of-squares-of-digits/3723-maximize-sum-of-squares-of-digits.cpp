class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num || sum < 1) return "";
        string result = "";
        for (int i = 0; i < num; ++i) {
            int remaining_digits = num - 1 - i;
            for (int d = 9; d >= 0; --d) {
                if (sum - d >= 0 && sum - d <= 9 * remaining_digits) {
                    result += to_string(d);
                    sum -= d;
                    break;
                }
            }
        }
        return result;
    }
};