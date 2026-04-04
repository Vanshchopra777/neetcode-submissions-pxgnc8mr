class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        vector<int>vis(n,0);
        int totalcost=0;

        pq.push({0,0});
        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;

            pq.pop();
            if(vis[node])continue;
            vis[node]=1;
            totalcost+=dist;

            for(int i=0;i<n;i++){
                if(!vis[i]){
                    int man_dist=(abs(points[i][0]-points[node][0])+abs(points[i][1]-points[node][1]));
                    pq.push({man_dist,i});
                }


            }
        }
        return totalcost;

        
    }
};
