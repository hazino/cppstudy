// Day 7 - 10/04 : Week 1 Review - 빈칸 드릴 정답 예시
// blank_drill.cpp를 직접 채운 뒤에 비교용으로만 본다.
//   ../run.sh blank_drill_answer.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// [1] 정렬 : 점수 내림차순, 같으면 이름 오름차순
void sortStudents(vector<pair<string, int>>& v) {
    sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });
}

// [2] BFS : 1번 정점에서 각 정점까지의 최단 간선 수 (도달 불가 -1)
vector<int> bfsDist(int n, const vector<vector<int>>& adj) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nxt : adj[cur]) {
            if (dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
    return dist;
}

// [3] DFS : 연결 요소 개수
void dfs(int cur, const vector<vector<int>>& adj, vector<bool>& vis) {
    vis[cur] = true;
    for (int nxt : adj[cur])
        if (!vis[nxt]) dfs(nxt, adj, vis);
}

int countComponents(int n, const vector<vector<int>>& adj) {
    vector<bool> vis(n + 1, false);
    int cnt = 0;
    for (int v = 1; v <= n; v++) {
        if (vis[v]) continue;
        dfs(v, adj, vis);
        cnt++;
    }
    return cnt;
}

// [4] Grid BFS : (0,0) → (R-1,C-1) 최단거리, '1'만 이동 가능, 시작칸 포함 칸 수 (불가 -1)
int mazeDist(const vector<string>& g) {
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};
    int R = g.size(), C = g[0].size();
    vector<vector<int>> dist(R, vector<int>(C, -1));
    queue<pair<int, int>> q;
    dist[0][0] = 1;
    q.push({0, 0});
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (g[nx][ny] != '1' || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    return dist[R - 1][C - 1];
}

// [5] lower_bound 직접 구현 (STL 사용 금지)
int myLowerBound(const vector<int>& a, int x) {
    int lo = 0, hi = a.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] >= x) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

// [6] Dijkstra : 1번에서 각 정점까지 최단거리 (도달 불가 -1)
vector<ll> dijkstra(int n, const vector<vector<pair<int, int>>>& adj) {
    const ll INF = LLONG_MAX / 4;
    vector<ll> dist(n + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [d, cur] = pq.top();
        pq.pop();
        if (d > dist[cur]) continue;
        for (auto [nxt, w] : adj[cur]) {
            if (d + w < dist[nxt]) {
                dist[nxt] = d + w;
                pq.push({dist[nxt], nxt});
            }
        }
    }
    for (auto& x : dist)
        if (x == INF) x = -1;
    return dist;
}

// ================= 테스트 (수정 X) =================
int passed = 0, total = 0;
template <typename T>
void check(const string& name, const T& got, const T& expected) {
    total++;
    if (got == expected) {
        passed++;
        cout << "[PASS] " << name << '\n';
    } else {
        cout << "[FAIL] " << name << '\n';
    }
}

int main() {
    vector<pair<string, int>> st = {{"kim", 80}, {"lee", 95}, {"ahn", 80}, {"park", 70}};
    sortStudents(st);
    check("sort", st, vector<pair<string, int>>{{"lee", 95}, {"ahn", 80}, {"kim", 80}, {"park", 70}});

    vector<vector<int>> g(7);
    auto addEdge = [&](int a, int b) { g[a].push_back(b); g[b].push_back(a); };
    addEdge(1, 2); addEdge(2, 3); addEdge(1, 4); addEdge(5, 6);
    check("bfs", bfsDist(6, g), vector<int>{-1, 0, 1, 2, 1, -1, -1});
    check("components", countComponents(6, g), 2);

    check("maze", mazeDist({"101111", "101010", "101011", "111011"}), 15);
    check("maze blocked", mazeDist({"10", "01"}), -1);

    vector<int> a = {1, 2, 4, 4, 4, 7};
    check("lower_bound 4", myLowerBound(a, 4), 2);
    check("lower_bound 5", myLowerBound(a, 5), 5);
    check("lower_bound 9", myLowerBound(a, 9), 6);

    vector<vector<pair<int, int>>> w(5);
    w[1] = {{2, 4}, {3, 1}};
    w[3] = {{2, 2}};
    w[2] = {{4, 5}};
    check("dijkstra", dijkstra(4, w), vector<ll>{-1, 0, 3, 1, 8});

    cout << passed << " / " << total << " passed\n";
    return 0;
}
