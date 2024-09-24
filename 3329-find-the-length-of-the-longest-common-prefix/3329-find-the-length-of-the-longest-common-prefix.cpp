class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_set<string> mySet;

        for(auto ele : arr1)
        {
            string temp  = to_string(ele);
            for(int i=0;i<temp.size();i++)
            {
                mySet.insert(temp.substr(0, i+1));
            }
        }


        int ans = 0;
        for(auto ele : arr2)
        {
            string temp  = to_string(ele);
            for(int i=0;i<temp.size();i++)
            {
                string str = temp.substr(0, i+1);
                if(mySet.find(str) != mySet.end())
                {
                    ans = max(ans, (int)str.size());
                    
                }
            }
        }
        return ans;    
    }
};