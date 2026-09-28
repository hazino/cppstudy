// Day 9 - 10/06 : Dynamic Programming I
// State 정의 → 점화식 → 초기값 → 계산 순서 (Top-down Memoization / Bottom-up)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 1) 피보나치 : 같은 부분 문제가 반복된다 → 저장해서 재사용
//    State : f(n) = n번째 피보나치 수
//    점화식 : f(n) = f(n-1) + f(n-2)

// Top-down (재귀 + 메모이제이션) : 점화식을 그대로 옮기기 쉽다
vector<ll> memo;
ll fibTopDown(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];  // 이미 계산됨
    return memo[n] = fibTopDown(n - 1) + fibTopDown(n - 2);
}

// Bottom-up (반복문) : 재귀 깊이 걱정 없음, 보통 더 빠르다
ll fibBottomUp(int n) {
    vector<ll> dp(max(2, n + 1));
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

// 2) 1로 만들기 : X를 (3으로 나누기 / 2로 나누기 / 1 빼기)로 1을 만드는 최소 연산 수
//    State : dp[i] = i를 1로 만드는 최소 연산 수
//    점화식 : dp[i] = min(dp[i-1], dp[i/2] (i%2==0), dp[i/3] (i%3==0)) + 1
//    참고 : "3으로 나눌 수 있으면 무조건 나눈다" 그리디는 반례 있음 (10 → 9 → 3 → 1)
int makeOne(int x) {
    vector<int> dp(x + 1, 0);
    for (int i = 2; i <= x; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
    }
    return dp[x];
}

// 3) 1, 2, 3 더하기 : n을 1, 2, 3의 합으로 나타내는 방법의 수 (순서 다르면 다른 방법)
//    State : dp[i] = i를 만드는 방법 수
//    점화식 : 마지막에 더한 수가 1, 2, 3 중 하나 → dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
ll countWays(int n) {
    vector<ll> dp(max(4, n + 1), 0);
    dp[0] = 1;      // 아무것도 안 더하는 방법 1가지
    for (int i = 1; i <= n; i++)
        for (int k = 1; k <= 3; k++)
            if (i - k >= 0) dp[i] += dp[i - k];
    return dp[n];
}

// 4) 계단 오르기 : 연속 3칸 밟기 금지, 마지막 칸 반드시 밟기, 점수 최대
//    State 하나로 부족 → 상태에 "정보를 추가"하는 연습
//    dp[i][1] = i번째를 밟았고, 직전 칸(i-1)은 안 밟음 (연속 1칸째)
//    dp[i][2] = i번째를 밟았고, 직전 칸(i-1)도 밟음 (연속 2칸째)
int stairs(const vector<int>& s) {  // s[1..n]
    int n = (int)s.size() - 1;
    vector<array<int, 3>> dp(n + 1, {0, 0, 0});
    dp[1][1] = s[1];
    for (int i = 2; i <= n; i++) {
        dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + s[i];
        dp[i][2] = dp[i - 1][1] + s[i];
    }
    return max(dp[n][1], dp[n][2]);
}

int main() {
    int n = 50;
    memo.assign(n + 1, -1);
    cout << "fib(50) top-down  = " << fibTopDown(n) << '\n';
    cout << "fib(50) bottom-up = " << fibBottomUp(n) << '\n';   // 12586269025 (int 초과!)
    cout << "makeOne(10) = " << makeOne(10) << '\n';            // 3
    cout << "countWays(4) = " << countWays(4) << ", countWays(7) = " << countWays(7) << '\n';  // 7, 44
    cout << "stairs = " << stairs({0, 10, 20, 15, 25, 10, 20}) << '\n';  // 75
    return 0;
}
