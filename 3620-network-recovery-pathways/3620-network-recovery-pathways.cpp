class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n,0);
        int hi = 0;
        for(auto &e: edges){
            adj[e[0]].push_back({e[1], e[2]});
            indegree[e[1]]++;
            hi = max(hi, e[2]);
        }
        auto check = [&](int mid)->bool{
            vector<long long> dist(n, LLONG_MAX);
            queue<int> q;
            vector<int> indeg = indegree;
            for(int i=0;i<n;i++)
                if(indeg[i]==0)
                    q.push(i);
            dist[0]=0;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                if(dist[u]!=LLONG_MAX){
                    for(auto &[v,w]:adj[u]){
                        if(w<mid) continue;
                        if(v!=n-1 && !online[v]) continue;
                        dist[v]=min(dist[v], dist[u]+(long long)w);
                    }
                }
                for(auto &[v,w]:adj[u]){
                    indeg[v]--;
                    if(indeg[v]==0)
                        q.push(v);
                }
            }
            return dist[n-1]<=k;
        };
        int l=0,r=hi,ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid)){
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        return ans;
    }
};