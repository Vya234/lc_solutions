class Solution {
    int minDigitsNeeded(int c2, int c3, int c5, int c7) {
        int min_d = 1e9;
        for (int d8 = 0; d8 <= (c2 + 2) / 3; d8++) {
            for (int d9 = 0; d9 <= (c3 + 1) / 2; d9++) {
                for (int d6 = 0; d6 <= min(c2, c3); d6++) {
                    int r2 = max(0, c2 - 3 * d8 - d6);
                    int r3 = max(0, c3 - 2 * d9 - d6);
                    int d4 = r2 / 2;
                    int r2_rem = r2 % 2;
                    int total = d8 + d9 + d6 + d4 + r2_rem + r3 + c5 + c7;
                    min_d = min(min_d, total);
                }
            }
        }
        return min_d;
    }
    string fillSmallestSuffix(int len, int c2, int c3, int c5, int c7) {
        string res = "";
        for (int pos = 0; pos < len; pos++) {
            int rem_slots = len - 1 - pos;
            for (int d = 1; d <= 9; d++) {
                int nc2 = max(0, c2 - (d == 2 ? 1 : d == 4 ? 2 : d == 6 ? 1 : d == 8 ? 3 : 0));
                int nc3 = max(0, c3 - (d == 3 ? 1 : d == 6 ? 1 : d == 9 ? 2 : 0));
                int nc5 = max(0, c5 - (d == 5 ? 1 : 0));
                int nc7 = max(0, c7 - (d == 7 ? 1 : 0));
                if (minDigitsNeeded(nc2, nc3, nc5, nc7) <= rem_slots) {
                    res += to_string(d);
                    c2 = nc2; c3 = nc3; c5 = nc5; c7 = nc7;
                    break;
                }
            }
        }
        return res;
    }
public:
    string smallestNumber(string num, long long t) {
        long long temp = t;
        int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
        while (temp % 2 == 0) { c2++; temp /= 2; }
        while (temp % 3 == 0) { c3++; temp /= 3; }
        while (temp % 5 == 0) { c5++; temp /= 5; }
        while (temp % 7 == 0) { c7++; temp /= 7; }
        if (temp > 1) return "-1";
        int n = num.length();
        int zero_idx = n;
        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                zero_idx = i;
                break;
            }
        }
        if (zero_idx == n) {
            int r2 = c2, r3 = c3, r5 = c5, r7 = c7;
            for (char ch : num) {
                int d = ch - '0';
                if (d == 2) r2 = max(0, r2 - 1);
                else if (d == 3) r3 = max(0, r3 - 1);
                else if (d == 4) r2 = max(0, r2 - 2);
                else if (d == 5) r5 = max(0, r5 - 1);
                else if (d == 6) { r2 = max(0, r2 - 1); r3 = max(0, r3 - 1); }
                else if (d == 7) r7 = max(0, r7 - 1);
                else if (d == 8) r2 = max(0, r2 - 3);
                else if (d == 9) r3 = max(0, r3 - 2);
            }
            if (r2 == 0 && r3 == 0 && r5 == 0 && r7 == 0) return num;
        }
        vector<int> req2(n + 1, c2), req3(n + 1, c3), req5(n + 1, c5), req7(n + 1, c7);
        for (int i = 0; i < n; i++) {
            if (num[i] == '0') break;
            int d = num[i] - '0';
            req2[i + 1] = max(0, req2[i] - (d == 2 ? 1 : d == 4 ? 2 : d == 6 ? 1 : d == 8 ? 3 : 0));
            req3[i + 1] = max(0, req3[i] - (d == 3 ? 1 : d == 6 ? 1 : d == 9 ? 2 : 0));
            req5[i + 1] = max(0, req5[i] - (d == 5 ? 1 : 0));
            req7[i + 1] = max(0, req7[i] - (d == 7 ? 1 : 0));
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i > zero_idx) continue;
            int start_d = (num[i] - '0') + 1;
            for (int d = start_d; d <= 9; d++) {
                int nr2 = max(0, req2[i] - (d == 2 ? 1 : d == 4 ? 2 : d == 6 ? 1 : d == 8 ? 3 : 0));
                int nr3 = max(0, req3[i] - (d == 3 ? 1 : d == 6 ? 1 : d == 9 ? 2 : 0));
                int nr5 = max(0, req5[i] - (d == 5 ? 1 : 0));
                int nr7 = max(0, req7[i] - (d == 7 ? 1 : 0));
                int rem_len = n - 1 - i;
                if (minDigitsNeeded(nr2, nr3, nr5, nr7) <= rem_len) {
                    string prefix = num.substr(0, i) + to_string(d);
                    string suffix = fillSmallestSuffix(rem_len, nr2, nr3, nr5, nr7);
                    return prefix + suffix;
                }
            }
        }
        int target_len = max(n + 1, minDigitsNeeded(c2, c3, c5, c7));
        return fillSmallestSuffix(target_len, c2, c3, c5, c7);
    }
};