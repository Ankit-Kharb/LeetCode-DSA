class Solution {
public:
    vector<int> LIS(vector<int>& nums)
    {
        int n = nums.size();

        vector<int>ans(n, 0);
        
        for(int i=0;i<n-1;i++)
        {
            ans[i] = 1;
            for(int j=i-1;j>=0;j--)
            {
                if(nums[j] < nums[i])
                {
                    ans[i] = max(ans[i], ans[j]+1);
                }
            }
        }
        return ans;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        
        int n = nums.size();

        vector<int>preLIS = LIS(nums);
        reverse(nums.begin(), nums.end());
        vector<int>postLIS = LIS(nums);
        reverse(postLIS.begin(), postLIS.end());
       // reverse(nums.begin(), nums.end());

        int lisSize = 0;
        for(int i=0;i<n;i++)
        {
            if(preLIS[i]<=1 or postLIS[i]<=1)
            continue;

            lisSize = max(lisSize, preLIS[i]+postLIS[i]-1);
            //cout<<nums[i]<<" "<<preLIS[i]<<" "<<postLIS[i]<<endl;
        }
        return n - lisSize;
    }
};
/*
[2,1,1,5,6,2,3,1]


*/