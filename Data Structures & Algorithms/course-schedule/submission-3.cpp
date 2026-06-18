class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& nums) {
        
        vector<vector<int>>adj(n);
        for(auto it: nums){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>indegree(n);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        int count=0;
        queue<int>q;

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }


        }
        if(n==count)return true;

        return false;

        
    }
};
