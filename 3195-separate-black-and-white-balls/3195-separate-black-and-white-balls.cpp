class Solution {
public:
    long long minimumSteps(string s) {
    
    int n = s.size();

    int oneIndex = 0;
    int zeroIndex = n-1;

    long long ans = 0;

    while(oneIndex < zeroIndex)
    {
        while(oneIndex < zeroIndex && s[oneIndex]!='1')
        {
            oneIndex++;
        }
        while(oneIndex < zeroIndex && s[zeroIndex]!='0')
        {
            zeroIndex--;
        }

        if(oneIndex >= zeroIndex)
            break;

        ans += (long long )(zeroIndex-oneIndex);

        oneIndex++;
        zeroIndex--;
    }
    return ans;   
}
};

/*
101001
index = 0;
index 4

010011
*/