class Solution {
public:
    int minLength(string s) {
        
        bool removed = false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == 'A')
            {
                if(i+1 < s.size())
                {
                    if(s[i+1] == 'B')
                    {
                        if(i+2<s.size())
                        {

                            s = s.substr(0, i) + s.substr(i+2);
                        }
                        else
                        {
                            s = s.substr(0, i);
                        }
                        removed = true;
                    }
                }
            }

            if(s[i] == 'C')
            {
                if(i+1 < s.size())
                {
                    if(s[i+1] == 'D')
                    {
                        if(i+2<s.size())
                        {

                            s = s.substr(0, i) + s.substr(i+2);
                        }
                        else
                        {
                            s = s.substr(0, i);
                        }
                        removed = true;
                    }
                }
            }
        }
        if(removed)
        {
            return minLength(s);
        }
        else
        {
            return s.size();
        }
    }
};