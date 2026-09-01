class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int start_r = -1, start_c = -1;
        vector<pair<int, int>> litters;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (classroom[r][c] == 'S') {
                    start_r = r;
                    start_c = c;
                } else if (classroom[r][c] == 'L') litters.push_back({r, c});
            }
        }
        int K = litters.size();
        int target_mask = (1 << K) - 1;
        vector<vector<int>> litter_id(m, vector<int>(n, -1));
        for (int i = 0; i < K; ++i) litter_id[litters[i].first][litters[i].second] = i;
        vector<vector<vector<int>>> max_energy(m, vector<vector<int>>(n, vector<int>(1 << K, -1)));
        queue<tuple<int, int, int, int, int>> q;
        q.push({start_r, start_c, 0, energy, 0});
        max_energy[start_r][start_c][0] = energy;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while (!q.empty()) {
            auto [r, c, mask, cur_energy, moves] = q.front();
            q.pop();
            if (mask == target_mask) return moves;
            if (cur_energy == 0) continue; 
            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && classroom[nr][nc] != 'X') {
                    int next_energy = cur_energy - 1;
                    int next_mask = mask;
                    char cell = classroom[nr][nc];
                    if (cell == 'R') next_energy = energy;
                    else if (cell == 'L') {
                        int id = litter_id[nr][nc];
                        next_mask |= (1 << id);
                    }
                    if (next_energy > max_energy[nr][nc][next_mask]) {
                        max_energy[nr][nc][next_mask] = next_energy;
                        q.push({nr, nc, next_mask, next_energy, moves + 1});
                    }
                }
            }
        }
        return -1;
    }
};