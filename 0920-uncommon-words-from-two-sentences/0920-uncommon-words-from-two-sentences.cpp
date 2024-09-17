class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        
        unordered_map<string, int> mapS1;
        unordered_map<string, int> mapS2;

        string temp = "";
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i] == ' ')
            {
                mapS1[temp] += 1;
                temp = "";
            }
            else
            {
                temp += s1[i];
            }
        }
        mapS1[temp] += 1;

        temp = "";
        for(int i=0;i<s2.size();i++)
        {
            if(s2[i] == ' ')
            {
                mapS2[temp] += 1;
                temp  = "";
            }
            else
            {
                temp += s2[i];
            }
        }
        mapS2[temp] += 1;

        vector<string>ans;

        for(auto keyValue : mapS1)
        {
            //cout<<keyValue.first<<" "<<keyValue.second<<endl;
            if(mapS2.find(keyValue.first)==mapS2.end() && keyValue.second == 1)
            {
                ans.push_back(keyValue.first);
            }
        }

        for(auto keyValue : mapS2)
        {
            if(mapS1.find(keyValue.first)==mapS1.end() && keyValue.second == 1)
            {
                ans.push_back(keyValue.first);
            }
        }

        return ans;

    }
};