// Day 20 - 시험 전날 / D-2 : Final Review 템플릿 모음
// 새 알고리즘 학습 X. 아래 템플릿을 한 번씩 손으로 다시 써 본다.
//   ../run.sh templates.cpp   (main에서 각 템플릿을 간단히 검증)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1e9;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

// ---------------------------------------------------------------- Sort Comparator
// a가 b보다 앞에 와야 하면 true. <= 금지
bool cmpDescThenAsc(const pii& a, const pii& b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

// ---------------------------------------------------------------- Priority Queue
// 최대 힙 : priority_queue<int>
// 최소 힙 : priority_queue<int, vector<int>, greater<int>>
// pair 최소 힙 : priority_queue<pii, vector<pii>, greater<>>

// ---------------------------------------------------------------- BFS (그래프)
vector<int> bfs(int start, const vector<vector<int>>& adj) {
    vector<int> dist(adj.size(), -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
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

// ---------------------------------------------------------------- DFS (재귀)
void dfs(int cur, const vector<vector<int>>& adj, vector<bool>& vis) {
    vis[cur] = true;
    for (int nxt : adj[cur])
        if (!vis[nxt]) dfs(nxt, adj, vis);
}

// ---------------------------------------------------------------- Grid Search (BFS)
int gridBfs(const vector<string>& g, int sx, int sy, int ex, int ey) {
    int R = g.size(), C = g[0].size();
    vector<vector<int>> dist(R, vector<int>(C, -1));
    queue<pii> q;
    dist[sx][sy] = 0;
    q.push({sx, sy});
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (g[nx][ny] == '#' || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    return dist[ex][ey];
}

// ---------------------------------------------------------------- Dijkstra
vector<ll> dijkstra(int start, const vector<vector<pii>>& adj) {   // adj[u] = {(v, w)}
    const ll LINF = LLONG_MAX / 4;
    vector<ll> dist(adj.size(), LINF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});
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
    return dist;
}

// ---------------------------------------------------------------- Binary Search
// lower_bound : x 이상 첫 위치 / upper_bound : x 초과 첫 위치
// Parameter Search : ok(mid)가 T T T F F 일 때 마지막 T
ll lastTrue(ll lo, ll hi, const function<bool(ll)>& ok) {
    ll ans = lo - 1;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (ok(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

// ---------------------------------------------------------------- Topological Sort
// 선택 참고: 이번 필수 복습 범위에서는 제외한다.
vector<int> topoSort(int n, const vector<vector<int>>& adj) {   // 1-indexed
    vector<int> indeg(n + 1, 0);
    for (int u = 1; u <= n; u++)
        for (int v : adj[u]) indeg[v]++;
    queue<int> q;
    for (int v = 1; v <= n; v++)
        if (indeg[v] == 0) q.push(v);
    vector<int> order;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        order.push_back(cur);
        for (int nxt : adj[cur])
            if (--indeg[nxt] == 0) q.push(nxt);
    }
    return order;   // size < n → 사이클
}

// ---------------------------------------------------------------- DP 기본 (0/1 배낭)
// 선택 참고: 기본 State/점화식 복습은 Day 9를 우선한다.
int knapsack(const vector<int>& wt, const vector<int>& val, int W) {
    vector<int> dp(W + 1, 0);
    for (size_t i = 0; i < wt.size(); i++)
        for (int w = W; w >= wt[i]; w--)    // 역순!
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
    return dp[W];
}

// ---------------------------------------------------------------- Backtracking (조합)
void combi(int n, int r, int start, vector<int>& cur, vector<vector<int>>& out) {
    if ((int)cur.size() == r) {
        out.push_back(cur);
        return;
    }
    for (int i = start; i <= n; i++) {
        cur.push_back(i);
        combi(n, r, i + 1, cur, out);
        cur.pop_back();
    }
}

// ---------------------------------------------------------------- Prefix Sum
// s[i] = 앞의 i개 원소 합. 구간 [l,r] (1-based)의 합은 s[r]-s[l-1].
vector<ll> prefixSum(const vector<ll>& a) {
    vector<ll> s(a.size() + 1, 0);
    for (size_t i = 0; i < a.size(); ++i) s[i + 1] = s[i] + a[i];
    return s;
}

// lower_bound 직접 구현: 정렬된 배열, 반환 범위 [0, a.size()].
int lowerBound(const vector<int>& a, int x) {
    int lo = 0, hi = static_cast<int>(a.size());
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] < x) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

// ================================================================ 검증
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ok = 0, total = 0;
    auto check = [&](const string& name, bool cond) {
        total++;
        ok += cond;
        cout << (cond ? "[PASS] " : "[FAIL] ") << name << '\n';
    };

    // 기본 STL 회상: 삽입/조회/삭제를 직접 작성한 뒤 비교한다.
    vector<pii> pairs;
    pairs.push_back({2, 7});
    check("vector / pair", pairs.front().first == 2 && pairs.front().second == 7);
    stack<int> st;
    st.push(3); st.push(8); st.pop();
    check("stack", st.top() == 3);
    map<string, int> counts;
    ++counts["apple"];
    ++counts["apple"];
    check("map", counts.at("apple") == 2 && counts.find("pear") == counts.end());
    set<int> uniqueValues = {3, 1, 3};
    uniqueValues.erase(3);
    check("set", uniqueValues.size() == 1 && uniqueValues.count(1) == 1);

    vector<pii> v = {{1, 2}, {3, 1}, {3, 0}};
    sort(v.begin(), v.end(), cmpDescThenAsc);
    check("sort", v == vector<pii>{{3, 0}, {3, 1}, {1, 2}});
    sort(v.begin(), v.end(), [](const pii& a, const pii& b) {
        return a < b;
    });
    check("sort lambda", v == vector<pii>{{1, 2}, {3, 0}, {3, 1}});
    queue<int> q;
    q.push(2); q.push(1); q.pop();
    check("queue", q.front() == 1);
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(2); pq.push(1);
    check("priority_queue", pq.top() == 1);
    const auto sums = prefixSum({2000000000LL, 2000000000LL, -3});
    check("prefix sum", sums[3] - sums[0] == 3999999997LL);
    check("prefix sum single", sums[3] - sums[2] == -3);
    check("lower_bound duplicate", lowerBound({1, 3, 3, 5}, 3) == 1);
    check("lower_bound end", lowerBound({1, 3}, 4) == 2);
    check("lower_bound empty", lowerBound({}, 1) == 0);

    vector<vector<int>> g(5);
    g[1] = {2, 3};
    g[2] = {4};
    g[3] = {4};
    check("bfs", bfs(1, g)[4] == 2);
    vector<bool> vis(5, false);
    dfs(1, g, vis);
    check("dfs", vis[4] && !vis[0]);
    check("topo", topoSort(4, g).size() == 4);

    check("grid", gridBfs({"..#", "..#", "..."}, 0, 0, 2, 2) == 4);

    vector<vector<pii>> w(4);
    w[1] = {{2, 5}, {3, 1}};
    w[3] = {{2, 1}};
    check("dijkstra", dijkstra(1, w)[2] == 2);

    check("parameter search", lastTrue(0, 100, [](ll x) { return x * x <= 50; }) == 7);
    check("knapsack", knapsack({6, 4, 3, 5}, {13, 8, 6, 12}, 7) == 14);

    vector<int> cur;
    vector<vector<int>> out;
    combi(5, 3, 1, cur, out);
    check("combination", out.size() == 10);

    cout << ok << " / " << total << " passed\n";
    return ok == total ? 0 : 1;
}
