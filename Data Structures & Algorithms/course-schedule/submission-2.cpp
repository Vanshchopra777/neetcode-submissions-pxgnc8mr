class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {

        vector<vector<int>>adj(n);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>indeg(n);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indeg[it]++;
                
            }
        }
        queue<int>q;
        // vector<int>topo;
        int count=0;
        for(int i=0;i<n;i++){
            if(indeg[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            // topo.push_back(node);
            count++;

            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }

            }
        }

        // int size=topo.size();
        if(n==count)return true;


        return false;

        

        
    }
};
