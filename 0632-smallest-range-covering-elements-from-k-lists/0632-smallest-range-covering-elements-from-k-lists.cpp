class Solution {
public:
    
    struct NUM
    {
        int row;
        int index;
        int val;
        NUM(int x, int y, int z)
        {
            row = x;
            index = y;
            val = z;
        }
    };

    struct cmp
    {
        bool operator()(NUM const &a,NUM const &b)
        {
            return a.val > b.val;
        }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        priority_queue<NUM, vector<NUM>, cmp> myPQ;

        int small = INT_MAX;
        int large = -1;

        vector<int>myAns;

        int ans = INT_MAX;

        for(int i=0;i<nums.size();i++)
        {
            myPQ.push(NUM(i, 0, nums[i][0]));
            large = max(large, nums[i][0]);
            small = min(small, nums[i][0]);
        }
        int diff = large-small;
        cout<<large<<" "<<small<<" "<<diff<<" "<<ans<<endl;
        if(diff < ans)
        {
            ans = diff;
            myAns = {small, large};
        }

        while(myPQ.size() >= nums.size())
        {
            NUM pp = myPQ.top();
            int index = pp.index;
            int val = pp.val;
            int row = pp.row;

            cout<<index<<" "<<val<<" "<<row<<" "<<ans<<endl;
            myPQ.pop();

            if(nums[row].size() > index+1)
            {
                index+=1;
                pp.index = index;
                pp.val = nums[row][index];

                myPQ.push(pp);

                small = myPQ.top().val;
                large = max(large, pp.val);

                int diff = large-small;
                if(diff < ans)
                {
                    ans = diff;
                    myAns = {small, large};
                }
            }
        }

        return myAns;
    }
};

/*
[[4,10,15,24,26]
[0,9,12,20]
[5,18,22,30]]
*/