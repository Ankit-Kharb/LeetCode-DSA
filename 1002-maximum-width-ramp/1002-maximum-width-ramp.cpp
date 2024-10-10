class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int,int>> myNums;
        for(int i=0;i<nums.size();i++)
        {
            myNums.push_back({nums[i], i});
        }
        sort(myNums.begin(), myNums.end());

        int minIndex = myNums[0].second;

        int ans = 0;
        for(int i=1;i<myNums.size();i++)
        {
            if(myNums[i].second < minIndex)
            {
                minIndex = myNums[i].second;
            }
            else
            {
                ans = max(ans, int(myNums[i].second-minIndex));
            }
        }
        return ans;
    }
};

/*
[6,0,8,2,1,7]
[9,8,1,0,1,9,4,0,4,1]

[0, 1, 2, 6, 7, 8]
[1, 4, 3, 0, 5, 2]

[6, 0, 0, 0, 0, 0]
[8, 8, 8, 5, 5, 5]
find i<j, such that num[i] <= num[j]

what will be time complexity to find all such pairs ?

*/