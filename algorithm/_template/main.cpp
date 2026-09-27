// 코딩테스트 기본 템플릿
// 새 문제를 풀 때 이 파일을 복사해서 시작한다.
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int INF = 1e9;
const ll LINF = 1e18;

// 상하좌우 (Grid 문제용)
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    // TODO: 풀이

    cout << '\n';   // endl 대신 '\n' (flush 비용 없음)
    return 0;
}
