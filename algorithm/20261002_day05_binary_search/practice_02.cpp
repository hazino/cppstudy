#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    long long lo = 1;
    long long hi = *max_element(stones.begin(), stones.end());
    
    while(lo <= hi) {
        bool success = true;
        long long mid = lo + (hi - lo) / 2;
        int cnt = 0;
        for(auto n : stones) {
            if(n <= mid) {
                cnt++;
            } else {
                cnt= 0;
            }
            if(k == cnt) {
                success = false;
                break;
            }
        }
        if(!success) {                     
            hi = mid-1; 
            answer = mid;
        } else {
            lo = mid+1; 
        }       
    }
    
    return answer;
}
