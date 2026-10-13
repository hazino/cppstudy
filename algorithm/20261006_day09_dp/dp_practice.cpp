#include <bits/stdc++.h>

using ll = long long;
const ll INF = LLONG_MAX / 4;
using namespace std;

ll solve_1(const vector<int>& s) {
    int sz = s.size();
    vector<array<int, 3>> dp(sz, {0,0,0});
    dp[1][1] = s[1];
    for(int i = 2; i <=sz; i++) {
        dp[i][1] = max(dp[i-2][1], dp[i-2][2])+s[i];
        dp[i][2] = dp[i-1][1] + s[i];
    }
    return max(dp[sz][1], dp[sz][2]);
}

int makeOne(int x) {
    vector<int> dp(x+1, 0);
    for(int i = 2; i<=x; i++) {
        dp[i] = dp[i-1] + 1;
        if(i % 2 == 0) dp[i] = min(dp[i], dp[i/2] + 1);
        if(i % 3 == 0) dp[i] = min(dp[i], dp[i/3] + 1);
    }
    return dp[x];
}
