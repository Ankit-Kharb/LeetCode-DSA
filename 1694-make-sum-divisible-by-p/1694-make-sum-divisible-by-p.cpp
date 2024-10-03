class Solution {
public:
  
    long long int findArray(vector<int>&nums, long long int reqq, long long int p)
    {
        unordered_map<long long int,long long int> myMap;
        long long int ans = INT_MAX;

        long long int sum = 0;
        for(long long int i=0;i<nums.size();i++)
        {
            sum = (sum + (long long int)nums[i])%p;
            
            long long int reqSum = (sum-reqq+p)%p;

            if(sum == reqq)
            {
                ans = min(ans, i+1);
            }
            if(reqSum == 0)
            {
                ans = min(ans, i+1);
            }
            if(myMap.find(reqSum) != myMap.end())
            {
                ans = min(ans, i-myMap[reqSum]);
            }   
            myMap[sum] = i;  
        }
        if(ans == nums.size())
        ans = -1;
        return ans;

    }
    int minSubarray(vector< int>& nums,int p) {
        long long int sum = 0;
        for(long long int i=0;i<nums.size();i++)
        {
            sum = sum +  (long long int)nums[i];
            nums[i] = nums[i]%p;
        }  
        if(sum%p == 0)
        return 0;

        long long int rem = sum%p;
        //cout<<"ankit "<<rem<<endl;
        long long int ans = findArray(nums, rem, p);  
        if(ans == INT_MAX)
        ans = -1;
        return ans;
    }
};