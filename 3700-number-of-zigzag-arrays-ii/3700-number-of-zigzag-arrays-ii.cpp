class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        if (n == 1) {
            return r - l + 1;
        }
        
        long long MOD = 1e9 + 7;
        int m = r - l + 1;
        int size = 2 * m;
        auto multiply = [&](const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
            vector<vector<long long>> C(size, vector<long long>(size, 0));
            for (int i = 0; i < size; ++i) {
                for (int k = 0; k < size; ++k) {
                    if (A[i][k] == 0) continue; 
                    for (int j = 0; j < size; ++j) {
                        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                    }
                }
            }
            return C;
        };
        auto power = [&](vector<vector<long long>> base, int exp) {
            vector<vector<long long>> res(size, vector<long long>(size, 0));
            for (int i = 0; i < size; ++i) {
                res[i][i] = 1; 
            }       
            while (exp > 0) {
                if (exp % 2 == 1) {
                    res = multiply(res, base);
                }
                base = multiply(base, base);
                exp /= 2;
            }
            return res;
        };
        vector<vector<long long>> T(size, vector<long long>(size, 0));       
        for (int x = 0; x < m; ++x) {
            int up_state = x + m;
            int down_state = x;
            for (int y = 0; y < x; ++y) {
                T[y + m][down_state] = 1;
            }
            for (int y = x + 1; y < m; ++y) {
                T[y][up_state] = 1;
            }
        }
        vector<vector<long long>> T_final = power(T, n - 1);
        long long ans = 0;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                ans = (ans + T_final[i][j]) % MOD;
            }
        }     
        return ans;
    }
};