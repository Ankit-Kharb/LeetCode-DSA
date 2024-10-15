class Solution {
public:
    long long minimumSteps(string s) {
    
    int n = s.size();

    int oneIndex = 0;
    int zeroIndex = n-1;

    long long ans = 0;

    while(oneIndex < zeroIndex)
    {
        while(s[oneIndex]!='1' && oneIndex < zeroIndex )
        {
            oneIndex++;
        }
        while(s[zeroIndex]!='0' && oneIndex < zeroIndex )
        {
            zeroIndex--;
        }

        ans += (zeroIndex-oneIndex);

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