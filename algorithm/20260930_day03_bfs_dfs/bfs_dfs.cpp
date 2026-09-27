// Day 3 - 09/30 : BFS / DFS
// Graph 표현(인접 리스트) → BFS / DFS → visited 관리 → Connected Component
//
// 입력 형식 (input.txt)
//   N M V        : 정점 수, 간선 수, 시작 정점
//   a b (M줄)    : 양방향 간선
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;    // 인접 리스트 : adj[u] = u와 연결된 정점들
vector<bool> visited;

// BFS : queue 사용. "넣을 때" visited 표시 → 같은 정점이 중복으로 들어가지 않는다
vector<int> bfs(int start) {
    vector<int> order;
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        order.push_back(cur);
        for (int nxt : adj[cur]) {
            if (visited[nxt]) continue;
            visited[nxt] = true;
            q.push(nxt);
        }
    }
    return order;
}

// DFS (재귀) : 가장 직관적. 깊이가 10^5 이상이면 스택 오버플로 주의
void dfsRecursive(int cur, vector<int>& order) {
    visited[cur] = true;
    order.push_back(cur);
    for (int nxt : adj[cur]) {
        if (!visited[nxt]) dfsRecursive(nxt, order);
    }
}

// DFS (stack) : 재귀 깊이 걱정 없음
// 재귀와 같은 방문 순서를 원하면 : 꺼낼 때 visited 체크 + 인접 정점을 역순으로 push
vector<int> dfsStack(int start) {
    vector<int> order;
    stack<int> st;
    st.push(start);
    while (!st.empty()) {
        int cur = st.top();
        st.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        order.push_back(cur);
        for (int i = (int)adj[cur].size() - 1; i >= 0; i--) {
            if (!visited[adj[cur][i]]) st.push(adj[cur][i]);
        }
    }
    return order;
}

// Connected Component : 방문 안 한 정점마다 탐색 시작 → 시작 횟수 = 컴포넌트 수
int countComponents() {
    fill(visited.begin(), visited.end(), false);
    int cnt = 0;
    for (int v = 1; v <= n; v++) {
        if (visited[v]) continue;
        bfs(v);
        cnt++;
    }
    return cnt;
}

void print(const string& name, const vector<int>& v) {
    cout << name << ": ";
    for (int x : v) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int start;
    cin >> n >> m >> start;
    adj.assign(n + 1, {});          // 정점 번호가 1부터 → n+1 크기
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);        // 방향 그래프면 이 줄 삭제
    }
    // 번호가 작은 정점부터 방문하라는 조건이 있을 때
    for (auto& e : adj) sort(e.begin(), e.end());

    visited.assign(n + 1, false);   // 탐색마다 visited 초기화 잊지 말 것
    vector<int> order;
    dfsRecursive(start, order);
    print("DFS(recursive)", order);

    visited.assign(n + 1, false);
    print("DFS(stack)    ", dfsStack(start));

    visited.assign(n + 1, false);
    print("BFS           ", bfs(start));

    cout << "components: " << countComponents() << '\n';
    return 0;
}
