#include <bits/stdc++.h>

using namespace std;
int answer = 0;
bool visited[15];
void solve(int cur, int idx,
           int health,
           const vector<vector<int>>& vec){
    if(vec.size() == idx) {
        if(answer < cur) answer = cur;
        return;
    }
    
    for (int i = 0; i < vec.size(); i++) {
        if(visited[i]) continue;
        auto minimum = vec[i][0];
        auto minus = vec[i][1];
        visited[i] = true;
        if(minimum <= health) solve(cur+1, idx+1, health-minus, vec);
        else solve(cur, idx+1, health, vec);
        
        visited[i] = false;
    }

}
int solution(int k, vector<vector<int>> dungeons) {
    answer = 0;
    memset(visited, 0, sizeof(visited));
    
    solve(0,0,k,dungeons);
    return answer;
}
