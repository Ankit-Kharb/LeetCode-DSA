class Solution {
public:
    int dp[50];
    int solve(string s, int index, unordered_set<string> &mySet, int extraCount)
    {
        if(index == s.size())
        {
            return 0;
        }

        if(dp[index] != -1)
        {
            return dp[index];
        }

        string temp = "";
        int ans = INT_MAX;
        for(int i = index;i<s.size();i++)
        {
            temp += s[i];

            if(mySet.find(temp) != mySet.end())
            {
                ans = min(ans, solve(s, i+1, mySet, extraCount));   
            }
        }
        ans = min(ans, 1+solve(s, index+1, mySet, extraCount));
        return dp[index]=ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {

        memset(dp, -1, sizeof(int)*50);
        unordered_set<string> mySet = unordered_set(dictionary.begin(), dictionary.end());
        int ans = solve(s, 0, mySet, 0);
        return ans;
    }
};


/*
Recursion : Without Memoisation
Time Complexity : 
1. Looping : s.size()*size() = > 50*50 = 2500 = > 2^103
2. Each element can be selected => 2^50

class Solution {
public:
    int solve(string s, int index, unordered_set<string> &mySet, int extraCount)
    {
        if(index == s.size())
        {
            return 0;
        }

        string temp = "";
        int ans = INT_MAX;
        for(int i = index;i<s.size();i++)
        {
            temp += s[i];

            if(mySet.find(temp) != mySet.end())
            {
                ans = min(ans, solve(s, i+1, mySet, extraCount));   
            }
        }
        ans = min(ans, 1+solve(s, index+1, mySet, extraCount));
        return ans;

    }
    int minExtraChar(string s, vector<string>& dictionary) {

        unordered_set<string> mySet = unordered_set(dictionary.begin(), dictionary.end());
        int ans = solve(s, 0, mySet, 0);
        
    }
};

Failed TC : 
"octncmdbgnxapjoqlofuzypthlytkmchayflwky"
dictionary = ["m","its","imaby","pa","ijmnvj","k","mhka","n","y","nc","wq","p","mjqqa","ht","dfoa","yqa","kk","pixq","ixsdln","rh","dwl","dbgnxa","kmpfz","nhxjm","wg","wky","oct","og","uhin","zxb","qz","tpf","hlrc","j","l","tew","xbn","a","uzypt","uvln","mchay","onnbi","hlytk","pjoqlo","dxsjr","u","uj"]

*/