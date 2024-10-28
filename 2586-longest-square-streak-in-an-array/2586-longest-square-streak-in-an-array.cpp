class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        
        map<int,int> myMap;
        for(int i=0;i<nums.size();i++)
        {
            myMap[nums[i]] = 1;
        }

        int ans = -1;
        for(int i=0;i<nums.size();i++)
        {
            int sequence = 1;
            long long temp = nums[i];

            while(1)
            {
                long long square = temp*temp;
                if(myMap[square]>1)
                {
                    sequence += myMap[square];
                    break;
                }

                //cout<<nums[i]<<" "<<square<<" "<<"hello"<<endl;
                if(myMap[square] == 0 || square >= 10e5)
                {
                    break;
                }

                //myMap[temp] = 0;
                sequence+=1;
                temp = square;
            }
            if(sequence>=2)
            ans = max(ans, sequence);

            myMap[nums[i]] = sequence;
        }
        return ans;
    }
};