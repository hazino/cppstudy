# C++ 코딩테스트 준비 (현대모비스 SW)

2026-09-28부터 하루 약 **2시간**, C++17로 준비한다. 기본~중급 문제를 대상으로 구현/Simulation 및 BFS/DFS/Dijkstra를 중점 학습한다.

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

최신 접속 점검: [2026-10-05 문제 링크 38개 확인 결과](LINK_CHECK.md). `12930`은 사용자 404 신고와 확인 브라우저 결과가 달라 대체 문제를 함께 안내한다.

## 온라인 학습 플랫폼

Primary는 [CodeTree](https://www.codetree.ai/ko), Secondary는 [Programmers](https://school.programmers.co.kr/learn/challenges)다. LeetCode는 특정 알고리즘의 선택 보충으로만 사용한다.

CodeTree는 Day 7·10·12·17 및 실전 세트에서 사용하고, Day 6·11은 해당 과정에서 접근 가능한 문제를 우선 선택한다. 개별 그래프 문제를 확인하지 못한 날짜에는 공식 페이지를 확인한 Programmers 대체 문제를 제공한다. 문제 선택·이용권 확인은 타이머 시작 전에 마친다.

2026-09-28 확인: CodeTree의 지정된 구현·누적합 문제는 문제 본문과 편집기·제출 버튼이 표시됐다. 일부 과정 메뉴는 로그인·이용권 안내가 나타났다. Programmers 지정 문제는 공식 본문과 C++ 선택 항목을 확인했다. 실제 계정 로그인 후 제출·채점은 수행하지 않았다. 무료 접근 및 계정별 권한까지 보장한 목록은 아니다. CodeTree에 접근할 수 없으면 같은 날의 대체 문제를 사용하거나 이전 미해결 Programmers 문제를 재풀이한다.

## 필수 범위

구현 / Simulation / BFS / DFS / Dijkstra를 우선하며 Binary Search / Priority Queue / Greedy도 반복한다. DP / Backtracking은 기본만 학습한다. LIS/LCS, 고급 DP, Segment Tree, Trie는 필수 및 실전 출제 범위에서 제외한다. 기존 dp2.cpp와 위상 정렬 코드는 과거 참고자료로 보존하며 오늘의 과제로 요구하지 않는다. N-Queen은 선택이다.

## 플랫폼별 제출과 로컬 검증

- **CodeTree:** 브라우저에서 C++ 언어를 선택하고 C++17 범위로 `main()`과 표준 입출력을 직접 작성한다. 로컬로 옮긴 뒤 기존 `run.sh`로 실행할 수 있다.
- **Programmers:** 브라우저의 C++ 시작 코드에 있는 `solution(...)` 시그니처를 유지한다. 결과는 반환값으로 전달하며 온라인에 `main()`을 제출하지 않는다. 로컬 검증 시에만 `main()`에서 함수를 호출하는 코드를 직접 추가하고 `run.sh`로 실행한다.
- **LeetCode (선택):** 공식 C++의 `class Solution` 시그니처를 따른다. 로컬 테스트용 진입점은 온라인 제출 코드에 포함하지 않는다.

현재 문제 파일은 메타데이터와 TODO 및 로컬 자리표시자뿐이다. 온라인 제출용 완성 코드가 아니며, 미완성 상태 실행은 종료 코드 1을 반환한다. 브라우저에서 푼 뒤 저장소에 풀이와 복기 내용을 옮긴다. 같은 문제 재풀이는 해당 날짜의 파일에 기록하고 예제 파일은 복제하지 않는다.

## 일정

### Phase 1 : C++ / STL + 핵심 그래프 (09/28 ~ 10/04)
| 날짜 | 폴더 | 주제 | 예제 |
|---|---|---|---|
| 09/28 월 | `20260928_day01_stl_basic` | vector, string, sort, lambda | `stl_basic.cpp` |
| 09/29 화 | `20260929_day02_stl_container` | stack, queue, deque, pq, set, map | `stl_container.cpp` |
| 09/30 수 | `20260930_day03_bfs_dfs` | 인접 리스트, BFS, DFS, 연결 요소 | `bfs_dfs.cpp` + `input.txt` |
| 10/01 목 | `20261001_day04_grid_bfs` | Grid 최단거리, Multi-source BFS | `grid_bfs.cpp` |
| 10/02 금 | `20261002_day05_binary_search` | lower/upper_bound, Parameter Search | `binary_search.cpp` |
| 10/03 토 | `20261003_day06_dijkstra` | Dijkstra, 경로 역추적 | `dijkstra.cpp` + `input.txt` |
| 10/04 일 | `20261004_day07_week1_review` | 빈칸 드릴 + 혼합 2문제 (1개 선택) | `blank_drill.cpp` |

### Phase 2 : 현대모비스 Core (10/05 ~ 10/11)
| 날짜 | 폴더 | 주제 | 예제 |
|---|---|---|---|
| 10/05 월 | `20261005_day08_greedy` | 정렬 + 그리디, 반례 | `greedy.cpp` |
| 10/06 화 | `20261006_day09_dp` | State, 점화식, Memo / Bottom-up | `dp1.cpp` |
| 10/07 수 | `20261007_day10_prefix_sum` | Prefix Sum, 구간 질의, 누적 계산 | `prefix_sum.cpp` (기존 dp2는 선택) |
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

### 40~45 Minute Rule

40~45분 고민해도 알고리즘 방향조차 잡히지 않으면 힌트 또는 해설을 확인한다. 단순 구현 실수를 디버깅 중이면 조금 더 진행할 수 있으나 초과 시간을 기록한다. 테스트 중에는 힌트를 열지 않고 다음 문제로 넘어가며 종료 후 확인한다.

### No IntelliSense Drill

BFS / DFS / Dijkstra / Binary Search는 최소 한 번 자동완성이나 AI 도움 없이 처음부터 작성한다. 브라우저의 일반 텍스트 입력 환경이나 자동완성·코드 제안·스니펫을 끈 편집기에서 C++17로 연습한다. 예제를 닫고 작성한 뒤 비교한다. `practice_*.cpp`, `q*.cpp`, `a.cpp`~`e.cpp`는 의도적으로 미완성이다.

### Browser First

실전 문제는 가능한 한 CodeTree 또는 Programmers 브라우저 에디터에서 직접 작성한다. VS Code에서 완성한 코드를 사이트로 복사하는 방식은 지양한다. 에디터 자동완성과 AI 코드 제안·분석 기능을 끄고 시작한다.

### AI Usage

AI는 학습 후 코드 리뷰, 시간복잡도 검증, 다른 풀이 비교, 오답 원인 분석에만 사용한다. 첫 풀이와 No IntelliSense Drill에서는 AI로 정답을 생성하지 않는다.

### 문제 판단

문제를 읽은 뒤 3~5분 안에 Implementation / Simulation, BFS, DFS, Dijkstra, Binary Search, Greedy, DP, Backtracking 중 접근 후보를 고르고 입력 크기·복잡도·근거를 기록한다.

### 자료와 입력

기존 이름의 개념 예제를 유지하며 동일한 `example.cpp`를 중복 생성하지 않는다. 각 `input/README.md`에 따라 예제 입력과 예상 출력을 준비한다. 완성된 개념 코드는 제출용 정답이 아니다. Day 9 예제처럼 과제와 겹치는 코드는 먼저 풀고 비교한다. 각 날짜의 개념 노트도 첫 풀이 이후에만 펼친다.



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
