class Solution {
public:

    int bfs(int i,vector<int>&vis, vector<vector<int>>&adj){
        vis[i]=1;
        queue<int>q;
        q.push(i);
        int cnt=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    bool validTree(int n, vector<vector<int>>& edges) {


        int size=edges.size();
        if(size!=n-1)return false;

        vector<vector<int>>adj(n);

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        int c;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                c= bfs(i,vis,adj);
            }
        }
        if(c==n)return true;
        else return false;

    }
};
