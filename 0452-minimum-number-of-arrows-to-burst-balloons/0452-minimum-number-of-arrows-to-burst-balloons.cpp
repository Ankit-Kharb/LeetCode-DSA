class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end());
        int ans = 0;
        int index = 0;

        vector<int>prevPoint{-1};
        for(auto point : points)
        {
            if(prevPoint[0] == -1)
            {
                prevPoint = point;
            }
            else
            {
                if(point[0] <= prevPoint[1])
                {
                    int commonSt = max(point[0], prevPoint[0]);
                    int commonEnd = min(point[1], prevPoint[1]);

                    prevPoint[0] = commonSt;
                    prevPoint[1] = commonEnd;
                }
                else
                {
                    ans += 1;
                    prevPoint = point;
                }
            }
            index++;
        }
        return ans+1; 
    }
};
/*
[[10,16],[2,8],[1,6],[7,12]]
*/