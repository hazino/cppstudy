#include <bits/stdc++.h>
using namespace std;
int answer = 1e7;
bool visited[10005][2];
void solve(int idx, int jdx, 
           int ival, int jval, const vector<vector<int>>& sizes){
    int ot =0;
    auto dx = max(ival, sizes[idx][jdx]);
    if(jdx ==0)
        ot = 1;
    auto dy = max(jval, sizes[idx][ot]);

    if(sizes.size()-1 == idx) {
        if (answer > dx* dy) answer = dx*dy;
        return;
    }
    
    solve(idx+1, 0, dx,dy,sizes);
    solve(idx+1, 1, dx,dy,sizes);
}

int solution(vector<vector<int>> sizes) {
    int width = 0;
    int height = 0;

    for (const auto& size : sizes) {
        width = max(width, max(size[0], size[1]));
        height = max(height, min(size[0], size[1]));
    }

    return width * height;
}
