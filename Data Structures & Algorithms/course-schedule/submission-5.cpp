class Solution {
public:
    bool canFinish(int nc, vector<vector<int>>& nums) {

        int n=nums.size();
        vector<vector<int>>adj(nc);
        vector<int>indegree(nc);




        for(int i=0;i<n;i++){
            adj[nums[i][1]].push_back(nums[i][0]);

            indegree[nums[i][0]]++;
            
        }
        queue<int>q;
        for(int i=0;i<nc;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int cnt=0;


        while(!q.empty()){

            int node=q.front();
            q.pop();

            cnt++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }


        }
        if(cnt==nc)return true;
        return false;






        
    }
};
