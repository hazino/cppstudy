#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int sz = sequence.size();
    vector<ll>dp (sz+1, 0);
    int jdx = 1e7;
    int idx = 1e7;
    int tail = -1;
    int head = 0;
    int le = 1e7;
    dp[head] = sequence[0];

    while(head < sz) {        
        int span = head-tail;
        ll cal = dp[head];
        if(tail >= 0) {
            cal  -= dp[tail];            
        }         
        if(cal > k) {
            if(span == 1) {
                head++, tail++;
                dp[head] += (dp[head-1] + sequence[head]);
            } else {
                tail++;                
            }            
        } else if (cal == k) {
            if(span < le  ||  (span == le && (tail+1) < idx)) {
                idx = tail + 1;
                jdx = head;
                le = span;
            }
            head++, tail++;
            dp[head] += (dp[head-1] + sequence[head]);            
        } else {
            head++;
            dp[head] += (dp[head-1] + sequence[head]);           
        }  
    }
             
    answer.push_back(idx);
    answer.push_back(jdx);
    return answer;
}
