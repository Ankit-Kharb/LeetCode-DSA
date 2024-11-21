class Solution {
public:
    const int horizontaol = 3;
    const int vertical = 7;
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        int ans = m*n;

        vector<vector<int>> visit(m, vector<int>(n, 0));
        for(auto wall: walls)
        {
            visit[wall[0]][wall[1]] = -1;   
            ans-=1;
        }

        for(auto guard: guards)
        {
            visit[guard[0]][guard[1]] = 1;   
            ans-=1;
        }

        
        for(auto guard: guards)
        {
            int guard_x = guard[0];
            int guard_y = guard[1];

            // horizontal traversal
            for(int i=guard_x+1;i<m;i++)
            {
                if(visit[i][guard_y] == 1 || visit[i][guard_y] == horizontaol || visit[i][guard_y] == -1 || visit[i][guard_y] == horizontaol*vertical)
                {
                    break;
                }
                if(visit[i][guard_y] == 0)
                {
                    visit[i][guard_y] = horizontaol;
                    ans-=1;
                }
                if(visit[i][guard_y] == vertical)
                {
                    visit[i][guard_y] = horizontaol*vertical;   
                }
            }

            for(int i=guard_x-1;i>=0;i--)
            {
                if(visit[i][guard_y] == 1 || visit[i][guard_y] == horizontaol || visit[i][guard_y] == -1 || visit[i][guard_y] == horizontaol*vertical)
                {
                    break;
                }
                if(visit[i][guard_y] == 0)
                {
                    visit[i][guard_y] = horizontaol;
                    ans-=1;
                }
                
                if(visit[i][guard_y] == vertical)
                {
                    visit[i][guard_y] = horizontaol*vertical;   
                }
            }
            // vertical traversal
            for(int i=guard_y+1;i<n;i++)
            {
                 if(visit[guard_x][i] == 1|| visit[guard_x][i] == vertical || visit[guard_x][i]== -1 || visit[guard_x][i] == horizontaol*vertical)
                {
                    break;
                }
                if(visit[guard_x][i] == 0)
                {
                    visit[guard_x][i] = vertical;
                    ans-=1;
                }
                if(visit[guard_x][i] == horizontaol)
                {
                    visit[guard_x][i] = horizontaol*vertical;   
                }
            }

            for(int i=guard_y-1;i>=0;i--)
            {
                 if(visit[guard_x][i] == 1|| visit[guard_x][i] == vertical || visit[guard_x][i]== -1 || visit[guard_x][i] == horizontaol*vertical)
                {
                    break;
                }
                if(visit[guard_x][i] == 0)
                {
                    visit[guard_x][i] = vertical;
                    ans-=1;
                }
                if(visit[guard_x][i] == horizontaol)
                {
                    visit[guard_x][i] = horizontaol*vertical;   
                }
            }


           
        }

         for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    //cout<<visit[i][j]<<" ";
                }
                cout<<endl;
            }

        return ans;

    }
};