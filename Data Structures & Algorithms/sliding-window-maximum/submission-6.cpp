class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();

        int i=0;
        int j=0;
        vector<int>ans;
        deque<int>q;


        while(j<n){

            while(!q.empty() && nums[j]> q.back()){
                q.pop_back();
            }

            q.push_back(nums[j]);

            if(j-i+1==k){
                ans.push_back(q.front());
                if(nums[i]==q.front()){
                    q.pop_front();
                }
                i++;
            }
            

            
            j++;

        }
        return ans;

        
    }
};
