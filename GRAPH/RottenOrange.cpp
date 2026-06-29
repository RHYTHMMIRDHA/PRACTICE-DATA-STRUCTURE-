/*
PROBLEM : 

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> ro = {0, -1, 0, 1};
vector<int> col = {-1, 0, 1, 0};

int main(){
    int m, n; cin >> m >> n; // no of cities
    vector<vector<int>> mat(m, vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++) cin >> mat[i][j];
    }

    queue<pair<int, int>> q;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] == 2) q.push({i, j});
        }
    }

    int t = 0;

    while(!q.empty()){
        int qs = q.size();


        for(int i=1; i<=qs; i++){
            int r = q.front().first, c = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nr = ro[i]+r, nc = col[i]+c;
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && mat[nr][nc] == 1){
                    mat[nr][nc] = 2;
                    q.push({nr, nc});
                }
            }
        }
        if(!q.empty()) t++;
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] == 1) t = -1;
        }
    }

    cout << t << '\n';
}

// tc : O(m*) sc : O(m*n)