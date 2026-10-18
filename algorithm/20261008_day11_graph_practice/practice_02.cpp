#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll ENF = LLONG_MAX / 4;
using node = pair<ll, int>;
bool visited[20001] = {false};

int bfs(int n, const vector<vector<int>>& info_) {
    queue<node> q;
    vector<ll> arr(n+1, ENF);
    q.push({0,1});
    visited[1] = true;
    int mval = -1;
    int cnt = 0;
    while(!q.empty()) {
        auto [dist, p] = q.front();
        q.pop();     
        arr[p] = dist;     
        for(auto c : info_[p]) {
            auto ndist = dist + 1;
            auto np = c;
            if(visited[np] == true) continue;
            visited[np] = true;
            arr[np] = ndist;
            q.push({ndist, np});
        }
    }
    
    for(int i = 1; i <=n; i++) {
        cout << i << ":"<<arr[i]<<endl;
        if(arr[i] >mval)  {mval = arr[i]; cnt =1;}
        else if(arr[i] == mval) {cnt++;}
    }
    return cnt;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> info_(n+1);
    for(auto a : edge) {
        int aa = a[0];
        int bb = a[1];
        info_[aa].push_back(bb);
        info_[bb].push_back(aa);
    }
    for(int i = 0; i <=20000; i++) visited[i] = false;
    answer = bfs(n, info_);
    return answer;
}
