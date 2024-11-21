class Solution {
public:
    void findPairs(vector<int>&nums, long long low, long long mid, long long high, long long &ans)
    {
        long long tempInc = mid+1;
        long long multiplier = 2;
        for(long long i=low;i<=mid;i++)
        {
            while(tempInc<=high and ((long long)nums[tempInc]*multiplier)<(nums[i]))
            {
                tempInc++;
            }
            ans += (tempInc-mid-1);
            //cout<<low<<" "<<mid<<" "<<high<<" "<<ans<<endl;
        }
    }
    void merge(vector<int>&nums, long long low, long long mid, long long high)
    {
        vector<long long>temp;

        long long left = low;
        long long right = mid+1;

        while(left<=mid && right<=high)
        {
            if(nums[left] <= nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid)
        {
            temp.push_back(nums[left]);
            left++; 
        }
        while(right<=high)
        {
            temp.push_back(nums[right]);
            right++; 
        }

        //cout<<low<<" "<<mid<<" "<<high<<endl;
        for(long long i=0;i<temp.size();i++)
        {
            nums[i+low] = temp[i];  
            //cout<<nums[i+low]<<" ";
        }
        cout<<endl;
        
    }
    void mergeSort(vector<int>& nums, long long low, long long high, long long &ans)
    {
        if(low == high)
            return;

        long long mid = (low+high)/2;
        mergeSort(nums, low, mid, ans);
        mergeSort(nums, mid+1, high, ans);
        findPairs(nums, low, mid, high, ans);
        merge(nums, low, mid, high);
    }
    long long reversePairs(vector<int>& nums) {
        long long ans = 0;
        mergeSort(nums, 0, nums.size()-1, ans);
        for(int i=0;i<nums.size();i++)
        {
            cout<<nums[i]<<endl;
        }
        return ans;
    }
};


