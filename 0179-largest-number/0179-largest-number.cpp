class Solution {
public:
    // Trick is to sort (first+second) or (second+first)
    // 9, 98 => (998), (989) => return 998.

    static bool cmp(const int &first, const int &second)
    {
        string ff = to_string(first);
        string ss = to_string(second);

        return ff+ss > ss+ff;
    }

    string largestNumber(vector<int>& nums) {
        sort(begin(nums), end(nums), cmp);
        string ans="";
        for(auto num:nums)
        {
            ans += to_string(num);
        }
        while(ans[0] == '0' and ans.size()>1)
        {
            ans.erase(ans.begin());
        }
        return ans;
    }
};