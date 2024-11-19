class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> my_map;
        int start = 0;
        int end = 0;

        long long ans = 0;
        long long currSum = 0;

        while(end<nums.size())
        {
            long long num = nums[end];
            currSum += num;

            if(my_map.find(num) != my_map.end())
            {
                int pos = my_map[num];
                while(start <= pos)
                {
                    currSum -= nums[start];
                    my_map.erase(nums[start]);
                    start++;
                }
            }
            my_map[num] = end;

            //cout<<start<<" "<<end<<" "<<currSum<<endl;

            if(end-start == k-1)
            {
                ans = max(ans, currSum);
                long long startNum = nums[start++];
                currSum -= startNum;
            }
            end++;
        }

        return ans;    
    }
};