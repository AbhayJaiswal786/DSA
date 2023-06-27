#include<bits/stdc++.h>
#include "C:\\Users\\asus1\\OneDrive\\Attachments\\__Programming\\Winning Camp\\DSA\\_Shortcut.cpp"
using namespace std;


// BFS of Graph
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> BFS;
    vector<int> vis(V,0);
    vis[0] = 1;
    
    queue<int> que;
    que.push(0);
    
    while(que.size()){
        int curr_vertex = que.front(); que.pop();
        BFS.push_back(curr_vertex);
        
        for(auto neighour : adj[curr_vertex]){
            if(vis[neighour] == 0){
                vis[neighour] = 1;
                que.push(neighour);
            }
        }
    }
    return BFS;
    
}

// DFS of Graph

void DFS(int vertex, vector<int> adj[], vector<int> &vis, vector<int> &ans){
    vis[vertex] = 1;
    ans.push_back(vertex);
    for(auto neighour : adj[vertex]){
        if(vis[neighour] == 0){
            DFS(neighour, adj, vis, ans);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> vis(V,0);
    vector<int> ans;
    DFS(0, adj, vis, ans);
    return ans;
}


// Number of provinces
// SC : O(N)
// TC : O(V) + O(V+E)
int numProvinces(vector<vector<int>> adjMatrix, int V) {
    //creating adjency list
    vector<int> adjList[V];
    
    for(int i=0; i<adjMatrix.size(); i++){
        for(int j=0; j<adjMatrix[0].size(); j++){
            if(adjMatrix[i][j] == 1){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    //checking for provinces
    int provinces = 0;
    vector<int> vis(V,0);
    
    for(int vertex = 0; vertex<V; vertex++){ //O(V)
        if(vis[vertex]) continue; //if visited then continue
        
        queue<int> que;
        que.push(vertex);
        
        provinces++;
        
        while(que.size()){ //O(V+E)
            int curr_ver = que.front(); que.pop();
            vis[curr_ver] = 1;
            
            for(auto neighour : adjList[curr_ver]){
                if(vis[neighour] == 0){
                    vis[neighour] = 1;
                    que.push(neighour);
                }
            }
        }
    }
    return provinces;
}


// Number of Islands
// An island formed by connecting adjacent lands *"horizontally or vertically" i.e., in 4 directions.
void bfs_numIslands_4Dir(int row, int col, vector<vector<int>> &vis, vector<vector<char>>&grid) {
    // mark it visited
    vis[row][col] = 1; 
    queue<pair<int,int>> q;
    // push the node in queue
    q.push({row, col}); 
    int n = grid.size(); 
    int m = grid[0].size(); 

    vector<int> delrow = {-1,1,0,0};
    vector<int> delcol = {0,0,-1,1};

    // until the queue becomes empty
    while(q.size()) {
        int row = q.front().first; 
        int col = q.front().second; 
        q.pop(); 
        
        //(checking for connecting adjacent lands *"horizontally or vertically")
        // traverse in the neighbours and mark them if its a land 
        // neighbour row and column is valid, and is an unvisited land

        for(int i = 0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                if(grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
        
    }
}
int numIslands_4Dir(vector<vector<char>>& grid) {
    int n = grid.size(); 
    int m = grid[0].size(); 

    // create visited array and initialise to 0
    vector<vector<int>> vis(n, vector<int>(m, 0)); 
    int islands = 0; 
    for(int row = 0; row < n ; row++) {
        for(int col = 0; col < m ;col++) {
            // if not visited and is a land
            if(!vis[row][col] && grid[row][col] == '1') {
                islands++; 
                bfs_numIslands_4Dir(row, col, vis, grid); 
            }
        }
    }
    return islands; 
}

//Number of Islands
// An island formed by connecting adjacent lands *"horizontally or vertically or diagonally" i.e., in all 8 directions.
void bfs_numIslands_8Dir(int row, int col, vector<vector<int>> &vis, vector<vector<char>>&grid) {
    // mark it visited
    vis[row][col] = 1; 
    queue<pair<int,int>> q;
    // push the node in queue
    q.push({row, col}); 
    int n = grid.size(); 
    int m = grid[0].size(); 

    // until the queue becomes empty
    while(!q.empty()) {
        int row = q.front().first; 
        int col = q.front().second; 
        q.pop(); 
        
        //(checking for connecting adjacent lands (horizontally or vertically or diagonally)
        // traverse in the neighbours and mark them if its a land 
        for(int delrow = -1; delrow<=1;delrow++) {
            for(int delcol = -1; delcol <= 1; delcol++) {
                int nrow = row + delrow; 
                int ncol = col + delcol; 
                // neighbour row and column is valid, and is an unvisited land
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1; 
                    q.push({nrow, ncol}); 
                }
            }
        }
    }
}

int numIslands_8Dir(vector<vector<char>>& grid) {
    int n = grid.size(); 
    int m = grid[0].size(); 

    // create visited array and initialise to 0
    vector<vector<int>> vis(n, vector<int>(m, 0)); 
    int islands = 0; 
    for(int row = 0; row < n ; row++) {
        for(int col = 0; col < m ;col++) {
            // if not visited and is a land
            if(!vis[row][col] && grid[row][col] == '1') {
                islands++; 
                bfs_numIslands_8Dir(row, col, vis, grid); 
            }
        }
    }
    return islands; 
}

//Flood Fill
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) { 
    if(image[sr][sc] == color) return image;
    
    int n = image.size(); 
    int m = image[0].size(); 

    int old_color = image[sr][sc];
    image[sr][sc] = color; 
    
    queue<pair<int,int>> q;
    // push the starting pixel in queue
    q.push({sr, sc}); 

    vector<int> delrow = {-1,1,0,0};
    vector<int> delcol = {0,0,-1,1};

    // until the queue becomes empty
    while(!q.empty()) {
        int row = q.front().first; 
        int col = q.front().second; 
        q.pop(); 
        
        // traverse in the neighbours and color them with new color, if its a same starting pixel color  
        // neighbour row and column is valid,
        for(int i = 0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                if(image[nrow][ncol] == old_color){
                    image[nrow][ncol] = color;
                    q.push({nrow,ncol});
                }
            }
        }
    }

    return image;
}

//Rotting Oranges
int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size(); 
    int m = grid[0].size(); 

    queue<pair<pair<int,int>,int>> que; //pair.first = {row,col} & pair.second = minutes
    int cntfresh = 0; //counting fresh oranges

    for(int row = 0; row < n ; row++) {
        for(int col = 0; col < m ;col++) {
            // if orange rotten
            if(grid[row][col] == 2) que.push({{row,col},0});
            //if orange fresh
            if(grid[row][col] == 1) cntfresh++;
            
        }
    }
 
    vector<int> drows = {-1,1,0,0}; // delta row for 4 directions
    vector<int> dcols = {0,0,-1,1}; // delta col for 4 directions

    int total_minute = 0;
    int cntrotten = 0;
    while(que.size()){
        int row = que.front().first.first; //getting row of rotten orange
        int col = que.front().first.second; //getting col of rotten orange
        int minute = que.front().second; //getting minute taken for current rotten orange

        que.pop();

        for(int i = 0; i<4; i++){ //going for all four directions of current oranges to find any fresh oraanges so that it can be rotten
            int newrow = row + drows[i];
            int newcol = col + dcols[i];

            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m){
                if(grid[newrow][newcol] == 1 ){ //if neighour of any direction is fresh 
                    grid[newrow][newcol] = 2; //then make it rotten 
                    que.push({{newrow, newcol}, minute+1}); // and (push new rotten orange's row and col) & (push minute to rotten that orange )
                    
                    total_minute = minute+1; // update total minute has taken to rotten all oranges
                    cntrotten++; //count oranges being rotten
                }
            }
        }
    }

    if(cntfresh != cntrotten) return -1; // if previous all fresh oranges are not rotten at the end then it means ... it is not possible to rott some of oranges ... so return -1
    return total_minute;
}

// Distance of nearest cell having 1
vector<vector<int>>nearest(vector<vector<int>>mat)
{
    // Code here
    
    int rows = mat.size();
    int cols = mat[0].size();

    queue<pair<pair<int,int>,int>> que; //pair.first = {row,col} & pair.second = distance

    for(int row = 0; row < rows ; row++) {
        for(int col = 0; col < cols ;col++) {
            if(mat[row][col] == 1) que.push({{row,col},0}); // taking all vertice's row and col that having 1 and storing their distance as 0
        }
    }

    vector<vector<int>> vis(rows, vector<int>(cols, 0));

    vector<int> drows = {-1,1,0,0}; // delta row for 4 directions
    vector<int> dcols = {0,0,-1,1}; // delta col for 4 directions

    vector<vector<int>> ans(rows, vector<int>(cols, 0));

    while(que.size()){
        int curr_row = que.front().first.first;
        int curr_col = que.front().first.second;
        int dis = que.front().second;

        que.pop();

        for(int i = 0; i<4; i++){
            int nrow = curr_row + drows[i];
            int ncol = curr_col + dcols[i];

            if(nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols){
                if(mat[nrow][ncol] == 0 && vis[nrow][ncol] == 0){
                    ans[nrow][ncol] = dis + 1;
                    vis[nrow][ncol] = 1;
                    que.push({{nrow , ncol}, dis + 1});
                }
            } 
        }
    }

    return ans;
}

//Replace O's with X's || Surrounded Regions 
// Logic : Find boundary O's as wel as all O's connected with them and mark them in visited matrix 
//         then except marked O's, other O's can be converted into X's
void SurroundedRegions(vector<vector<char>>& board) {
    int rows = board.size();
    int cols = board[0].size();

    queue<pair<int,int>> que; //pair.first = {row,col}
    vector<vector<int>> vis(rows, vector<int>(cols, 0));

    for(int row = 0; row < rows ; row++) {
        for(int col = 0; col < cols ;col++) {
            if(board[row][col] == 'O' && ((row == 0 || row == rows-1) || (col == 0 || col == cols-1))){
                que.push({row,col}); // pushing all border O's 
                vis[row][col] = 1; // marking border O's 
            } // taking all border's row and col that having '0'
        }
    }

    vector<int> drows = {-1,1,0,0}; // delta row for 4 directions
    vector<int> dcols = {0,0,-1,1}; // delta col for 4 directions

    while(que.size()){ //going for search of connected O's of border O's one by one

        queue<pair<int,int>> q;
        q.push({que.front().first , que.front().second});
        que.pop();

        while(q.size()){ //going for search of connected O's in all four directions
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
                
            for(int i = 0; i<4; i++){
                int nrow = row + drows[i];
                int ncol = col + dcols[i];

                if(nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols){
                    if(board[nrow][ncol] == 'O' && vis[nrow][ncol] == 0){
                        vis[nrow][ncol] = 1;
                        q.push({nrow , ncol});
                    }
                } 
            }
        }          
    }

    for(int row = 0; row < rows ; row++) {
        for(int col = 0; col < cols ;col++) {
            if(vis[row][col] != 1 && board[row][col] == 'O') board[row][col] = 'X'; // convert all O's except marked one to X's
        }
    }

}

//Number of enclaves 
int numEnclaves(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    queue<pair<int,int>> que; //pair.first = {row,col}
    vector<vector<int>> vis(rows, vector<int>(cols, 0));

    for(int row = 0; row < rows ; row++) {
        for(int col = 0; col < cols ;col++) {
            if(grid[row][col] == 1 && ((row == 0 || row == rows-1) || (col == 0 || col == cols-1))){
                que.push({row,col}); // pushing all border 1's 
                vis[row][col] = 1; // marking border 1's 
            } // taking all border's row and col that having '1'
        }
    }

    vector<int> drows = {-1,1,0,0}; // delta row for 4 directions
    vector<int> dcols = {0,0,-1,1}; // delta col for 4 directions

    while(que.size()){ //going for search of connected 1's of border 1's one by one

        queue<pair<int,int>> q;
        q.push({que.front().first , que.front().second});
        que.pop();

        while(q.size()){ //going for search of connected 1's in all four directions
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
                
            for(int i = 0; i<4; i++){
                int nrow = row + drows[i];
                int ncol = col + dcols[i];

                if(nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols){
                    if(grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0){
                        vis[nrow][ncol] = 1;
                        q.push({nrow , ncol});
                    }
                } 
            }
        }    
    }

    int count = 0;

    for(int row = 0; row<rows; row++){
        for(int col = 0; col<cols; col++){
            if(grid[row][col] == 1 && vis[row][col] == 0) count++;
        }
    }

    return count;
    
}


//Cycle Detection using BFS
bool isCycle(int V, vector<int> adj[]) {    
    vector<int> vis(V,0);
    
    for(int vertex = 0; vertex<V; vertex++){
        if(vis[vertex]) continue; 
        
        queue<pair<int,int>> que;
        que.push({vertex,-1});
        vis[vertex] = 1;
        
        while(que.size()){
            int curr_ver = que.front().first;
            int parent = que.front().second;
            
            que.pop();
            
            for(auto neighour : adj[curr_ver]){
                if(vis[neighour] == 0){
                    vis[neighour] = 1;
                    que.push({neighour,curr_ver});
                }
                // main condition is that ... cur_ver's parent is the only neighour who has been already visited,
                // if there is neighour, who is visited but that neighour is not parent of curr_ver then "there is cycle exist"
                else if(vis[neighour] == 1 && neighour != parent) return true;
            }
        }
    }
    return false;
}

int main(){
    vector<vector<int>> adjMatrix = 
    {
        {1,0,1},
        {0,1,0},
        {1,0,1}
    };    

    int V = adjMatrix.size();
    vector<int> adjList[V];

    //converting adjMatrix into adjList
    for(int i = 0; i<V; i++){
        for(int j = 0; j<V; j++){
            if(adjMatrix[i][j] == 1 && i!=j){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    
    
    cout<<"BFS Traversal of Graph : "<<endl;
    print_vector(bfsOfGraph(V, adjList));

    cout<<"DFS Traversal of Graph : "<<endl;
    print_vector(dfsOfGraph(V, adjList));

    cout<<"Number of Provinces : ";
    cout<<numProvinces(adjMatrix,V)<<endl; 

    vector<vector<char>> grid = 
    {
        {'1','1','1'},
        {'0','1','0'},
        {'1','0','1'}
    };  
    cout<<"Number of Islands formed by connecting adjacent lands (horizontally or vertically) i.e., in 4 directions : ";
    cout<<numIslands_4Dir(grid)<<endl;

    cout<<"Number of Islands formed by connecting adjacent lands (horizontally or vertically or diagonally) i.e., in all 8 directions : ";
    cout<<numIslands_8Dir(grid)<<endl;



    










}