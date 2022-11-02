class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(m==1 && n!=1){
            return {-1};
        }
        

        vector<int> ans(m);
        
        for(int j=0; j<m; j++){
            int row = 0;
            int col = j;
            
            
            bool flag = true;
            
            
            while(row<n){
                
                                
                
                if(grid[row][col]==-1 && col == 0){
                    ans[j] = -1;
                    flag = false;
                    break;
                }
                
                if(grid[row][col]==1 && col == m-1){
                    ans[j] = -1;
                    flag = false;
                    break;
                }
                
                if(grid[row][col]==1 && col<m-1 && grid[row][col+1]==-1){
                    ans[j] = -1;
                    flag = false;
                    break;
                }
                
                if(grid[row][col]==-1 && col>0 && grid[row][col-1]==1){
                    ans[j] = -1;
                    flag = false;
                    break;
                }
                
            
                
                if(grid[row][col]==1){
                    row +=1;
                    col +=1;
                    continue;
                }
                
                if(grid[row][col]==-1){
                    row +=1;
                    col -=1;
                    continue;
                }
                
                
                
            }
            if(flag)
                ans[j] = col;    
            
            
            
            
            
        }
        
        return ans;
    }
};