class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<vector<int>>pq;

        for(auto it:points){
            int x=it[0];
            int y=it[1];
            pq.push({(x*x+y*y),x,y});
            if(pq.size()>k)pq.pop();
        }

        vector<vector<int>>ans;

        while(!pq.empty()){
            int x=pq.top()[1];
            int y=pq.top()[2];
            ans.push_back({x,y});
            pq.pop();
        }
        return ans;


        
    }
};
