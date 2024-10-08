public class Solution {
    public int MinSwaps(string s) {
        
        int open = 0;
        int close = 0;

        int ans = 0;
        for(int i=0;i<s.Length;i++)
        {
            if(s[i] == '[')
            {
                open++;
            }
            else
            {
                if(open > 0)
                {
                    open--;
                }
                else
                {
                    open++;
                    ans++;
                }
            }
        }
        return ans;
    }
}