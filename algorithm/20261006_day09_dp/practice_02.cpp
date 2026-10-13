#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll solve(int n) {
    vector<ll> dp;
    dp.assign(n+1, 0);
    dp[0] = 1;
    for(int i = 1; i <=n; i++) {
        for(int j = 1; j <=2; j++) {
            if(i-j >= 0) 
                dp[i] += ((dp[i-j])%1234567);
        }
    }
    return dp[n] % 1234567;
}

long long solution(int n) {
    long long answer = 0;
    return solve(n);
}
