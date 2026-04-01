class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(k == 1) return *max_element(nums.begin(), nums.end());
        priority_queue<int,vector<int>,greater<int>>pq;


        for(const int &it:nums){
            pq.push(it);
            if(pq.size()>k)pq.pop();
        }
        return pq.top();
        
    }
};
