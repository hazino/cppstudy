# C++ 코딩테스트 준비 (현대모비스 SW)

하루 약 60분. 날짜별 폴더에 예제 코드와 체크리스트가 있다.

## 실행
```bash
./run.sh <폴더>/<파일>.cpp [입력파일]

./run.sh 20260928_day01_stl_basic/stl_basic.cpp
cd 20260930_day03_bfs_dfs && ../run.sh bfs_dfs.cpp input.txt
```
`g++ -std=c++17 -O2 -Wall -Wextra`로 컴파일하고, 바이너리는 `.bin/`에 생긴다 (git 무시).

새 문제는 `_template/main.cpp`를 복사해서 시작한다. 풀이 기록은 `problem_log.md`에 남긴다.

## 일정

### Phase 1 : C++ / STL Recovery (09/28 ~ 10/04)
| 날짜 | 폴더 | 주제 | 예제 |
|---|---|---|---|
| 09/28 월 | `20260928_day01_stl_basic` | vector, string, sort, lambda | `stl_basic.cpp` |
| 09/29 화 | `20260929_day02_stl_container` | stack, queue, deque, pq, set, map | `stl_container.cpp` |
| 09/30 수 | `20260930_day03_bfs_dfs` | 인접 리스트, BFS, DFS, 연결 요소 | `bfs_dfs.cpp` + `input.txt` |
| 10/01 목 | `20261001_day04_grid_bfs` | Grid 최단거리, Multi-source BFS | `grid_bfs.cpp` |
| 10/02 금 | `20261002_day05_binary_search` | lower/upper_bound, Parameter Search | `binary_search.cpp` |
| 10/03 토 | `20261003_day06_dijkstra` | Dijkstra, 경로 역추적 | `dijkstra.cpp` + `input.txt` |
| 10/04 일 | `20261004_day07_week1_review` | 빈칸 드릴 + 혼합 3문제 | `blank_drill.cpp` |

### Phase 2 : Core Algorithm (10/05 ~ 10/11)
| 날짜 | 폴더 | 주제 | 예제 |
|---|---|---|---|
| 10/05 월 | `20261005_day08_greedy` | 정렬 + 그리디, 반례 | `greedy.cpp` |
| 10/06 화 | `20261006_day09_dp1` | State, 점화식, Memo / Bottom-up | `dp1.cpp` |
| 10/07 수 | `20261007_day10_dp2` | 배낭, 2D DP, LIS, LCS, 누적합 | `dp2.cpp` |
| 10/08 목 | `20261008_day11_graph_topo_sort` | 위상 정렬, DAG + DP | `topo_sort.cpp` + `input.txt` |
| 10/09 금 | `20261009_day12_simulation` | 방향 회전, 배열 회전, 뱀 | `simulation.cpp` |
| 10/10 토 | `20261010_day13_backtracking` | 순열, 조합, N-Queen | `backtracking.cpp` |
| 10/11 일 | `20261011_day14_week2_mini_test` | Mini Test 90분 | README |

### Phase 3 : Practical Test (10/12 ~ 시험)
| 날짜 | 폴더 | 주제 |
|---|---|---|
| 10/12 월 | `20261012_day15_weak_point` | 약점 분석 + 약점 문제 |
| 10/13 화 | `20261013_day16_mixed` | 유형 모르고 풀기 |
| 10/14 수 | `20261014_day17_speed` | 속도 훈련 |
| 10/15 목 | `20261015_day18_mock_test1` | 모의 테스트 120분 |
| 10/16 금 | `20261016_day19_mock_review` | 오답 분석 |
| D-1 / D-2 | `20261017_day20_final_review` | 템플릿 총정리 `templates.cpp` |

## 최종 완료 기준
- [ ] C++ STL 사용에 불편함이 없다.
- [ ] BFS / DFS를 자료 없이 구현할 수 있다.
- [ ] Dijkstra를 자료 없이 구현할 수 있다.
- [ ] Binary Search를 자료 없이 구현할 수 있다.
- [ ] 기본 DP 문제를 해결할 수 있다.
- [ ] Greedy 문제를 판별할 수 있다.
- [ ] Simulation 문제를 안정적으로 구현할 수 있다.
- [ ] Backtracking 기본 구조를 구현할 수 있다.
- [ ] 문제의 시간복잡도를 계산할 수 있다.
- [ ] 90~120분 동안 실전 문제풀이가 가능하다.
- [ ] 풀 문제와 넘길 문제를 판단할 수 있다.
