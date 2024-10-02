class Solution {
public:

    //const int maxSize = 10e5+1;
    bool canArrange(vector<int>& arr, int k) {
        int countP[100001] = {0};
        int countN[100001] = {0};
        int zeroVals = 0;

        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]%k==0)
            {
                zeroVals++;
                continue;
            }

            if(arr[i] > 0)
            {
                countP[arr[i]%k]++;
            }
            else if(arr[i] < 0)
            {
                countN[(-1*arr[i])%k]++;
            }
        }

        if(zeroVals%2 != 0)
        {
            cout<<"hey "<<zeroVals<<endl;
            return false;
        }

        for(int i=1;i<(k/2)+1;i++)
        {
            int minCount = countP[i];
            int maxCount = countP[k-i];

            if(minCount < maxCount)
            {
                int diff = maxCount-minCount;
                cout<<i<<" "<<minCount<<" "<<maxCount<<countN[k-i]<<endl;
                if(countN[k-i] < diff)
                {
                    return false;
                }
                else
                {
                    countN[k-i] -= diff;
                }
            }
            else
            {
                int diff = minCount-maxCount;
                cout<<i<<" "<<minCount<<" "<<maxCount<<countN[i]<<endl;
                if(countN[i] < diff)
                {
                    return false;
                }
                else
                {
                    countN[i] -= diff;
                }
            }
        }

        for(int i=1;i<(k/2)+1;i++)
        {
            int minCount = countN[i];
            int maxCount = countN[k-i];

            cout<<i<<" "<<minCount<<" "<<maxCount<<countN[i]<<endl;
            if(minCount != maxCount)
            {
                return false;
            }
        }
        return true;
    }
};