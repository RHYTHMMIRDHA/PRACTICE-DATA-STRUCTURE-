/*
Problem : https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/?envType=daily-question&envId=2026-07-01

Solution : first make the matrix using multi-source bfs and then apply dijkstra's algorithm to find the safest path from (0,0) to (n-1,m-1)

tc : O(n*n*log(n*n))
sc : O(n*n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();        

        queue<pair<int, int>> q;
        vector<vector<int>> mat(m, vector<int>(n, INT_MAX));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    mat[i][j] = 0;
                }
            }
        }

        vector<int> ro = {0, -1, 0, 1}, col = {-1, 0, 1, 0};

        int dist = 0;

        while(!q.empty()){
            int s = q.size();

            for(int i=1; i<=s; i++){
                int r = q.front().first, c = q.front().second;

                q.pop();

                for(int j=0; j<4; j++){
                    int nr = r+ro[j], nc = c+col[j];

                    if(nr >= 0 && nr < m && nc >=0 && nc < n && mat[nr][nc] > mat[r][c]+1){
                        q.push({nr, nc});
                        mat[nr][nc] = mat[r][c] + 1;
                    }
                }
            }
        }


        priority_queue<vector<int>> pq;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        pq.push({mat[0][0], 0, 0});
        vis[0][0] = 1;

        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();

            int safe = cur[0];
            int r = cur[1];
            int c = cur[2];

            if(r == n-1 && c == n-1) return safe;

            for(int k=0;k<4;k++){
                int nr = r + ro[k];
                int nc = c + col[k];

                if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    pq.push({min(safe, mat[nr][nc]), nr, nc});
                }
            }
        }


        return 0;

    }
};