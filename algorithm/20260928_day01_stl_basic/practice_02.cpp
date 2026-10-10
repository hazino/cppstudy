// 2026-10-05: 기본 링크에 사용자 404 신고가 있어 접근 시 확인 필요.
// 대체: 문자열 내림차순으로 배치하기 — https://school.programmers.co.kr/learn/courses/30/lessons/12917
// 대체 선택 시 아래 Problem / URL을 갱신하고 같은 파일을 사용한다.
// Platform: Programmers
// Problem: 이상한 문자 만들기
// URL: https://school.programmers.co.kr/learn/courses/30/lessons/12930
// 먼저 브라우저 편집기에서 직접 작성하고, 풀이 후 이 파일에 기록한다.
// 입력 크기 / First Approach / Selected Algorithm / Time Complexity:
// 예상 Edge Case:
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(auto n : commands) {
        int i = n[0]-1;
        int j = n[1]-1;
        int k = n[2]-1;
        vector<int> tmp;
        for(int c = i; c <= j; c++)
        {
            tmp.push_back(array[c]);
        }        
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[k]);
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
