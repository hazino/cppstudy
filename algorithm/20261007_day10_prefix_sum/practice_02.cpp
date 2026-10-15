#include <bits/stdc++.h>
using namespace std;

using ll = long long;

long long solution(vector<int> sequence) {
    long long answer = 0;
    int i = 0;   
    int sz = sequence.size();
    
    for(auto& n : sequence) {
        i %=2;
        if(i++ == 1) {
            n *= -1;
        }
    }
    ll prefix = 0;
    ll minPrefix = 0;
    for(auto n : sequence) {
        prefix += n;
        answer = max(answer, prefix - minPrefix);
        minPrefix = min(minPrefix, prefix);
    }  
    
    for(auto& n : sequence) {
        n *= -1;
    }
    prefix = 0;
    minPrefix = 0;
    for(auto n : sequence) {
        prefix += n;
        answer = max(answer, prefix - minPrefix);
        minPrefix = min(minPrefix, prefix);
    }  
    
    return answer;
}
