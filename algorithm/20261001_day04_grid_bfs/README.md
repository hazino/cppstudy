# Day 04 — 2026-10-01: Grid BFS

## 오늘의 목표

오늘의 주제를 설명하고 스스로 구현한다. 예제 읽기는 20분 이내, 문제 풀이를 우선한다.

## 핵심 개념

2D Grid, dx/dy, 최단거리, Multi-source BFS.

## 반드시 직접 작성할 코드

좌표 경계 검사와 단일/다중 시작점 BFS를 직접 작성한다.

## 오늘 풀 문제

| 순서 | 문제 | 풀이 파일 |
|---|---|---|
| 1 | [BOJ 2178 미로 탐색](https://www.acmicpc.net/problem/2178) | `boj_2178.cpp` |
| 2 | [BOJ 7576 토마토](https://www.acmicpc.net/problem/7576) | `boj_7576.cpp` |

## 권장 시간

20분 개념·손코딩 → 40분 기본 문제 → 45분 실전 문제 → 15분 오답·로그 (총 120분).

## 자주 발생하는 실수

행/열 뒤바뀜, 시작 거리 기준, 도달 불가 처리.

## 완료 체크리스트

- [ ] 코드를 보기 전에 직접 작성했다.
- [ ] 문제를 읽고 3~5분 안에 첫 접근과 복잡도를 적었다.
- [ ] 예제와 직접 만든 경계 사례를 확인했다.
- [ ] 결과·실패 원인·재도전 날짜를 [problem_log.md](../problem_log.md)에 기록했다.

[공통 풀이 원칙](../README.md#문제-풀이-원칙)을 따른다.

---

## 기존 개념 노트

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

## 선택 추가 문제 (필수 풀이 완료 후)
- 2178 미로 탐색
- 7576 토마토 (Multi-source)
- 14940 쉬운 최단거리
