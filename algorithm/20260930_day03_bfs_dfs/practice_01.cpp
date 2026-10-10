// Platform: Programmers
// Problem: 네트워크
// URL: https://school.programmers.co.kr/learn/courses/30/lessons/43162
// 먼저 브라우저 편집기에서 직접 작성하고, 풀이 후 이 파일에 기록한다.
// 입력 크기 / First Approach / Selected Algorithm / Time Complexity:
// 예상 Edge Case:

#include <bits/stdc++.h>

using namespace std;

bool visited[200] = {false,};
queue<int> q;
void bfs(int idx, int n, const vector<vector<int>>& computers) {
    while(!q.empty()) q.pop();
    q.push(idx);
    
    while(!q.empty()) {
        int i = q.front();
        q.pop();
        visited[i] = true;
        for(int j = 0; j < n; j++) {
            if(computers[i][j] == true && visited[j] == false){
                q.push(j);
            }
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
   
    for(int i = 0; i < 200; i++)
        visited[i] = false;
    
    for(int i = 0; i < n; i++) {
        if(visited[i]) continue;
        bfs(i, n, computers);
        
        answer++;
    }
    return answer;
}

// TODO: 공식 C++ 시작 코드에 맞는 함수 시그니처 또는 입력 처리를 직접 작성한다.
// 아래 main은 로컬 자리표시자다. 함수 제출 플랫폼에서는 온라인에 제출하지 않는다.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // TODO: 풀이 후 로컬 검증 코드 또는 표준 입출력 풀이를 작성한다.
    cerr << "TODO: not implemented\n";
    return 1;  // 빈 skeleton 실행을 정답 통과로 착각하지 않는다.
}
