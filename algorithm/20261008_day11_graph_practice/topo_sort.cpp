// Day 11 - 10/08 : Graph 심화 - Topological Sort / DAG
//
// 입력 형식 (input.txt)
//   N M                : 작업 수, 선행 관계 수
//   t1 t2 ... tN       : 각 작업의 소요 시간
//   a b (M줄)          : a를 끝내야 b를 시작할 수 있다 (a → b)
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> indegree;   // 나에게 들어오는 간선 수 = 아직 안 끝난 선행 작업 수

// Kahn 알고리즘 (BFS 기반)
// 1. 진입차수 0인 정점을 모두 큐에
// 2. 꺼낸 정점을 결과에 추가하고, 나가는 간선을 제거 (진입차수 감소)
// 3. 진입차수가 0이 된 정점을 큐에
// 결과 크기 < N 이면 사이클 존재 (DAG가 아님)
vector<int> topoSort() {
    vector<int> deg = indegree;     // 원본 보존
    queue<int> q;                   // 번호 작은 것 우선이면 priority_queue<int, vector<int>, greater<>>
    for (int v = 1; v <= n; v++)
        if (deg[v] == 0) q.push(v);

    vector<int> order;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        order.push_back(cur);
        for (int nxt : adj[cur])
            if (--deg[nxt] == 0) q.push(nxt);
    }
    return order;   // order.size() != n 이면 사이클
}

// DAG 응용 : 모든 작업을 끝내는 최소 시간 (선행 작업이 끝나야 시작, 병렬 가능)
// finish[v] = max(finish[선행 작업]) + time[v]  → 위상 순서대로 계산하면 DP
int minTotalTime(const vector<int>& time) {
    vector<int> order = topoSort();
    vector<int> start(n + 1, 0);    // start[v] = v를 시작할 수 있는 가장 빠른 시각
    vector<int> finish(n + 1, 0);
    for (int cur : order) {         // 위상 순서 → cur의 선행 작업은 이미 모두 계산됨
        finish[cur] = start[cur] + time[cur];
        for (int nxt : adj[cur]) start[nxt] = max(start[nxt], finish[cur]);
    }
    return *max_element(finish.begin(), finish.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<int> time(n + 1);
    for (int i = 1; i <= n; i++) cin >> time[i];

    adj.assign(n + 1, {});
    indegree.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);    // 방향 그래프
        indegree[b]++;
    }

    vector<int> order = topoSort();
    if ((int)order.size() != n) {
        cout << "cycle detected\n";
        return 0;
    }
    cout << "topological order:";
    for (int v : order) cout << ' ' << v;
    cout << '\n';
    cout << "min total time: " << minTotalTime(time) << '\n';
    return 0;
}
