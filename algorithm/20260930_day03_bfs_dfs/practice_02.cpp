// Platform: Programmers
// Problem: 타겟 넘버
// URL: https://school.programmers.co.kr/learn/courses/30/lessons/43165
// 먼저 브라우저 편집기에서 직접 작성하고, 풀이 후 이 파일에 기록한다.
// 입력 크기 / First Approach / Selected Algorithm / Time Complexity:
// 예상 Edge Case:
#include <bits/stdc++.h>

using namespace std;

int dfs(int idx, int answer, const vector<int>& numbers, int sum, int target)
{
    if(idx+1 == numbers.size()){
        if(target == sum) {
            answer++;
        }
        return answer;
    }
    answer = dfs(idx+1, answer, numbers, sum+numbers[idx+1], target);
    answer = dfs(idx+1, answer, numbers, sum-numbers[idx+1], target);
    return answer;
}
int solution(vector<int> numbers, int target) {
    int answer, answer1, answer2 = 0;

    answer1 = dfs(0, 0, numbers, numbers[0], target);
    answer2 = dfs(0, 0, numbers, -numbers[0], target);
    answer = answer1 + answer2;
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
