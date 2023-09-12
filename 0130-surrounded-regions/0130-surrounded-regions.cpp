class Solution {
public:

    void dfs(vector<vector<char>>& board, int row,int col, vector<vector<int>>& visited){
        visited[row][col] = 1;
        int n = board.size();
        int m = board[0].size();
        for(int i=-1 ; i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(abs(i)==abs(j)) continue;
                int nrow = row+i;
                int ncol = col +j;
                if(nrow<n && nrow>=0 && ncol>=0 && ncol<m && !visited[nrow][ncol] && board[nrow][ncol]=='O' ){
                    dfs(board, nrow,ncol, visited);
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n,vector<int> (m,0));

        // for traversing through columns
        for(int j=0;j<m;j++){
            if(!visited[0][j] && board[0][j] == 'O'){
                dfs(board,0,j,visited);
            }
            if(!visited[n-1][j] && board[n-1][j] == 'O'){
                dfs(board,n-1,j,visited);
            }
        }

        // for traversing through rows
        for(int i=0;i<n;i++){
            if(!visited[i][0] && board[i][0] == 'O'){
                dfs(board,i,0,visited);
            }
            if(!visited[i][m-1] && board[i][m-1] == 'O'){
                dfs(board,i,m-1,visited);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }

    }
};