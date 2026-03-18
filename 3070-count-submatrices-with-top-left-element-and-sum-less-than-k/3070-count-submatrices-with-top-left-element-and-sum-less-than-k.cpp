class Solution {
public:
   static int countSubmatrices(vector<vector<int>>& grid, int limit) {
    const int rows = grid.size(), cols = grid[0].size();

    int count = 0 ;
    int breakcol = cols;

    if( grid[0][0] > limit) return 0;
    count++;

    for( int col =1 ; col < cols ; col++){
        
        int& prefixsum = grid[0][col];
        prefixsum += grid[0][col - 1];
        if ( prefixsum > limit){
            breakcol = col;
            break;
        }
        count++;
    }
    for( int row = 1;row < rows; row++){
        grid[row][0] += grid[row-1][0];

        if ( grid[row][0] > limit) break;
        count++;
        for( int col =1 ; col < breakcol ; col++){
            int& prefixsum = grid[row][col];
            prefixsum += grid[row-1][col]+ grid[row][col-1]-grid[row- 1][col -1];
            if( prefixsum >limit){
                breakcol =  col;
                break;

            }
            count++ ;

        }
    }
    return count ;

        
    }
};