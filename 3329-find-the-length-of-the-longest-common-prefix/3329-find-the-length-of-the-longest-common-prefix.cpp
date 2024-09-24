class Solution {
public:
    struct Trie
    {
        char Current;
        vector<Trie *> childerns;
        Trie(char x)
        {
            Current = x;
        }

        void Insert(string s)
        {
            for(auto child: this->childerns)
            {
                if(child->Current == s[0])
                {
                    if(s.size() == 1)
                        return ;
                    return child->Insert(s.substr(1));
                }
            }
            Trie * newT = new Trie(s[0]);
            this->childerns.push_back(newT);

            if(s.size() == 1)
                return ;
            return newT->Insert(s.substr(1));
        }

        bool Find(string s)
        {
            for(auto child: this->childerns)
            {
                if(child->Current == s[0])
                {
                    if(s.size() == 1)
                        return true;
                    return child->Find(s.substr(1));
                }
            }
            return false;
        }
    };

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_set<string> mySet;
        Trie * myTrie = new Trie('.');

        for(auto ele : arr1)
        {
            string temp  = to_string(ele);
            myTrie->Insert(temp);
        }


        int ans = 0;
        for(auto ele : arr2)
        {
            string temp  = to_string(ele);
            for(int i=0;i<temp.size();i++)
            {
                string str = temp.substr(0, i+1);
                if(myTrie->Find(str))
                {
                    ans = max(ans, (int)str.size());
                }
            }
        }
        return ans;    
    }
};  