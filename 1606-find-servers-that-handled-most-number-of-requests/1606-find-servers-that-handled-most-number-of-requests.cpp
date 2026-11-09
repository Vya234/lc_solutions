class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> count(k, 0);
        set<int> freeServers;
        for (int i = 0; i < k; ++i) {
            freeServers.insert(i);
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busyServers;
        int n = arrival.size();
        for (int i = 0; i < n; ++i) {
            long long arrTime = arrival[i];
            long long duration = load[i];
            while (!busyServers.empty() && busyServers.top().first <= arrTime) {
                freeServers.insert(busyServers.top().second);
                busyServers.pop();
            }
            if (freeServers.empty()) continue;
            int targetServer = i % k;
            auto it = freeServers.lower_bound(targetServer);
            if (it == freeServers.end()) {
                it = freeServers.begin(); 
            }
            int assignedServer = *it;
            count[assignedServer]++;
            busyServers.push({arrTime + duration, assignedServer});
            freeServers.erase(it);
        }
        int maxReq = *max_element(count.begin(), count.end());
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (count[i] == maxReq) {
                result.push_back(i);
            }
        }
        return result;
    }
};