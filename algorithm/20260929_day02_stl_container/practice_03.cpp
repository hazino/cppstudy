#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    bool solved = false;
    auto greater =[](int a, int b) {return a > b; };
    priority_queue <int, vector<int>, decltype(greater)> pq; 
    
    for(auto n : scoville){
        pq.push(n);
    }
    
    while(true) {
        if(pq.top() >= K){
            solved = true;
            break;
        }
        if(pq.size() < 2)
            break;
        int tmp1 = pq.top();
        pq.pop();
        int tmp2 = pq.top();
        pq.pop();
        int tmp3 = tmp1 + ( tmp2*2);
        
        pq.push(tmp3);
        answer++;
    }
    if(!solved) answer = -1;
    return answer;
}
