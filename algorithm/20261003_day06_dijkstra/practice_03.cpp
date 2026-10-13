#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, vector<vector<int>> paths,
                     vector<int> gates, vector<int> summits) {
    // adj[u] = {다음 정점, 이동 비용}
    vector<vector<pair<int, int>>> adj(n + 1);

    for (const auto& path : paths) {
        int u = path[0];
        int v = path[1];
        int w = path[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<bool> isGate(n + 1, false);
    vector<bool> isSummit(n + 1, false);

    for (int gate : gates) isGate[gate] = true;
    for (int summit : summits) isSummit[summit] = true;

    // intensity[v]: 모든 출입구 중 하나에서 v까지의 최소 intensity
    vector<int> intensity(n + 1, INT_MAX);

    // {intensity, 정점} — 작은 intensity부터 꺼냄
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<>> pq;

    // 모든 출입구에서 동시에 시작
    for (int gate : gates) {
        intensity[gate] = 0;
        pq.push({0, gate});
    }

    while (!pq.empty()) {
        auto [d, cur] = pq.top();
        pq.pop();

        // 이미 더 좋은 값으로 갱신된 항목은 무시
        if (d > intensity[cur]) continue;

        // 산봉우리는 도착만 하고 통과하지 않음
        if (isSummit[cur]) continue;

        for (auto [nxt, w] : adj[cur]) {
            // 출입구를 중간에 경유하지 않음
            if (isGate[nxt]) continue;

            // 총합이 아니라, 지나온 간선 비용의 최댓값
            int nextIntensity = max(d, w);

            if (nextIntensity < intensity[nxt]) {
                intensity[nxt] = nextIntensity;
                pq.push({nextIntensity, nxt});
            }
        }
    }

    int bestSummit = INT_MAX;
    int bestIntensity = INT_MAX;

    for (int summit : summits) {
        if (intensity[summit] < bestIntensity ||
            (intensity[summit] == bestIntensity &&
             summit < bestSummit)) {
            bestIntensity = intensity[summit];
            bestSummit = summit;
        }
    }

    return {bestSummit, bestIntensity};
}
