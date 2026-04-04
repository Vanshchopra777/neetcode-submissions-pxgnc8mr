class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

vector<vector<pair<int,int>>>adj(n);

for(auto it:flights){
    adj[it[0]].push_back({it[1],it[2]});
}


//stop,node,price
queue<pair<int,pair<int,int>>>q;
    q.push({0,{src,0}});
    int minfair=INT_MAX;
    vector<int>pricearr(n,1e9);
    pricearr[src]=0;
    

    while(!q.empty()){
        int stop=q.front().first;
        int node=q.front().second.first;
        int fair=q.front().second.second;
        q.pop();
        if(stop > k) continue;
        if(node==dst && stop<=k){
            minfair=min(minfair,fair);
        }

        for(auto it:adj[node]){
            int nextnode=it.first;
            int price=it.second;

            if(fair+price<pricearr[nextnode]){
                pricearr[nextnode]=fair+price;
                q.push({stop+1,{nextnode,pricearr[nextnode]}});
            }

        }

    }
     return pricearr[dst] == 1e9 ? -1 : pricearr[dst];
        
    }
};
