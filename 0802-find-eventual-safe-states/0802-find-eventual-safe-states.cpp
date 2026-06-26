class Solution {
    bool dfs(int node,vector<vector<int>>& graph,vector<int>& vis,vector<int>& pathVis,vector<int>& check){
        vis[node]=1;
        pathVis[node]=1;
        check[node]=0;
        for(auto it : graph[node]){
            if(!vis[it]){
                if(dfs(it,graph,vis,pathVis,check)==true){
                    check[node]=0;
                    return true;
                }
            }
            else if(pathVis[it]){
                check[node]=0;
                return true;
            }
        }
        check[node]=1;
        pathVis[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> vis(v, 0);
        vector<int> pathVis(v, 0);
        vector<int> check(v, 0);
        for(int i=0;i<v;i++){
            if(!vis[i]) dfs(i,graph,vis,pathVis,check);
        }
        vector<int> safeNodes;
        for(int i=0;i<v;i++){
            if(check[i]) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};