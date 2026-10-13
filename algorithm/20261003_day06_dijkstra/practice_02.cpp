#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = LLONG_MAX / 4;
vector<vector<pair<int,int>>> adj;
vector<ll> dijkstra(int N, int S, vector<int>& prev)
{
    vector<ll> dist;
    
    dist.assign(N+1, INF);
    prev.assign(N+1, -1);
    dist[S] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    pq.push({0,S});
    while(!pq.empty()) {
        auto [d, cur] = pq.top();
        pq.pop();
        if(d > dist[cur]) continue;
        for(auto [nxt, w] : adj[cur]) {
            auto nxt_dist = d + w;
            if(nxt_dist < dist[nxt]) {
                dist[nxt] = nxt_dist;
                prev[nxt] = cur;
                pq.push({nxt_dist,nxt});
            }
        }
    }
    return dist;
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    ll answer = 0;
    adj.clear();
    adj.assign(n+1, {});
    for(auto &n : fares) {
        adj[n[0]].push_back({n[1],n[2]});
        adj[n[1]].push_back({n[0],n[2]}); 
    }
    vector<int> prev;

    auto dist_s = dijkstra(n, s, prev);
    auto dist_a = dijkstra(n, a, prev);
    auto dist_b = dijkstra(n, b, prev);
    answer = 1e7;
    for (int i = 1; i <= n; i++) {
        // 도달할 수 없는 합승 지점은 제외
        if (dist_s[i] == INF ||
            dist_a[i] == INF ||
            dist_b[i] == INF) {
            continue;
        }

        long long tmp = dist_s[i] + dist_a[i] + dist_b[i];
        answer = min(answer, tmp);
    }
    return static_cast<int>(answer);
}
