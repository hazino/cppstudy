# Day 4 - 10/01 (목) : BFS / DFS 응용 (Grid)

```bash
../run.sh grid_bfs.cpp
```

## 바로 쓸 수 있어야 하는 형태
```cpp
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();             // Current
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];       // Next
        if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;  // Boundary
        if (dist[nx][ny] != -1) continue;         // Visited
        dist[nx][ny] = dist[x][y] + 1;
        q.push({nx, ny});
    }
}
```

## 체크
- [ ] 가중치 없는 격자 최단거리 = BFS
- [ ] `dist`를 -1로 초기화해서 visited 대용
- [ ] Multi-source : 시작점 전부 큐에 넣고 BFS 한 번
- [ ] 행(x) / 열(y) 헷갈리지 않기 (입력이 `M N`처럼 열 먼저 주어지는지 확인)

## 추천 문제 (BOJ)
- 2178 미로 탐색
- 7576 토마토 (Multi-source)
- 14940 쉬운 최단거리
