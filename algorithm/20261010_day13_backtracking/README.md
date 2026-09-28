# Day 13 — 2026-10-10: 완전탐색 / Backtracking

## 오늘의 목표

오늘의 주제를 설명하고 스스로 구현한다. 예제 읽기는 20분 이내, 문제 풀이를 우선한다.

## 핵심 개념

permutation, combination, 선택과 복구.

## No IntelliSense Drill

순열·조합을 각각 직접 작성하고 종료 조건 및 상태 복구를 확인한다.

## 온라인 문제

| Platform | Problem Name / Problem URL | Difficulty | Recommended Time | 핵심 학습 목표 | 파일 |
|---|---|---|---|---|---|
| Programmers | [최소직사각형](https://school.programmers.co.kr/learn/courses/30/lessons/86491) | 기본 | 40분 | 조건 분석과 독립 구현 | `practice_01.cpp` |
| Programmers | [피로도](https://school.programmers.co.kr/learn/courses/30/lessons/87946) | 실전 | 45분 | 조건 분석과 독립 구현 | `practice_02.cpp` |

Difficulty의 기본·실전·도전은 이 계획의 학습 기준이며 공식 등급이 아니다. CodeTree의 Easy/Medium/Hard는 해당 페이지 표기다.

No IntelliSense 시간에 순열·조합·기본 Backtracking을 모두 작성한다. N-Queen은 선택이며 고급 탐색은 추가하지 않는다.

[플랫폼별 제출·로컬 검증 방법](../README.md#플랫폼별-제출과-로컬-검증)을 따른다. 온라인 문제의 전체 지문은 저장소에 복사하지 않는다.

## 권장 시간

20분 No IntelliSense 손코딩 → 40분 기본 문제 → 45분 실전 문제 → 15분 오답·problem_log 기록 (총 120분).

## 자주 하는 실수

used 복구 누락, 중복 출력, 조합 시작 인덱스.

## 완료 체크리스트

- [ ] 자동완성·AI를 끄고 자료 없이 Drill을 작성했다.
- [ ] 브라우저 에디터에서 첫 풀이를 작성했다.
- [ ] 학습 후에만 AI 리뷰·복잡도 검증·다른 풀이 비교·오답 분석을 활용했다.
- [ ] 문제를 읽고 3~5분 안에 첫 접근과 복잡도를 적었다.
- [ ] 예제와 직접 만든 경계 사례를 확인했다.
- [ ] 결과·실패 원인·재도전 날짜를 [problem_log.md](../problem_log.md)에 기록했다.

[공통 풀이 원칙](../README.md#문제-풀이-원칙)을 따른다.

---

<details>
<summary>풀이 후 확인할 기존 개념 노트</summary>

## 기존 개념 노트

```bash
../run.sh backtracking.cpp
```

## Backtracking 기본 Template
```cpp
void dfs(int depth /* 상태 */) {
    if (종료 조건) { 결과 처리; return; }
    for (선택지 : 후보들) {
        if (불가능) continue;   // Pruning
        선택;                   // 상태 변경
        dfs(depth + 1);
        선택 취소;              // 상태 복구
    }
}
```

## 경우의 수 감각 (1초 ≈ 10^8 연산)
| 탐색 | 개수 | 가능한 N |
|---|---|---|
| 순열 N! | 10! ≈ 3.6×10^6 | N ≤ 10 |
| 부분 집합 2^N | 2^20 ≈ 10^6 | N ≤ 20 |
| 조합 nCr | 20C10 ≈ 1.8×10^5 | N ≤ 25 정도 |

## 체크
- [ ] 순열(used 배열) / 조합(start 인덱스) 구분
- [ ] 재귀 후 상태 복구 빠뜨리지 않기
- [ ] 전역 변수 초기화 (테스트 케이스 여러 개)
- [ ] `next_permutation`은 정렬된 상태에서 시작


</details>
