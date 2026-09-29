class Solution {
private:
    int m, n;
    int memo[100][100][201];
    bool dfs(const vector<vector<char>>& grid, int r, int c, int bal) {
        bal += (grid[r][c] == '(' ? 1 : -1);
        if (bal < 0) return false;
        if (r == m - 1 && c == n - 1) return bal == 0;
        if (memo[r][c][bal] != -1) return memo[r][c][bal];
        bool can_reach = false;
        if (r + 1 < m) can_reach = can_reach || dfs(grid, r + 1, c, bal);
        if (c + 1 < n && !can_reach) can_reach = can_reach || dfs(grid, r, c + 1, bal);
        return memo[r][c][bal] = can_reach;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if ((m + n - 1) % 2 != 0) return false;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;
        fill(&memo[0][0][0], &memo[0][0][0] + sizeof(memo) / sizeof(int), -1);
        return dfs(grid, 0, 0, 0);
    }
};