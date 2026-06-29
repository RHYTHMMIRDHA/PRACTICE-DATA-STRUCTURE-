/*
PROBLEM : TO CALCULATE THE NO OF COMPONENTS
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> ro = {0, -1, 0, 1};
vector<int> col = {-1, 0, 1, 0};

void dfs(vector<vector<int>>& mat, vector<vector<int>>& visited, int r, int c){
    int n = mat.size();
    visited[r][c] = 1;
    for(int i=0; i<4; i++){
        int nr = ro[i]+r, nc = col[i]+c;
        if(nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc] && mat[nr][nc] == 1){
            dfs(mat, visited, nr, nc);
        }
    }
}

int main(){
    int n; cin >> n; // no of cities
    vector<vector<int>> mat(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> mat[i][j];
    }

    vector<vector<int>> visited(n, vector<int>(n, 0));

    int ans = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j] && mat[i][j] == 1){
                ans++;
                dfs(mat, visited, i, j);
            } 
        }
    }

    cout << ans << '\n';
}