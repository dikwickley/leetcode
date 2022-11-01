class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> x;
        set<int> y;
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    x.insert(j);
                    y.insert(i);
                }
            }
        }
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(x.count(j)==1 || y.count(i)==1) 
                    matrix[i][j] = 0;
            }
        }
        
        
    }
};