class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        pq.push({grid[0][0],{0,0}});
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        int tmin=INT_MAX;
        vector<vector<int>>level(n,vector<int>(m,1e9));
        level[0][0]=0;
        while(!pq.empty()){
            int waterlevel=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(r==n-1 && c==m-1){
                // tmin=min(tmin,waterlevel);no need of this direct return 
                // as dijkstra gurantees of minimum in first time pop only 
                return waterlevel;
                
            }
            for(int i=0;i<4;i++){
                int newr=r+delr[i];
                int newc=c+delc[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m ){
                    if(max(waterlevel,grid[newr][newc])<level[newr][newc]){
                        level[newr][newc]=max(waterlevel,grid[newr][newc]);
                        pq.push({level[newr][newc],{newr,newc}});


                    }
                    
                }
            }
        }
        return tmin;

        
    }
};
