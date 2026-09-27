# Day 6 - 10/03 (토) : Graph / Dijkstra

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

## 추천 문제 (BOJ)
- 1753 최단경로
- 1916 최소비용 구하기
- 11779 최소비용 구하기 2 (경로 역추적)
