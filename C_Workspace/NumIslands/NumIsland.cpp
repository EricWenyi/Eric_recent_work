class Solution {
public:
    int isValid(int i, int j, int r, int c){
        if(i < 0 || i >= r || j < 0 || j >= c){
            return false;
        }
        return true;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    res++;
                    BFS(grid, i, j);
                }
            }
        }
        return res;
    }
    
    void BFS(vector<vector<char>>& grid, int i, int j){
        queue<vector<int>> q;
        q.push({i, j});
        grid[x][y] = '0';
        int r = grid.size();
        int c = grid.size();
        while(!q.empty()){
            i = q.front()[0];
            j = q.front()[1];
            q.pop;
            if(isValid(i+1,j,r,c) && grid[i+1][j] == '1'){
                q.push({i + 1, j});
                grid[i+1][j] = '0';
            }
            if(isValid(i-1,j,r,c) && grid[i-1][j] == '1'){
                q.push({i - 1, j});
                grid[i-1][j] = '0';
            }
            if(isValid(i,j+1,r,c) && grid[i][j+1] == '1'){
                q.push({i, j+1});
                grid[i][j+1] = '0';
            }
            if(isValid(i,j-1,r,c) && grid[i][j-1] == '1'){
                q.push({i, j-1});
                grid[i][j-1] = '0';
            }
        }
    }
    
    
};