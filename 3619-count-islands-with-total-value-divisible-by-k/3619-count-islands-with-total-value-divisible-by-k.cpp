class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        auto dfs = [&](auto& self, int r, int c) -> long long {
            long long sum = grid[r][c];
            grid[r][c] = 0; 
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                    sum += self(self, nr, nc);
                }
            }
            return sum;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    long long totalValue = dfs(dfs, i, j);
                    if (totalValue % k == 0) count++;
                }
            }
        }
        return count;
    }
};