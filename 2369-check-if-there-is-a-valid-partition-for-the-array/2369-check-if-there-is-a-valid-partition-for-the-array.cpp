class Solution {
public:
    int solve(int i,vector<int>& nums, vector<int>&dp)
    {
        if(nums.size()==i)
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        int ans=0;
        if(i+1<nums.size() and nums[i]==nums[i+1])
            ans=max(ans,solve(i+2,nums,dp));
        if(i+2<nums.size())
        {
            if(nums[i]==nums[i+1] and nums[i+1]==nums[i+2])
                ans=max(ans,solve(i+3,nums,dp));
            else if(abs(nums[i]-nums[i+1])==1 and abs(nums[i+1]-nums[i+2])==1)
                 ans=max(ans,solve(i+3,nums,dp));
        }
        return dp[i]=ans;
        //return dp[i];
        
    }
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(0,nums,dp);
    }
};