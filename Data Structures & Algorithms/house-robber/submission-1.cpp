class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        // vector<int> dp(n + 2, 0);
        int one =0;
        int two=0;

        for(int i = n - 1; i >= 0; i--) {

            int robCurrent = nums[i] + two;
            int skipCurrent = one;

            two=one;

            one = max(robCurrent, skipCurrent);
        }

        return one;
    }
};