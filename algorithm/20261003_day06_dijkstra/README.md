# Day 06 — 2026-10-03: Dijkstra

## 오늘의 목표

오늘의 주제를 설명하고 스스로 구현한다. 예제 읽기는 20분 이내, 문제 풀이를 우선한다.

## 핵심 개념

가중 그래프, priority_queue, 거리 배열, 경로 역추적.

## No IntelliSense Drill

참고자료 없이 최소 힙, 거리 갱신, 오래된 항목 무시, prev 역추적까지 작성한다.

## 온라인 문제

| Platform | Problem Name / Problem URL | Difficulty | Recommended Time | 핵심 학습 목표 | 파일 |
|---|---|---|---|---|---|
| Programmers | [배달](https://school.programmers.co.kr/learn/courses/30/lessons/12978) | 실전 | 40분 | 조건 분석과 독립 구현 | `practice_01.cpp` |
| LeetCode | [Network Delay Time](https://leetcode.com/problems/network-delay-time/) | Medium | 45분 | 선택 보충: 독립 구현 | `practice_02.cpp` |

Difficulty의 기본·실전·도전은 이 계획의 학습 기준이며 공식 등급이 아니다. CodeTree의 Easy/Medium/Hard는 해당 페이지 표기다.

**CodeTree 우선 선택:** [공식 학습 사이트](https://www.codetree.ai/ko)에서 Trail 5 → Chapter 5 Shortest Path의 접근 가능한 기본 문제를 선택한다. 2026-09-28에는 과정 탐색 중 로그인·이용권 안내가 표시되어 개별 그래프 문제의 이름·URL·난이도를 검증하지 못했다. 아래 표는 선택 기록용이며 홈페이지를 개별 문제 URL로 취급하지 않는다. 선택이 어렵거나 접근 권한이 없으면 위의 확인된 대체 문제를 바로 사용한다.

| Platform | Problem Name | Problem URL | Difficulty | Recommended Time | 핵심 학습 목표 |
|---|---|---|---|---|---|
| CodeTree | 당일 선택 | 개별 문제 링크 기록 | 페이지에서 확인 | 40분 | 조건에 맞는 독립 구현 |
| CodeTree | 당일 선택 | 개별 문제 링크 기록 | 페이지에서 확인 | 45분 | 경계 사례 검증 |

CodeTree 문제를 선택하면 같은 `practice_01.cpp`, `practice_02.cpp`의 메타데이터만 바꾸고 풀이한다.

[플랫폼별 제출·로컬 검증 방법](../README.md#플랫폼별-제출과-로컬-검증)을 따른다. 온라인 문제의 전체 지문은 저장소에 복사하지 않는다.

## 권장 시간

20분 Dijkstra 전체 손코딩 → 기본 문제 40분 → 다른 CodeTree 문제 또는 빈 파일 재풀이 45분 → 로그 15분. LeetCode는 이 45분 슬롯의 선택 대체이며 추가 필수가 아니다.

## 자주 하는 실수

음수 가중치 적용, INF 덧셈, 힙 방향, 도달 불가 경로 역추적.

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
../run.sh dijkstra.cpp input.txt
```

## 알고리즘 선택
| 상황 | 알고리즘 | 복잡도 |
|---|---|---|
| 가중치 없음 (모두 1) | BFS | O(V + E) |
| 가중치 0 또는 1 | 0-1 BFS (deque) | O(V + E) |
| 가중치 양수 | Dijkstra | O(E log V) |
| 음수 가중치 존재 | Bellman-Ford | O(VE) |
| 모든 쌍 최단거리, V ≤ 400 정도 | Floyd-Warshall | O(V³) |

## 체크
- [ ] `if (d > dist[cur]) continue;` 빠뜨리지 않기 (빠지면 시간 초과 가능)
- [ ] `greater<>` 로 최소 힙 (기본은 최대 힙!)
- [ ] 거리 합이 int 범위를 넘는지 → `long long`
- [ ] INF에 더하다가 overflow 나지 않게
- [ ] 단방향 / 양방향 간선 확인

## OHT 경로 탐색과 연결
- 레일 구간 = 간선, 분기/합류점 = 정점, 구간 주행 시간 = 가중치
- 실무에서의 경로 비용(거리/혼잡도)이 코딩테스트의 가중치와 같은 개념
- 경로 자체가 필요하면 `prev[]`로 역추적


</details>
