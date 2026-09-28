# Day 03 — 2026-09-30: BFS / DFS

## 오늘의 목표

오늘의 주제를 설명하고 스스로 구현한다. 예제 읽기는 20분 이내, 문제 풀이를 우선한다.

## 핵심 개념

인접 리스트, 방문 배열, BFS, DFS, 연결 요소.

## No IntelliSense Drill

참고자료 없이 인접 리스트, BFS, DFS, 연결 요소 세기를 처음부터 작성한다.

## 온라인 문제

| Platform | Problem Name / Problem URL | Difficulty | Recommended Time | 핵심 학습 목표 | 파일 |
|---|---|---|---|---|---|
| Programmers | [네트워크](https://school.programmers.co.kr/learn/courses/30/lessons/43162) | Lv.3 | 40분 | 조건 분석과 독립 구현 | `practice_01.cpp` |
| Programmers | [네트워크 (빈 파일 재풀이)](https://school.programmers.co.kr/learn/courses/30/lessons/43162) | Lv.3 | 45분 | 조건 분석과 독립 구현 | `practice_02.cpp` |

Difficulty의 기본·실전·도전은 이 계획의 학습 기준이며 공식 등급이 아니다. CodeTree의 Easy/Medium/Hard는 해당 페이지 표기다.

[플랫폼별 제출·로컬 검증 방법](../README.md#플랫폼별-제출과-로컬-검증)을 따른다. 온라인 문제의 전체 지문은 저장소에 복사하지 않는다.

## 권장 시간

20분 BFS/DFS 손코딩 → 네트워크 40분 → 자료를 닫고 다른 탐색 방식으로 재작성·검증 45분 → 로그 15분.

## 자주 하는 실수

방문 처리 시점, 탐색 간 초기화, 무방향 간선 누락, 재귀 깊이.

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
../run.sh bfs_dfs.cpp input.txt
```

## 기본 구조
```
Graph → Start Node → BFS / DFS → Visited 관리 → 탐색
```

## BFS vs DFS
| | BFS | DFS |
|---|---|---|
| 자료구조 | queue | 재귀 / stack |
| 특징 | 가까운 것부터 (레벨 순서) | 한 방향으로 끝까지 |
| 주 용도 | **가중치 없는 최단거리** | 연결 여부, 경로 전체 탐색, 백트래킹 |
| 복잡도 | O(V + E) | O(V + E) |

## 체크
- [ ] 인접 리스트 `vector<vector<int>> adj(n + 1)` 바로 작성
- [ ] BFS는 **큐에 넣을 때** visited 표시
- [ ] 테스트 케이스 여러 개일 때 visited / adj 초기화
- [ ] 양방향 / 단방향 간선 구분


</details>
