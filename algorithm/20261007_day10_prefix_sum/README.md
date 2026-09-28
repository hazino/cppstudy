# Day 10 — 2026-10-07: Prefix Sum

## 오늘의 목표

오늘의 주제를 설명하고 스스로 구현한다. 예제 읽기는 20분 이내, 문제 풀이를 우선한다.

개념 확인은 `../run.sh prefix_sum.cpp`로 실행한다. 먼저 직접 작성하고 비교한다.

## 핵심 개념

누적합, 구간 처리, 누적 상태.

## No IntelliSense Drill

1차원 누적합 생성과 구간 질의, 구간 평균 출력을 직접 작성한다.

## 온라인 문제

| Platform | Problem Name / Problem URL | Difficulty | Recommended Time | 핵심 학습 목표 | 파일 |
|---|---|---|---|---|---|
| CodeTree | [정수 N개의 합 2](https://www.codetree.ai/ko/trails/complete/curated-cards/intro-sum-of-n-integers-2/description) | Easy | 40분 | 조건 분석과 독립 구현 | `practice_01.cpp` |
| CodeTree | [정수 N개의 합 3](https://www.codetree.ai/ko/trails/complete/curated-cards/intro-sum-of-n-integers-3/description) | Easy | 45분 | 조건 분석과 독립 구현 | `practice_02.cpp` |

Difficulty의 기본·실전·도전은 이 계획의 학습 기준이며 공식 등급이 아니다. CodeTree의 Easy/Medium/Hard는 해당 페이지 표기다.

[플랫폼별 제출·로컬 검증 방법](../README.md#플랫폼별-제출과-로컬-검증)을 따른다. 온라인 문제의 전체 지문은 저장소에 복사하지 않는다.

## 권장 시간

20분 No IntelliSense 손코딩 → 40분 기본 문제 → 45분 실전 문제 → 15분 오답·problem_log 기록 (총 120분). 두 번째 문제가 부담되면 첫 문제의 구간 질의를 바꿔 재작성한다.

## 자주 하는 실수

l-1 인덱스, 정수 나눗셈, 합계 overflow.

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

## 보존 자료: 기존 DP 심화 (이번 계획 제외)

기존 `dp2.cpp`는 보존한다. 배낭·LIS·LCS·2D DP는 이번 학습 계획에서 제외한다.

<details>
<summary>과거 개념 설명 펼치기</summary>

## 기존 개념 노트

```bash
../run.sh dp2.cpp
```

## 유형별 State 패턴
| 유형 | State | 예 |
|---|---|---|
| 선택 / 비선택 | `dp[i][용량]` | 0/1 배낭 |
| 이전 선택에 제약 | `dp[i][마지막 선택]` | RGB 거리, 계단 오르기 |
| i로 끝나는 최적값 | `dp[i]`, 답은 `max(dp)` | LIS |
| 두 수열 비교 | `dp[i][j]` | LCS, 편집 거리 |
| 누적 상태 | `S[i][j]` 누적합 | 구간 합 질의 |

## 체크
- [ ] 반복되는 Subproblem을 찾는다 ("마지막에 무엇을 선택했나?")
- [ ] 0/1 배낭 1차원 최적화 시 **역순** 루프
- [ ] 누적합은 1-indexed로 두면 경계 처리가 사라진다
- [ ] 메모리 : `dp[N][W]`가 너무 크면 1차원 / 롤링 배열


</details>

</details>
