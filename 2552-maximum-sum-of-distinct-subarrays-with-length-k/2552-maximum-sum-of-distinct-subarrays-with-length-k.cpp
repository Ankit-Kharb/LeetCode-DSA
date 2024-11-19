class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        int my_map[100001];
        memset(my_map, -1, sizeof(my_map));

        int start = 0;
        int end = 0;

        long long ans = 0;
        long long currSum = 0;

        while(end<nums.size())
        {
            long long num = nums[end];
            currSum += num;

            if(my_map[num]!=-1)
            {
                int pos = my_map[num];
                while(start <= pos)
                {
                    currSum -= nums[start];
                    my_map[nums[start]] = -1;
                    start++;
                }
            }
            my_map[num] = end;

            //cout<<start<<" "<<end<<" "<<currSum<<endl;

            if(end-start == k-1)
            {
                ans = ans<currSum ? currSum : ans;
                long long startNum = nums[start++];
                currSum -= startNum;
            }
            end++;
        }

        return ans;    
    }
};