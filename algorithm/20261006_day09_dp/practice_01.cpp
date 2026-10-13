#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> v;
ll pivo(int n) {
    if(n <= 1) return n;
    if(v[n] != -1) return v[n];
    
    return v[n] = (pivo(n-1) + pivo(n-2)) % 1234567;
}
ll pivo_2(int n) {
    v[0] = 0, v[1] = 1;
    for(int i = 2; i<=n; i++) {
        v[i] = (v[i-1] + v[i-2]) % 1234567;
    }
    return v[n];
}
int solution(int n) {
    int answer = 0;
    v.assign(n+1, -1);
    answer =  pivo_2(n);
    return answer;
}
