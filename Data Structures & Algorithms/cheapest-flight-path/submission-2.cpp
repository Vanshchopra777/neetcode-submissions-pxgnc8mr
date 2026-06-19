class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {


        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});

        }
        int mincost=INT_MAX;
        vector<int>cost(n,1e9);
        cost[src]=0;
        queue<vector<int>>q;
        //stop,cost,node
        q.push({0,0,src});
        while(!q.empty()){
            int stop=q.front()[0];
            int price=q.front()[1];
            int node=q.front()[2];
            q.pop();
            if(stop>k+1)continue;
           

            for(auto it:adj[node]){
                int adjnode=it.first;
                int wt=it.second;

                if(price+wt<cost[adjnode] && stop<=k){
                    cost[adjnode]=price+wt;
                    q.push({stop+1,cost[adjnode],adjnode});
                }

            }
        }
        return cost[dst]== 1e9 ?-1 :cost[dst];


        
    }
};
