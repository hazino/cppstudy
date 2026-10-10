// Platform: Programmers
// Problem: 게임 맵 최단거리
// URL: https://school.programmers.co.kr/learn/courses/30/lessons/1844
// 먼저 브라우저 편집기에서 직접 작성하고, 풀이 후 이 파일에 기록한다.
// 입력 크기 / First Approach / Selected Algorithm / Time Complexity:
// 예상 Edge Case:

#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};
bool visited[105][105] = {0,};
int answer = 0;

struct node {
    int x,y,sum;
};
queue<node> q;
void dfs(int i, int j, const vector<vector<int>>& maps, int sum, int n, int m)
{
    if(i == n-1 && j == m-1) {
        if(sum < answer) answer = sum;
        return;
    }
    for(int k = 0; k< 4; k++){
        int ni = i +dx[k];
        int nj = j +dy[k];
        if(ni < 0 || ni >=n  || nj < 0 || nj >=m)
            continue;
        if(visited[ni][nj] == true || maps[ni][nj] == 0)
            continue;
        visited[ni][nj] = true;
        dfs(ni,nj,maps,sum+1,n,m);
        visited[ni][nj] = false;
    }
}
void bfs(const vector<vector<int>>& maps)
{
    int n = maps.size();
    int m = maps[0].size();
    while(!q.empty()) q.pop();
    node start{0,0,1};
    q.push(start);
    while(!q.empty()) {
        auto [i,j,sum] = q.front(); q.pop();
        
         if(i == n-1 && j == m-1) {
            if(sum < answer) answer = sum;
            continue;
        }
        for(int k = 0; k< 4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni < 0 || ni >= n  || nj < 0 || nj >= m)
                continue;
            if(visited[ni][nj] == true || maps[ni][nj] == 0)
                continue;
            visited[ni][nj] = true;
            q.push({ni,nj,sum+1});
        }
    }
}
int solution(vector<vector<int> > maps)
{

    
    visited[0][0] = true;
    answer = 100000;
    //dfs(0,0,maps,1, n, m);
    bfs(maps);
    
    if(answer == 100000) answer = -1;

    return answer;
}
