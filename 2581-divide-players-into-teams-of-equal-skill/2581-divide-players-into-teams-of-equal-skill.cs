public class Solution {
    public long DividePlayers(int[] skill) {
        
        int n = skill.Length;
        Array.Sort(skill);

        long ans = 0;
        int reqSum = skill[0]+ skill[n-1];
        for (int i = 0; i<n/2;i++)
        {
            long first = skill[i];
            long second = skill[n-i-1];
            ans += first*second;

            int skillSum = skill[i] + skill[n-i-1];
            if(skillSum != reqSum)
            return -1;
        }
        return ans;
    }
}