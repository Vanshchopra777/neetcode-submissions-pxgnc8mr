class Solution {
public:
    void bfs(int node,vector<vector<int>>&adj,vector<bool>&vis){

        queue<int>q;
        q.push(node);

        while(!q.empty()){
            int n=q.front();
            q.pop();


        for(auto it:adj[n]){
            if(!vis[it]){
                vis[it]=true;
                q.push(it);
            }
        }
            
            
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>>adj(n);

        for(auto it:edges){
            adj[it[1]].push_back(it[0]);
            adj[it[0]].push_back(it[1]);
        }
        vector<bool>vis(n,false);
        int cnt=0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=true;
                bfs(i,adj,vis);
                cnt++;
            }
        }


        return cnt;





    }
};
