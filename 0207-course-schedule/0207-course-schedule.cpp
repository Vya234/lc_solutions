class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v=numCourses;
        vector<int> adj[v];
        for(auto it : prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        vector<int> indegree(v,0);
        for(int i=0;i<v;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0) q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(cnt==v) return true;
        return false;
    }
};