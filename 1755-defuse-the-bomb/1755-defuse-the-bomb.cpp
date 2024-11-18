class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        
        int start = 0;
        int cSum = 0;
         int n = code.size();

        vector<int>ans(n);

        if(k == 0)
        {
            for(int i=0;i<code.size();i++)
            {
                ans[i] = 0;
            }
        }

         if(k>0)
        {

            start = k;
            for(int i=0;i<k;i++)
            {
                cSum += code[i];
            }

            for(int i=0;i<n;i++)
            {
                cSum += code[start];
                cSum -= code[i];

                ans[i] = cSum;

                start++;
                start = (start+n)%n;
            }
        }

        if(k<0)
        {
            k = -k;
            start = n-k-1;
            for(int i=n-1;i>start;i--)
            {
                cSum += code[i];
            }

            for(int i=n-1;i>=0;i--)
            {
                //cout<<"Test1 "<<start<<" "<<i<<" "<<cSum<<" "<<code[i]<<endl;
                cSum += code[start];
                cSum -= code[i];

                ans[i] = cSum;

                start--;
                start = (start+n)%n;
                //cout<<"Test "<<start<<" "<<i<<" "<<cSum<<endl;
            }
        }   

       

        return ans;   
    }
};