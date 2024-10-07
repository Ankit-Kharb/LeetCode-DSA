class Solution {
public:
    string helper(string s, int index)
    {
        if(index == -1)
            index = 0;

        if(s.size() == 0 || index == s.size() || index  == s.size()-1)
            return s;

        if(s[index] == 'A' and s[index+1] == 'B')
        {
            string temp = s.substr(0, index);
            if(index + 2 < s.size())
                temp += s.substr(index+2);
            return helper(temp, index-1);
        }
        else if(s[index] == 'C' and s[index+1] == 'D')
        {
            string temp = s.substr(0, index);
            if(index + 2 < s.size())
                temp += s.substr(index+2);
            return helper(temp, index-1);
        }
        return helper(s, index+1);
    }
    int minLength(string s) 
    {    
        return helper(s, 0).size();
    }
};