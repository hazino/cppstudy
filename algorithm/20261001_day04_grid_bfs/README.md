# Day 04 — 2026-10-01: Grid BFS

## 오늘의 목표

오늘의 주제를 설명하고 스스로 구현한다. 예제 읽기는 20분 이내, 문제 풀이를 우선한다.

## 핵심 개념

2D Grid, dx/dy, 최단거리, Multi-source BFS.

## No IntelliSense Drill

좌표 경계 검사와 단일/다중 시작점 BFS를 직접 작성한다.

## 온라인 문제

| Platform | Problem Name / Problem URL | Difficulty | Recommended Time | 핵심 학습 목표 | 파일 |
|---|---|---|---|---|---|
| Programmers | [게임 맵 최단거리](https://school.programmers.co.kr/learn/courses/30/lessons/1844) | Lv.2 | 40분 | 조건 분석과 독립 구현 | `practice_01.cpp` |
| Programmers | [게임 맵 최단거리 (경계 사례 재검증)](https://school.programmers.co.kr/learn/courses/30/lessons/1844) | Lv.2 | 45분 | 조건 분석과 독립 구현 | `practice_02.cpp` |

Difficulty의 기본·실전·도전은 이 계획의 학습 기준이며 공식 등급이 아니다. CodeTree의 Easy/Medium/Hard는 해당 페이지 표기다.

[플랫폼별 제출·로컬 검증 방법](../README.md#플랫폼별-제출과-로컬-검증)을 따른다. 온라인 문제의 전체 지문은 저장소에 복사하지 않는다.

## 권장 시간

20분 Grid BFS·다중 시작점 초기화 손코딩 → 게임 맵 최단거리 40분 → 경계 사례 및 빈 파일 재작성 45분 → 로그 15분. Multi-source는 별도 작은 격자로 개념을 확인한다.

## 자주 하는 실수

행/열 뒤바뀜, 시작 거리 기준, 도달 불가 처리.

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


</details>
