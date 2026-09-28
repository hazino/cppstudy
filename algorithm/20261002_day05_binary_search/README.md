# Day 05 — 2026-10-02: Binary Search

## 오늘의 목표

오늘의 주제를 설명하고 스스로 구현한다. 예제 읽기는 20분 이내, 문제 풀이를 우선한다.

## 핵심 개념

binary_search, lower_bound, upper_bound, Parameter Search.

## No IntelliSense Drill

참고자료 없이 lower_bound와 단조 조건의 최대/최소 경계 탐색을 작성한다.

## 온라인 문제

| Platform | Problem Name / Problem URL | Difficulty | Recommended Time | 핵심 학습 목표 | 파일 |
|---|---|---|---|---|---|
| Programmers | [입국심사](https://school.programmers.co.kr/learn/courses/30/lessons/43238) | 실전 | 40분 | 조건 분석과 독립 구현 | `practice_01.cpp` |
| Programmers | [입국심사 (빈 파일 재풀이)](https://school.programmers.co.kr/learn/courses/30/lessons/43238) | 실전 | 45분 | 조건 분석과 독립 구현 | `practice_02.cpp` |

Difficulty의 기본·실전·도전은 이 계획의 학습 기준이며 공식 등급이 아니다. CodeTree의 Easy/Medium/Hard는 해당 페이지 표기다.

[플랫폼별 제출·로컬 검증 방법](../README.md#플랫폼별-제출과-로컬-검증)을 따른다. 온라인 문제의 전체 지문은 저장소에 복사하지 않는다.

## 권장 시간

20분 직접 이분 탐색 → 입국심사 40분 → 힌트를 닫고 재작성·경계 검증 45분 → 로그 15분.

## 자주 하는 실수

무한 루프, 정렬 누락, 합계 overflow, 답이 없는 경우.

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
../run.sh binary_search.cpp
```

## 두 가지 구간 스타일 (하나만 골라서 손에 익히기)
| | 닫힌 구간 `[lo, hi]` | 반닫힌 구간 `[lo, hi)` |
|---|---|---|
| 반복 조건 | `lo <= hi` | `lo < hi` |
| 이동 | `lo = mid + 1`, `hi = mid - 1` | `lo = mid + 1`, `hi = mid` |
| 결과 | 조건 만족 시 `answer = mid`로 기록 | 루프 끝난 `lo`가 답 |

## Parameter Search 판별법
- "~의 **최댓값/최솟값**을 구하라" + 답의 범위가 매우 큼 (10^9 이상)
- 답을 X로 **고정**하면 "가능/불가능" 판정이 쉬움
- 판정 결과가 단조 (`T T T F F` 또는 `F F T T T`)

## 체크
- [ ] 정렬 안 된 배열에 이분 탐색하지 않기
- [ ] `lo`, `hi`, 합계는 `long long` (특히 Parameter Search)
- [ ] `hi` 초기값이 가능한 답을 전부 포함하는지


</details>
