#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

bool visited[105][105] = {0,};
bool findlv = false;
int tolv = 1e7;
int lx,ly;
int answer = 1e7;
struct node {
    int x,y,times;
};
queue<node>q;


int bfs(const vector<string>& maps, int i, int j)
{
    int n = maps.size();
    int m = maps[0].size();
    while(!q.empty()) q.pop();
    for(int i = 0; i < 105; i++)for(int j = 0; j < 105;j++) visited[i][j] = 0;
    
    q.push({i,j,1});
    
    while(!q.empty()) {
        auto[x,y,times] = q.front();
        q.pop();
        
        for(int k = 0; k < 4; k++) {
            int ni = x+dx[k];
            int nj = y+dy[k];
            if(ni < 0 || ni >= n || nj < 0 || nj >= m) 
                continue;
            if(visited[ni][nj] == true || maps[ni][nj] =='X')
                continue;
            if(maps[ni][nj] == 'L') {
                findlv = true;
                lx = ni, ly = nj;
                if(tolv > times) {
                    tolv = times;
                }
                break;
            }
            q.push({ni,nj,times+1});
            visited[ni][nj] = true;
        }
    }
    if(!findlv) {
        return -1;
    }

    for(int i = 0; i < 105; i++)for(int j = 0; j < 105;j++) 
        visited[i][j] = 0;
    
    q.push({lx,ly,tolv+1});

    while(!q.empty()) {
        auto[x,y,times] = q.front();
        q.pop();
        
        for(int k = 0; k < 4; k++) {
            int ni = x+dx[k];
            int nj = y+dy[k];
            if(ni < 0 || ni >= n || nj < 0 || nj >= m ||
               visited[ni][nj] == true || maps[ni][nj] =='X')
                continue;
            if(maps[ni][nj] == 'E') {
                if(answer > times) {
                    answer = times;
                }
                break;
            }
            q.push({ni,nj,times+1});
            visited[ni][nj] = true;
        }
    }
    if(answer == 1e7) return -1;
    return answer;
    
}
int solution(vector<string> maps) {
    int i=0,j = 0;
    answer = 1e7;
    tolv= 1e7;
    findlv = false;
    for(const auto& n : maps){
        auto idx = n.find('S');
        if(idx == string::npos) {
            i++;
        } else {
            j = idx;
            break;
        }
    }
    return  bfs(maps,i,j);
}
