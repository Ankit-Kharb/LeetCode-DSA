public class Solution {
    public int MinAddToMakeValid(string s) {
        
        int open = 0;
        int ans = 0;

        for(int i=0;i<s.Length;i++)
        {
            if(s[i] == ')')
            {
                if(open == 0)
                {
                    ans += 1;
                }
                else
                {
                    open-=1;
                }
            }
            else
            {
                open+=1;
            }
        }

        return ans+open;

    }
}