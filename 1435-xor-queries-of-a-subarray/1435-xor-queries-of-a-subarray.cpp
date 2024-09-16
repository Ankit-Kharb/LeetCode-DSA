class Solution {
public:
    vector<int> findBits(int num)
    {
        vector<int>temp(31, 0);
        int numOfBits = 0;
        while(num)
        {
            int rem = num%2;
            temp[numOfBits++] = rem;
            num /= 2;
            //cout<<num<<endl;
        }
        //cout<<"Hello"<<endl;
        return temp;
    }
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int n = arr.size();
        vector<vector<int>> prefixArray;
        for(int i=0;i<n;i++)
        {
            if(i == 0)
            {
                vector<int> tempArr = findBits(arr[i]);
                prefixArray.push_back(tempArr);
            }
            else
            {
                vector<int> tempArr = findBits(arr[i]);
                for(int j=0;j<30;j++)
                {
                    tempArr[j] += prefixArray[i-1][j];
                }
                prefixArray.push_back(tempArr);
            }
        }

        /*for(int i=0;i<n;i++)
        {
            for(int j=0;j<10;j++)
            {
                cout<<prefixArray[i][j]<<" ";
            }
            cout<<endl;
        }*/

        vector<int>ans;
        for(auto query:queries)
        {
            int st = query[0];
            int end = query[1];

            if(st == end)
            {
                ans.push_back(arr[st]);
                continue;
            }

            vector<int>diffVec(31, 0);
            if(st == 0)
            {
                diffVec = prefixArray[end];
            }
            else
            {
                for(int j=0;j<30;j++)
                {
                    diffVec[j] = prefixArray[end][j] - prefixArray[st-1][j];
                }
            }

            int tempInt = 0;
            for(int i=0;i<=30;i++)
            {
                if(diffVec[i]%2 != 0)
                {
                    tempInt += 1<<i;
                }
            }
            
            ans.push_back(tempInt);
        }
        return ans;
    }
};

// 8 = 1000
// 7 = 0111
