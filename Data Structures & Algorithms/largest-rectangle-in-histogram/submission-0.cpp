class Solution {
public:
    void nsr(vector<int>&nums,vector<int>&right){
        int n=nums.size();
        stack<pair<int,int>>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty())right.push_back(n);
            else if(!st.empty() && nums[i]>st.top().first)right.push_back(st.top().second);

            else if(!st.empty() && nums[i]<=st.top().first){
                while(!st.empty() && nums[i]<=st.top().first){
                    st.pop();
                }
                if(st.empty())right.push_back(n);
                else right.push_back(st.top().second);
            }
            st.push({nums[i],i});

        }
        reverse(right.begin(),right.end());

    }

        void nsl(vector<int>&nums,vector<int>&left){
        int n=nums.size();
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++){
            if(st.empty())left.push_back(-1);
            else if(!st.empty() && nums[i]>st.top().first)left.push_back(st.top().second);

            else if(!st.empty() && nums[i]<=st.top().first){
                while(!st.empty() && nums[i]<=st.top().first){
                    st.pop();
                }
                if(st.empty())left.push_back(-1);
                else left.push_back(st.top().second);
            }
             st.push({nums[i],i});

        }
        

    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>right;
        vector<int>left;
        nsl(heights,left);
        nsr(heights,right);

  
        int maxarea=0;
        for(int i=0;i<n;i++){
           int area=(right[i]-left[i]-1)*heights[i];
            maxarea=max(maxarea,area);
        }
        return maxarea;





        
    }
};
