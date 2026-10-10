#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    
    long long lo = 1;
    long long hi = 1LL*times[0] * n;
   
    while(lo <= hi){
        long long mid = lo +(hi-lo)/2;
        long long tmp = 0;
        for(auto nn : times) {
            tmp += mid / nn;
            if(tmp >=n) break;
        }
        if(n > tmp) {
            lo = mid+1;
        } else {
            hi = mid-1;
            answer = mid;
        }         
    }
    return answer;
}
