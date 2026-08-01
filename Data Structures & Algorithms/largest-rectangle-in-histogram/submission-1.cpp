class Solution {
public:
void nsl(vector<int>& temp,vector<int>nums){

    int n=nums.size();

        stack<pair<int,int>>st;
      

        for(int i=0;i<n;i++){

            if(st.empty()){
                temp.push_back(-1);
            }
            else if(!st.empty() && st.top().first<nums[i]){
                temp.push_back(st.top().second);
            }
            else if(!st.empty() && st.top().first>=nums[i]){
                while(!st.empty() && st.top().first>=nums[i]){
                    st.pop();

                }
                 if(st.empty()){
                temp.push_back(-1);
            }
            else if(!st.empty() && st.top().first<nums[i]){
                temp.push_back(st.top().second);
            }

            }
            st.push({nums[i],i});

        }
        
        

}
void nsr(vector<int>& temp,vector<int>nums){
    int n=nums.size();
    

        stack<pair<int,int>>st;
        

        for(int i=n-1;i>=0;i--){

            if(st.empty()){
                temp.push_back(n);
            }
            else if(!st.empty() && st.top().first<nums[i]){
                temp.push_back(st.top().second);
            }
            else if(!st.empty() && st.top().first>=nums[i]){
                while(!st.empty() && st.top().first>=nums[i]){
                    st.pop();

                }
                 if(st.empty()){
                temp.push_back(n);
            }
            else if(!st.empty() && st.top().first<nums[i]){
                temp.push_back(st.top().second);
            }

            }
            st.push({nums[i],i});

        }
        reverse(temp.begin(),temp.end());
        

}

    int largestRectangleArea(vector<int>& nums) {
        int n=nums.size();
        vector<int>left_small;
        vector<int>right_small;

        nsl(left_small,nums);
        nsr(right_small,nums);
        int maxarea=0;
        for(int i=0;i<n;i++){
            maxarea=max(maxarea,(right_small[i]-left_small[i]-1)*nums[i]);
        }
        return maxarea;



        
        
    }
};
