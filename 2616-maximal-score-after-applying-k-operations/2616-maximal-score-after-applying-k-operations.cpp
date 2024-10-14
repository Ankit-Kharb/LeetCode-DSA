class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>> myPQ;

        //sort(nums.begin(), nums.end());
        long long rem = nums.size()-k;

        
        for(long long i=nums.size()-1; i>=0 ;i--)
        {
            //cout<<"Hello"<<" "<<k<<" "<<i<<endl;
            myPQ.push((long long)nums[i]);
        }
       
        long long ans = 0;
        while(k--)
        {
            long long val = myPQ.top();
            long long valAd = (val+2)/3;
            ans += val;
            myPQ.pop();
            myPQ.push(valAd);
        }
        return ans;
    }
};