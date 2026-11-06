class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int qLen = queries.size();
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {return a[1] < b[1];});
        vector<pair<int, int>> sortedQueries(qLen);
        for (int i = 0; i < qLen; ++i) {
            sortedQueries[i] = {queries[i], i};
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        vector<int> result(qLen);
        vector<int> serverCount(n + 1, 0);
        int activeServers = 0;
        int l = 0, r = 0;
        int logLen = logs.size();
        for (const auto& [qTime, originalIdx] : sortedQueries) {
            int winStart = qTime - x;
            int winEnd = qTime;
            while (r < logLen && logs[r][1] <= winEnd) {
                int sId = logs[r][0];
                if (serverCount[sId] == 0) activeServers++;
                serverCount[sId]++;
                r++;
            }
            while (l < logLen && logs[l][1] < winStart) {
                int sId = logs[l][0];
                serverCount[sId]--;
                if (serverCount[sId] == 0) activeServers--;
                l++;
            }
            result[originalIdx] = n - activeServers;
        }
        return result;
    }
};