#include <bits/stdc++.h>

using namespace std;

vector<int> uniform;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    uniform.clear();
    uniform.assign(n+2, 1);
    
    for(auto n : reserve)
    {
        uniform[n] = 2;
        
    }
    for (auto n : lost) {
        uniform[n]--;
    }
    for(int i =1 ; i<= n; i++)
    {
         if(uniform[i]>= 1) {

              answer++;
              uniform[i]--;
         } else {
              if(i > 1 && uniform[i-1] > 0)
              {
                   answer++;
              }
              else if(uniform[i+1]> 1) 
              { answer++;
                 uniform[i+1]--;
              }
         }
    }
    return answer;

}
