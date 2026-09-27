// Day 10 - 10/07 : Dynamic Programming II
// 1D DP / 2D DP / 선택-비선택 / 누적 상태
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 1) 0/1 Knapsack (선택 / 비선택)
//    State : dp[i][w] = 앞의 i개 물건만 고려, 무게 합 w 이하일 때 최대 가치
//    Transition : i번째를 안 넣는다 → dp[i-1][w]
//                 i번째를 넣는다   → dp[i-1][w - wt[i]] + val[i]
int knapsack2D(const vector<int>& wt, const vector<int>& val, int W) {
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w];
            if (w >= wt[i - 1]) dp[i][w] = max(dp[i][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[n][W];
}

// 1차원 최적화 : w를 "뒤에서부터" 돌아야 같은 물건을 두 번 넣지 않는다
// (앞에서부터 돌면 무한 배낭 = 같은 물건 여러 번 사용 가능)
int knapsack1D(const vector<int>& wt, const vector<int>& val, int W) {
    vector<int> dp(W + 1, 0);
    for (size_t i = 0; i < wt.size(); i++)
        for (int w = W; w >= wt[i]; w--)
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
    return dp[W];
}

// 2) RGB 거리 (2D DP) : 이웃 집과 같은 색 금지, 비용 최소
//    State : dp[i][c] = i번째 집을 색 c로 칠했을 때 0~i번째 최소 비용
int rgb(const vector<array<int, 3>>& cost) {
    int n = cost.size();
    vector<array<int, 3>> dp(n);
    dp[0] = cost[0];
    for (int i = 1; i < n; i++)
        for (int c = 0; c < 3; c++)
            dp[i][c] = min(dp[i - 1][(c + 1) % 3], dp[i - 1][(c + 2) % 3]) + cost[i][c];
    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
}

// 3) LIS (가장 긴 증가하는 부분 수열)
//    O(N^2) : dp[i] = i번째 원소로 "끝나는" LIS 길이 → 답은 max(dp)
int lisN2(const vector<int>& a) {
    int n = a.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
    return *max_element(dp.begin(), dp.end());
}

//    O(N log N) : tail[k] = 길이 k+1인 증가 수열의 마지막 값 중 최솟값
int lisNlogN(const vector<int>& a) {
    vector<int> tail;
    for (int x : a) {
        auto it = lower_bound(tail.begin(), tail.end(), x);  // 비감소 LIS면 upper_bound
        if (it == tail.end()) tail.push_back(x);
        else *it = x;
    }
    return tail.size();
}

// 4) LCS (2D, 두 문자열)
//    State : dp[i][j] = a의 앞 i글자, b의 앞 j글자의 LCS 길이
int lcs(const string& a, const string& b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = (a[i - 1] == b[j - 1]) ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
    return dp[n][m];
}

// 5) 누적 상태 : 2D 누적합 → 임의 직사각형 합을 O(1)
//    S[i][j] = (1,1) ~ (i,j) 합
ll rectSum(const vector<vector<ll>>& S, int x1, int y1, int x2, int y2) {
    return S[x2][y2] - S[x1 - 1][y2] - S[x2][y1 - 1] + S[x1 - 1][y1 - 1];
}

int main() {
    vector<int> wt = {6, 4, 3, 5}, val = {13, 8, 6, 12};
    cout << "knapsack2D = " << knapsack2D(wt, val, 7) << ", knapsack1D = " << knapsack1D(wt, val, 7) << '\n';  // 14

    cout << "rgb = " << rgb({{26, 40, 83}, {49, 60, 57}, {13, 89, 99}}) << '\n';  // 96

    vector<int> a = {10, 20, 10, 30, 20, 50};
    cout << "LIS O(N^2) = " << lisN2(a) << ", O(NlogN) = " << lisNlogN(a) << '\n';  // 4

    cout << "LCS = " << lcs("ACAYKP", "CAPCAK") << '\n';  // 4

    vector<vector<int>> g = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}, {4, 5, 6, 7}};
    int n = g.size();
    vector<vector<ll>> S(n + 1, vector<ll>(n + 1, 0));  // 1-indexed, 0행/0열은 0 (경계 처리 불필요)
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + g[i - 1][j - 1];
    cout << "rectSum (2,2)~(3,4) = " << rectSum(S, 2, 2, 3, 4) << '\n';  // 27
    return 0;
}
