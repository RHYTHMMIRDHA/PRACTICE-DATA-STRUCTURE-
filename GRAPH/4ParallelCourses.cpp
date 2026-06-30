/*
Problem URL : https://www.naukri.com/code360/problems/parallel-courses_1376444?leftPanelTabValue=PROBLEM


Solution : Using Kahn's algorithm (topo - sort)
TC : O(n+e)
SC : O(n)
*/

#include<bits/stdc++.h>
using namespace std;

int parallelCourses(int n, vector<vector<int>> &nums)
{
    // Write your code here.
    vector<vector<int>> g(n+1);
    vector<int> indegree(n+1, 0);

    for(auto &ele : nums){
        g[ele[0]].push_back(ele[1]);
        indegree[ele[1]]++;
    }

    queue<int> q;

    for(int i=1; i<=n; i++){
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> temp;

    int ans = 0;
    while(!q.empty()){
        ans++;
        int s = q.size();

        for(int i=1; i<=s; i++){
            int f = q.front();
            temp.push_back(f);

            q.pop();

            for(auto &ele : g[f]){
                indegree[ele]--;
                if(indegree[ele] == 0) q.push(ele);
            }
        }
    }

    if(temp.size() != n) return -1;
    return ans;
}
