class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int>pq;

        for(auto it:stones){

            pq.push(it);
        }

        while(!pq.empty()){
            if(pq.size()<2)return pq.top();
            int first=pq.top();
            pq.pop();
            int sec=pq.top();
            pq.pop();
            if(abs(first-sec)!=0)pq.push(abs(first-sec));
        }
        return 0;
        
    }
};
