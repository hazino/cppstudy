// Day 6 - 10/03 : Graph / Dijkstra
// Start → Priority Queue → Minimum Distance Node → Edge Relaxation → Distance Update
//
// 입력 형식 (input.txt)
//   V E          : 정점 수, 간선 수
//   S T          : 시작, 도착
//   u v w (E줄)  : u → v 가중치 w (단방향)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = LLONG_MAX / 4;   // 더해도 overflow 나지 않을 만큼 큰 값

int V, E;
vector<vector<pair<int, int>>> adj;     // adj[u] = {(v, w), ...}

// 반환 : dist 배열, prev에는 최단경로 역추적용 직전 정점
vector<ll> dijkstra(int start, vector<int>& prev) {
    vector<ll> dist(V + 1, INF);
    prev.assign(V + 1, -1);

    // (거리, 정점) 최소 힙
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, cur] = pq.top();       // 현재 가장 가까운 정점
        pq.pop();
        if (d > dist[cur]) continue;    // 이미 더 짧은 거리로 처리됨 (lazy deletion) ← 핵심

        for (auto [nxt, w] : adj[cur]) {
            ll nd = d + w;
            if (nd < dist[nxt]) {       // Edge Relaxation
                dist[nxt] = nd;         // Distance Update
                prev[nxt] = cur;
                pq.push({nd, nxt});
            }
        }
    }
    return dist;
}

vector<int> buildPath(int target, const vector<int>& prev) {
    vector<int> path;
    for (int v = target; v != -1; v = prev[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int S, T;
    cin >> V >> E >> S >> T;
    adj.assign(V + 1, {});
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // 양방향이면 : adj[v].push_back({u, w});
    }

    vector<int> prev;
    vector<ll> dist = dijkstra(S, prev);

    for (int v = 1; v <= V; v++) {
        cout << "dist[" << v << "] = ";
        if (dist[v] == INF) cout << "INF";
        else cout << dist[v];
        cout << '\n';
    }

    if (dist[T] == INF) {
        cout << "no path\n";
    } else {
        cout << "path " << S << "->" << T << ":";
        for (int v : buildPath(T, prev)) cout << ' ' << v;
        cout << " (cost " << dist[T] << ")\n";
    }
    return 0;
}
