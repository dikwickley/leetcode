class Solution {
public:
    bool check(vector<vector<char>>& board, int x, int y){
        char num = board[x][y];
        for(int i=0;i<9;i++){
            if(i!=y && board[x][i]==num) return false;
        }
        for(int i=0;i<9;i++){
            if(i!=x && board[i][y]==num) return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(check(board, i, j)==false) return false;
                }
            }
        }
        
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                
                vector<int> m(10,0);
                
                for(int x=i;x<i+3;x++){
                    for(int y=j;y<j+3;y++){
                        cout<<board[x][y]<<" ";
                        if(board[x][y]!='.'){
                            int n = board[x][y] - '0';
                            m[n] += 1;    
                        }
                        
                    }
                    cout<<"\n";
                }
                
                cout<<"\n";
                
                for(int w=0;w<10;w++) if(m[w]>1) return false;
                
            }
        }
        
        return true;
    }
};