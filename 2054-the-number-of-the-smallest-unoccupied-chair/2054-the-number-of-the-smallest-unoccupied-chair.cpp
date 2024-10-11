
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        set<int> emptyChair;
        int time = 0;
        int maxChair = 0;

        int ans = -1;
        int targetArrival = times[targetFriend][0];

        vector<int>arrivals;
        vector<int>departure;

        unordered_map<int, vector<int>> depArriveMap;
        for(int i=0;i<times.size();i++)
        {
            arrivals.push_back(times[i][0]);
            departure.push_back(times[i][1]);

            depArriveMap[times[i][1]].push_back(times[i][0]);
        }
        unordered_map<int, int> arrChairMap;

   

        sort(arrivals.begin(), arrivals.end());

        int arrIndex = 0;
        int depIndex = 0;

        while(time <= targetArrival)
        {
           
            vector<int> arrivedPeoples = depArriveMap[time];
            for(auto people : arrivedPeoples)
            {
                int chair = arrChairMap[people];
                emptyChair.insert(chair);
                //cout<<time<<" "<<depIndex<<" "<<chair<<endl;
            }

            if(arrIndex<times.size() &&arrivals[arrIndex] == time)
            {
                if(emptyChair.size() == 0)
                {
                    if(time == targetArrival)
                    {
                        ans = maxChair;
                        return ans;
                    }
                    //cout<<"Arrival "<<time<<" "<<arrIndex<<" "<<maxChair<<endl;
                    arrChairMap[time] = maxChair++;
                }
                else
                {
                    int firstChair = *(emptyChair.begin());
                    arrChairMap[time] = firstChair;
                    emptyChair.erase(emptyChair.begin());

                    //cout<<"Arrival "<<time<<" "<<arrIndex<<" "<<firstChair<<endl;
                    if(time == targetArrival)
                    {
                        ans = firstChair;
                        return ans;
                    }
                }
                arrIndex++;   
            }
            time++;
        }
        return ans;

    }
};
/*
Traget coming time = 5
[[3,10],[1,5],[2,6],[7,10],[4,15],[5,20],[8,20],[20,30],[30,40]]
1 2 3 4 5
5 6 10 10 15
*/