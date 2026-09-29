// Platform: Programmers
// Problem: K번째수
// URL: https://school.programmers.co.kr/learn/courses/30/lessons/42748
// 먼저 브라우저 편집기에서 직접 작성하고, 풀이 후 이 파일에 기록한다.
// 입력 크기 / First Approach / Selected Algorithm / Time Complexity:
// 예상 Edge Case:
#include <csignal>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string test(string s)
{
    stringstream ss(s);
    string answer = "";
    string word;
    while(ss >> word)
    {
        int i = 0;
        for(auto& n : word )
        {
            if(i%2 == 0)
                n = toupper(n);
            answer.push_back(n);
            i++;
        }
        answer.push_back(' ');
    }
    return answer;
}

string solution(string s)
{
    string answer = "";
    int idx = 0;
    for(auto iter = s.begin(); iter != s.end(); iter++)
    {
        if(*iter == ' ') {
            idx = 0;
        } else {
            if(idx++%2 == 0)  {
                *iter = toupper(*iter);
            } else {
                *iter = tolower(*iter);
            }
        }
        answer.push_back(*iter);
    }
    return answer;
}

// TODO: 공식 C++ 시작 코드에 맞는 함수 시그니처 또는 입력 처리를 직접 작성한다.
// 아래 main은 로컬 자리표시자다. 함수 제출 플랫폼에서는 온라인에 제출하지 않는다.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // TODO: 풀이 후 로컬 검증 코드 또는 표준 입출력 풀이를 작성한다.
    // cerr << "TODO: not implemented\n";
    //
    //
    string s;
    getline(cin, s);
    cout << solution(s);

    return 1;  // 빈 skeleton 실행을 정답 통과로 착각하지 않는다.
}
