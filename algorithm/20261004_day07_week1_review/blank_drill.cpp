// Day 7 - 10/04 : Week 1 Review - 빈칸 채우기 드릴
// 자료를 보지 않고 TODO를 채운다. 다 채우고 실행해서 모든 테스트가 PASS면 통과.
//   ../run.sh blank_drill.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// [1] 정렬 : 점수 내림차순, 같으면 이름 오름차순
void sortStudents(vector<pair<string, int>>& v) {
    // TODO
    (void)v;
}

// [2] BFS : 1번 정점에서 각 정점까지의 최단 간선 수 (도달 불가 -1)
vector<int> bfsDist(int n, const vector<vector<int>>& adj) {
    vector<int> dist(n + 1, -1);
    // TODO
    (void)adj;
    return dist;
}

// [3] DFS : 연결 요소 개수
int countComponents(int n, const vector<vector<int>>& adj) {
    // TODO
    (void)n;
    (void)adj;
    return 0;
}

// [4] Grid BFS : (0,0) → (R-1,C-1) 최단거리, '1'만 이동 가능, 시작칸 포함 칸 수 (불가 -1)
int mazeDist(const vector<string>& g) {
    // TODO
    (void)g;
    return 0;
}

// [5] lower_bound 직접 구현 (STL 사용 금지)
int myLowerBound(const vector<int>& a, int x) {
    // TODO
    (void)a;
    (void)x;
    return 0;
}

// [6] Dijkstra : 1번에서 각 정점까지 최단거리 (도달 불가 -1)
vector<ll> dijkstra(int n, const vector<vector<pair<int, int>>>& adj) {
    vector<ll> dist(n + 1, -1);
    // TODO
    (void)adj;
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
