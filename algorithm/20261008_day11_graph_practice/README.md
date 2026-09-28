# Day 11 — 2026-10-08: 그래프 응용

## 오늘의 목표

오늘의 주제를 설명하고 스스로 구현한다. 예제 읽기는 20분 이내, 문제 풀이를 우선한다.

## 핵심 개념

BFS/DFS/Dijkstra 응용과 선택.

## No IntelliSense Drill

연결 여부·간선 수·비용의 차이를 설명하고 선택한 알고리즘을 직접 작성한다.

## 온라인 문제

| Platform | Problem Name / Problem URL | Difficulty | Recommended Time | 핵심 학습 목표 | 파일 |
|---|---|---|---|---|---|
| Programmers | [단어 변환](https://school.programmers.co.kr/learn/courses/30/lessons/43163) | 실전 | 40분 | 조건 분석과 독립 구현 | `practice_01.cpp` |
| Programmers | [배달 (응용 재풀이)](https://school.programmers.co.kr/learn/courses/30/lessons/12978) | 실전 | 45분 | 조건 분석과 독립 구현 | `practice_02.cpp` |

Difficulty의 기본·실전·도전은 이 계획의 학습 기준이며 공식 등급이 아니다. CodeTree의 Easy/Medium/Hard는 해당 페이지 표기다.

**CodeTree 우선 선택:** [공식 학습 사이트](https://www.codetree.ai/ko)에서 Trail 4 → Chapter 3 DFS / Chapter 4 BFS 또는 Trail 5 → Chapter 5 Shortest Path의 접근 가능한 기본 문제를 선택한다. 2026-09-28에는 과정 탐색 중 로그인·이용권 안내가 표시되어 개별 그래프 문제의 이름·URL·난이도를 검증하지 못했다. 아래 표는 선택 기록용이며 홈페이지를 개별 문제 URL로 취급하지 않는다. 선택이 어렵거나 접근 권한이 없으면 위의 확인된 대체 문제를 바로 사용한다.

| Platform | Problem Name | Problem URL | Difficulty | Recommended Time | 핵심 학습 목표 |
|---|---|---|---|---|---|
| CodeTree | 당일 선택 | 개별 문제 링크 기록 | 페이지에서 확인 | 40분 | 조건에 맞는 독립 구현 |
| CodeTree | 당일 선택 | 개별 문제 링크 기록 | 페이지에서 확인 | 45분 | 경계 사례 검증 |

Day 6에서 배달을 풀었다면 초기 코드를 지운 브라우저에서 다시 작성하고 반례를 추가한다. 새 문제 성과와 재풀이 성과는 구분한다.

CodeTree 문제를 선택하면 같은 `practice_01.cpp`, `practice_02.cpp`의 메타데이터만 바꾸고 풀이한다.

[플랫폼별 제출·로컬 검증 방법](../README.md#플랫폼별-제출과-로컬-검증)을 따른다. 온라인 문제의 전체 지문은 저장소에 복사하지 않는다.

## 권장 시간

20분 No IntelliSense 손코딩 → 40분 기본 문제 → 45분 실전 문제 → 15분 오답·problem_log 기록 (총 120분).

## 자주 하는 실수

가중치 무시, 방향 착각, 도달 불가 정점.

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

## 보존 자료: 기존 위상 정렬 (이번 계획 제외)

기존 `topo_sort.cpp`와 `input.txt`는 과거 참고용으로 보존한다. 오늘의 필수 과제는 위의 두 문제다.

<details>
<summary>과거 개념 설명 펼치기</summary>

## 기존 개념 노트

```bash
../run.sh topo_sort.cpp input.txt
```

## 그래프 유형별 알고리즘 선택
| 문제 신호 | 알고리즘 |
|---|---|
| 연결 여부, 영역 개수 | BFS / DFS |
| 가중치 없는 최단거리 | BFS |
| 양수 가중치 최단거리 | Dijkstra |
| **선행 조건, 순서, 작업 스케줄** | Topological Sort |
| 선행 조건 + 최소 완료 시간 | 위상 정렬 + DP |
| 사이클 존재 여부 (방향 그래프) | 위상 정렬 결과 크기 < N |

## Topological Sort 설명 (말로 할 수 있어야 함)
- DAG(방향 + 사이클 없음)에서 모든 간선 `a → b`에 대해 a가 b보다 앞에 오는 순서
- 진입차수 0인 정점 = 지금 바로 할 수 있는 작업
- 결과가 유일하지 않을 수 있다 (문제에서 "번호 작은 것 먼저" → 최소 힙)


</details>

</details>
