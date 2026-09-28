# C++ 코딩테스트 준비 (현대모비스 SW)

2026-09-28부터 하루 약 **2시간**, C++17로 준비한다. 목표는 백준 Silver ~ Gold 5 수준이며 구현/Simulation 및 BFS/DFS/Dijkstra를 중점 학습한다.

10/17까지는 학습 계획이며 실제 시험일을 확정한 일정은 아니다. 시험이 더 늦으면 Day 15~19의 약점·혼합·모의·오답 주기를 반복하고 Final Review를 D-1/D-2에 다시 진행한다. 이 모의고사는 요청한 대비 방향에 맞춘 자체 구성이다.

## 실행
Windows에서는 Git Bash 또는 WSL에서 실행한다. 저장소 루트에서는 먼저 `cd algorithm` 한다.

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
| 10/04 일 | `20261004_day07_week1_review` | 빈칸 드릴 + 혼합 2문제 (1개 선택) | `blank_drill.cpp` |

### Phase 2 : Core Algorithm (10/05 ~ 10/11)
| 날짜 | 폴더 | 주제 | 예제 |
|---|---|---|---|
| 10/05 월 | `20261005_day08_greedy` | 정렬 + 그리디, 반례 | `greedy.cpp` |
| 10/06 화 | `20261006_day09_dp` | State, 점화식, Memo / Bottom-up | `dp1.cpp` |
| 10/07 수 | `20261007_day10_prefix_sum_dp` | Prefix Sum, 구간 처리, 기본 DP 응용 | `prefix_sum.cpp` (기존 dp2는 선택) |
| 10/08 목 | `20261008_day11_graph_practice` | BFS/DFS/Dijkstra 응용 및 선택 | Day 3/6 예제 재사용 (위상 정렬 선택) |
| 10/09 금 | `20261009_day12_simulation` | 방향 회전, 배열 회전, 뱀 | `simulation.cpp` |
| 10/10 토 | `20261010_day13_backtracking` | 순열, 조합 (N-Queen 선택) | `backtracking.cpp` |
| 10/11 일 | `20261011_day14_week2_mini_test` | Mini Test 90~120분 | README |

### Phase 3 : Practical Test (10/12 ~ 시험)
| 날짜 | 폴더 | 주제 |
|---|---|---|
| 10/12 월 | `20261012_day15_weak_point` | 약점 분석 + 약점 문제 |
| 10/13 화 | `20261013_day16_mixed` | 유형 모르고 풀기 |
| 10/14 수 | `20261014_day17_speed` | 속도 훈련 |
| 10/15 목 | `20261015_day18_mock_test1` | 모의 테스트 120분 |
| 10/16 금 | `20261016_day19_mock_review` | 오답 분석 |
| 10/17 토 (D-1/D-2 재활용) | `20261017_day20_final_review` | 템플릿 총정리 `templates.cpp` |

## 문제 풀이 원칙

### 하루 120분

- 20분: 개념 및 알고리즘 손코딩
- 40분: 기본 문제
- 45분: 실전 문제
- 15분: 오답 및 `problem_log.md` 기록

복습·테스트일은 각 README의 시간표를 우선한다. 선택 문제는 필수 문제를 끝낸 후에만 진행한다.

### 40~45분 Rule

40~45분 고민해도 알고리즘 방향조차 잡히지 않으면 힌트 또는 해설을 확인한다. 단순 구현 실수를 디버깅 중이면 조금 더 진행할 수 있으나 초과 시간을 기록한다. 테스트 중에는 힌트를 열지 않고 다음 문제로 넘어가며 종료 후 확인한다.

### No IntelliSense Drill

BFS / DFS / Dijkstra / Binary Search는 최소 한 번 자동완성이나 AI 도움 없이 처음부터 작성한다. 브라우저의 일반 텍스트 입력 환경이나 자동완성·코드 제안·스니펫을 끈 편집기에서 C++17로 연습한다. 예제를 닫고 작성한 뒤 비교한다. `boj_*.cpp`, `q*.cpp`, `a.cpp`~`e.cpp`는 의도적으로 미완성이다.

### 문제 판단

문제를 읽은 뒤 3~5분 안에 Implementation / Simulation, BFS, DFS, Dijkstra, Binary Search, Greedy, DP, Backtracking 중 접근 후보를 고르고 입력 크기·복잡도·근거를 기록한다.

### 자료와 입력

기존 이름의 개념 예제를 유지하며 동일한 `example.cpp`를 중복 생성하지 않는다. 각 `input/README.md`에 따라 예제 입력과 예상 출력을 준비한다. 완성된 개념 코드는 제출용 정답이 아니다. Day 9 예제처럼 과제와 겹치는 코드는 먼저 풀고 비교한다.

BOJ 링크는 요청된 문제 번호를 기준으로 보존했다. 2026-09-28 확인 시 일부 공식 페이지가 채점 서비스 준비 안내 또는 조회 오류를 반환해 현재 접근·채점 가능 여부와 난이도는 검증하지 못했다. 이용 가능한 문제 본문과 채점 환경을 먼저 확인하고, 채점이 불가능하면 로컬 검증 결과로 구분해 기록한다.

## 최종 완료 기준

- [ ] C++ STL 사용에 불편함이 없다.
- [ ] BFS를 자료 없이 구현할 수 있다.
- [ ] DFS를 자료 없이 구현할 수 있다.
- [ ] Grid BFS를 자료 없이 구현할 수 있다.
- [ ] Dijkstra를 자료 없이 구현할 수 있다.
- [ ] Binary Search / Parameter Search를 구현할 수 있다.
- [ ] 기본 DP 문제의 State와 점화식을 정의할 수 있다.
- [ ] Greedy 적용 가능 여부를 판단할 수 있다.
- [ ] Simulation 문제를 안정적으로 구현할 수 있다.
- [ ] Backtracking 기본 구조를 구현할 수 있다.
- [ ] 문제의 시간복잡도를 계산할 수 있다.
- [ ] 처음 보는 문제의 알고리즘 유형을 3~5분 안에 판단할 수 있다.
- [ ] 자동완성 없이 주요 알고리즘을 작성할 수 있다.
- [ ] 90~120분 동안 연속으로 문제를 풀 수 있다.
- [ ] 풀 문제와 넘길 문제를 판단할 수 있다.
