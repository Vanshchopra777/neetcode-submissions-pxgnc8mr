class Solution {
public:
    void bfs(int node,vector<int>&vis,vector<vector<int>>& adj){
        vis[node]=1;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int ver=q.front();
            q.pop();
            for(auto it:adj[ver]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        int count=0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                bfs(i,vis,adj);

            }
        }
        return count;
    }
};
