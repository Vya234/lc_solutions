class Solution {
    vector<int> parent;
    int find(int x){
        if(parent[x]==x) return x;
        return find(parent[x]);
    }
    void unite(int u,int v){
        int pu = find(u);
        int pv = find(v);
        parent[pv] = pu;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            if(find(u)==find(v)) return {u,v};
            unite(u,v);
        }
        return {};
    }
};