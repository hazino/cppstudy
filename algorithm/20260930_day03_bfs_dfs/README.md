# Day 3 - 09/30 (수) : BFS / DFS

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

## 추천 문제 (BOJ)
- 1260 DFS와 BFS (그래프)
- 11724 연결 요소의 개수 (그래프)
- 2667 단지번호붙이기 (Grid)
