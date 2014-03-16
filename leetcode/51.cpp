class Solution {
public:
    bool isValid(vector<int>& queens, int row, int col)
    {
         for(int row2 = 0; row2 < row; row2++){
            int col2 = queens[row2];
            
            if(col2 == col)
                return false;
                
            int colDist = abs(col2 - col);
            
            int rowDist = abs(row2 - row);
            
            if(colDist == rowDist)
                return false;
         }
         
         return true;
    }
    

    void placeQueens(vector<vector<string> >& results, vector<int>& queens, 
                    int row, int n)
    {
        if(row == n){
            vector<string> puzzle;
            for(int i=0; i<queens.size(); i++){
                string r(n, '.');
                r[queens[i]] = 'Q';
                puzzle.push_back(r);
            }
            results.push_back(puzzle);
        } else {
            for(int col=0; col<n; col++){
                if(isValid(queens, row, col)){
                    queens[row] = col;
                    placeQueens(results, queens, row+1, n);
                }
            }
        }       
    }

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
        vector<int> queens(n, 0);
        
        placeQueens(result, queens, 0, n);
        
        return result;
    }
};