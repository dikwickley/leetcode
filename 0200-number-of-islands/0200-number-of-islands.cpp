class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<"\n";
        }
        
        queue<pair<pair<int,int>,int>> q;
        set<pair<int,int>> visited;
        
        
        
        int ans = 0;
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                
                
                if(grid[i][j]=='0') continue;
                
                if(visited.count({i,j})==1) continue;
                
                
                int counter = 1;
        
                q.push({{i,j},counter});
        
                while(!q.empty()){
                    pair<pair<int,int>, int> top = q.front();
                    q.pop();

                    int x = top.first.first;
                    int y = top.first.second;
                    counter = top.second;

                    if(x>0 && grid[x-1][y]=='1' && visited.count({x-1,y})==0) {
                        q.push({{x-1,y}, counter + 1});
                        visited.insert({x-1,y});
                    }


                    if(x<n-1 && grid[x+1][y]=='1' && visited.count({x+1,y})==0) {
                        q.push({{x+1,y}, counter + 1});
                        visited.insert({x+1,y});
                    }

                    if(y>0 && grid[x][y-1]=='1' && visited.count({x,y-1})==0) {
                        q.push({{x,y-1}, counter + 1});
                        visited.insert({x,y-1});
                    }

                    if(y<m-1 && grid[x][y+1]=='1' && visited.count({x,y+1})==0) {
                        q.push({{x,y+1}, counter + 1});
                        visited.insert({x,y+1});
                    }
                    
                    if(q.empty()) ans++;

                }
            }
        }
        
        return ans;
    }
};