# Day 09 — 2026-10-06: 기본 DP

## 오늘의 목표

오늘의 주제를 설명하고 스스로 구현한다. 예제 읽기는 20분 이내, 문제 풀이를 우선한다.

## 핵심 개념

State, 점화식, Memoization, Bottom-up.

## No IntelliSense Drill

상태·초기값·전이·계산 순서를 정의하고 기본 DP를 작성한다.

## 온라인 문제

| Platform | Problem Name / Problem URL | Difficulty | Recommended Time | 핵심 학습 목표 | 파일 |
|---|---|---|---|---|---|
| Programmers | [피보나치 수](https://school.programmers.co.kr/learn/courses/30/lessons/12945) | 기본 | 40분 | 조건 분석과 독립 구현 | `practice_01.cpp` |
| Programmers | [멀리 뛰기](https://school.programmers.co.kr/learn/courses/30/lessons/12914) | 기본 | 45분 | 조건 분석과 독립 구현 | `practice_02.cpp` |

Difficulty의 기본·실전·도전은 이 계획의 학습 기준이며 공식 등급이 아니다. CodeTree의 Easy/Medium/Hard는 해당 페이지 표기다.

기존 dp1.cpp에는 과제와 겹치는 완성 예제가 있으므로 첫 풀이 전에는 열지 않는다. State·초기값·점화식 정의에 집중한다.

[플랫폼별 제출·로컬 검증 방법](../README.md#플랫폼별-제출과-로컬-검증)을 따른다. 온라인 문제의 전체 지문은 저장소에 복사하지 않는다.

## 권장 시간

20분 No IntelliSense 손코딩 → 40분 기본 문제 → 45분 실전 문제 → 15분 오답·problem_log 기록 (총 120분).

## 자주 하는 실수

초기값 누락, 계산 순서, 상태에 필요한 정보 누락.

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
../run.sh dp1.cpp
```

## DP 풀이 순서
1. **State** : `dp[i]`가 무엇을 의미하는지 **한 문장으로** 쓴다
2. **Transition** : `dp[i]`를 더 작은 state로 표현 ("마지막 선택이 무엇이었나?")
3. **초기값** : 가장 작은 state (`dp[0]`, `dp[1]`)
4. **순서** : 작은 state → 큰 state
5. **답** : `dp[n]`인지, `max(dp[...])`인지

## Top-down vs Bottom-up
| | Top-down (재귀 + memo) | Bottom-up (반복문) |
|---|---|---|
| 장점 | 점화식 그대로, 필요한 state만 계산 | 빠름, 스택 오버플로 없음 |
| 주의 | memo 초기값(-1)과 실제 값 구분, 재귀 깊이 | 계산 순서를 직접 정해야 함 |

## 체크
- [ ] State가 한 차원으로 부족하면 차원 추가 (계단 오르기)
- [ ] 방법의 수는 `% MOD` 요구 여부 확인
- [ ] 값 크기 → `long long`


</details>
