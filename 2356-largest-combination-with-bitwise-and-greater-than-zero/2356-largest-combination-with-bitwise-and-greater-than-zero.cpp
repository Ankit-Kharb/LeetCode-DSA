class Solution {
public:
    void breakInBinary(int &x, unordered_map<int,int> &my_map)
    {
        int index = 0;
        while(x)
        {
            my_map[index] += x&1;
            x = x>>1;
            index++;
        }
    }
    int largestCombination(vector<int>& candidates) {
        
        unordered_map<int,int> my_map;
        for(auto candid : candidates)
        {
            breakInBinary(candid, my_map);
        }
        int ans = 0;

        for(int i=0;i<31;i++)
        {
            ans = max(ans, my_map[i]);
        }
        return ans;
    }
};