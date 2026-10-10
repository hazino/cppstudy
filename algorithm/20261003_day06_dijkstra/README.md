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
| Programmers | [배달](https://school.programmers.co.kr/learn/courses/30/lessons/12978) | 기본 | 40분 | 가중 그래프의 최단거리 기본 구현 | `practice_01.cpp` |
| Programmers | [합승 택시 요금](https://school.programmers.co.kr/learn/courses/30/lessons/72413) | 실전 | 60분 | 최단거리 응용과 비용 비교 | `practice_02.cpp` |
| Programmers | [등산코스 정하기](https://school.programmers.co.kr/learn/courses/30/lessons/118669) | 도전 | 75분 | 경로 비용 정의와 제약 조건을 반영하는 탐색 | `practice_03.cpp` |

난이도는 이 계획의 학습 기준이며 공식 등급이 아니다. 위 순서대로 풀고, 세 번째 문제는 기본 구현을 익힌 뒤 도전한다. Day 11의 배달과 Day 18의 합승 택시 요금은 복습으로 유지한다.

[플랫폼별 제출·로컬 검증 방법](../README.md#플랫폼별-제출과-로컬-검증)을 따른다. 온라인 문제의 전체 지문은 저장소에 복사하지 않는다.

## 권장 시간

20분 Dijkstra 손코딩 → 배달 40분 → 합승 택시 요금 60분 → 등산코스 정하기 75분 → 로그 15분. 총 210분이며, 시간이 부족하면 세 번째 문제는 다음 학습 시간에 이어서 푼다.

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
