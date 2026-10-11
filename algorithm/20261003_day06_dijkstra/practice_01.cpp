#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 4;
vector<vector<pair<int,int>>> adj;
vector<ll> dijkstra(int N, int start, vector<int>& prev) {
    vector<ll> dist(N+1, INF);
    dist[1] = 0;
    
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    pq.push({0, start});
    
    while(!pq.empty()) {
        auto [d, cur] = pq.top();
        pq.pop();
        if(d > dist[cur]) continue;
        for(auto [nxt, w] : adj[cur]) {
            auto nxt_w = d+w;
            if(nxt_w < dist[nxt]) {
                dist[nxt] = nxt_w;
                prev[nxt] = cur;
                pq.push({nxt_w, nxt});
            }
        }
    }
    return dist;
}
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    sort(road.begin(), road.end());
    adj.clear();
    adj.assign(N+1,{});
    for(auto n : road) {
        adj[n[0]].push_back({n[1],n[2]});
        adj[n[1]].push_back({n[0],n[2]});
    }
    vector<int> prev;
    prev.assign(N+1, -1);
    auto dist = dijkstra(N,1,prev);
    for(auto n : dist) {
        cout << n <<endl;
        if(n <= K) 
            answer++; 
    }
    return answer;
}
