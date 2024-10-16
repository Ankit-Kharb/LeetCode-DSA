class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        string ans = "";
        vector<pair<int,char>> myVec;
        myVec.push_back({a, 'a'});
        myVec.push_back({b, 'b'});
        myVec.push_back({c, 'c'});

        sort(myVec.begin(), myVec.end(), greater<pair<int, char>>());

        int count = myVec[0].first;
        char temp = myVec[0].second;
        for(int j=0;j<count;j++)
        {
            ans += temp;
        } 

        int stIndex = 2;
        int index = min(2, (int)ans.size());
        int addCount = 3;

        while(myVec[1].first > 0 or myVec[2].first > 0)
        {
            //cout<<index<<" "<<addCount<<" "<<myVec[1].first<<" "<<myVec[2].first<<endl;
            if(myVec[1].first > 0)
            {
                ans.insert(ans.begin()+index, myVec[1].second);
                myVec[1].first -= 1;
            }
            else
            {
                ans.insert(ans.begin()+index, myVec[2].second);
                myVec[2].first -= 1;
            }

            index+=addCount;

            if(index>=ans.size())
            {
                if(index-ans.size() < 2)
                index = ans.size();  
                else
                {
                    addCount+=1;
                stIndex++;
                index = stIndex;
                } 
            }
        }

     
        cout<<ans<<"Last"<<endl;

        int sameCount = 1;
        index = ans.size()-2;
        while(index >= 0)
        {
            if(ans[index] == ans[index+1])
            {
                sameCount += 1;
            }
            else
            {
                break;
            }
            index--;
        }
        cout<<"aaa "<<sameCount<<endl;

        sameCount-=2;
        if(sameCount>0)
        {
            int stPos = ans.size()-sameCount;
            ans.erase(stPos);
        }
        return ans;

    }
};
/*
aabbaabbaabb
*/