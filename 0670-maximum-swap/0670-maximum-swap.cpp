class Solution {
public:
    int getNum(vector<int> &digits)
    {
        int temp = 0;
        for(int i=0;i<digits.size();i++)
        {
            temp = temp*10;
            temp += digits[i];
        }
        return temp;
    }
    int maximumSwap(int num) {
        
        vector<int>digits;
        int temp = num;
        while(temp)
        {
            int rem = temp%10;
            digits.insert(digits.begin(), rem);
            temp /= 10;
        }

        int ans = num;
        for(int i=0;i<digits.size();i++)
        {
            for(int j=i+1;j<digits.size();j++)
            {
                swap(digits[i], digits[j]);
                temp = getNum(digits);
                ans = max(ans, temp);
                swap(digits[i], digits[j]);
            }
        }
        return ans;    
    }
};