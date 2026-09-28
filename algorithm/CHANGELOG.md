# 변경 파일 목록 — CodeTree / Programmers 전환

## 변경 이유

- 20일 일정과 기존 개념 자료를 유지하면서 온라인 학습의 주 플랫폼을 CodeTree, 보조 플랫폼을 Programmers로 전환했다. LeetCode는 선택 보충이다.
- 이전 채점 사이트의 문제 번호·링크·문제별 파일명을 현재 학습 계획에서 제거했다. 모든 문제 파일은 TODO 상태이며 지문이나 정답은 복사하지 않았다.
- Day 10 폴더는 `20261007_day10_prefix_sum`으로 이름을 정리했다. 기존 dp2.cpp와 prefix_sum.cpp의 내용은 그대로 이동했다.
- 일반 날짜의 문제 파일은 practice_01.cpp 형태로 통일하고, 기존 실전 폴더의 q1.cpp 및 a.cpp 형태는 유지했다.
- 고급 DP와 위상 정렬 자료는 이번 계획 밖의 과거 참고자료로 보존했다.

## 검증 범위

- 공식 Programmers 문제 본문 및 C++ 선택 항목 확인. CodeTree 지정 구현·누적합 문제의 제목·난이도·문제 탭·편집기 확인.
- CodeTree 그래프 과정 탐색은 로그인·이용권 안내로 개별 문제 검증에 제한이 있어 Day 6/11에 선택 기록란과 확인된 대체 문제 제공.
- 온라인 제출·계정별 채점 권한 확인은 수행하지 않음.
- 이전 작업에서 Windows 애플리케이션 제어 정책이 g++.exe 실행을 차단했으므로 이번 변경의 컴파일·런타임 통과를 주장하지 않음.

## 파일별 변경

| 파일 | 변경 이유 및 내용 |
|---|---|
| [README.md](../README.md) | 학습 플랫폼과 Browser First 원칙 안내 |
| [algorithm/20260928_day01_stl_basic/README.md](20260928_day01_stl_basic/README.md) | 7개 공통 항목 및 플랫폼·이름·URL·난이도·시간·목표, 기존 개념 노트 보존 |
| [algorithm/20260928_day01_stl_basic/input/README.md](20260928_day01_stl_basic/input/README.md) | 표준 입출력과 함수 인자 검증의 차이, 로컬 실행 안내 |
| [algorithm/20260928_day01_stl_basic/practice_01.cpp](20260928_day01_stl_basic/practice_01.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20260928_day01_stl_basic/practice_02.cpp](20260928_day01_stl_basic/practice_02.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20260929_day02_stl_container/README.md](20260929_day02_stl_container/README.md) | 7개 공통 항목 및 플랫폼·이름·URL·난이도·시간·목표, 기존 개념 노트 보존 |
| [algorithm/20260929_day02_stl_container/input/README.md](20260929_day02_stl_container/input/README.md) | 표준 입출력과 함수 인자 검증의 차이, 로컬 실행 안내 |
| [algorithm/20260929_day02_stl_container/practice_01.cpp](20260929_day02_stl_container/practice_01.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20260929_day02_stl_container/practice_02.cpp](20260929_day02_stl_container/practice_02.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20260929_day02_stl_container/practice_03.cpp](20260929_day02_stl_container/practice_03.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20260930_day03_bfs_dfs/README.md](20260930_day03_bfs_dfs/README.md) | 7개 공통 항목 및 플랫폼·이름·URL·난이도·시간·목표, 기존 개념 노트 보존 |
| [algorithm/20260930_day03_bfs_dfs/input/README.md](20260930_day03_bfs_dfs/input/README.md) | 표준 입출력과 함수 인자 검증의 차이, 로컬 실행 안내 |
| [algorithm/20260930_day03_bfs_dfs/practice_01.cpp](20260930_day03_bfs_dfs/practice_01.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20260930_day03_bfs_dfs/practice_02.cpp](20260930_day03_bfs_dfs/practice_02.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261001_day04_grid_bfs/README.md](20261001_day04_grid_bfs/README.md) | 7개 공통 항목 및 플랫폼·이름·URL·난이도·시간·목표, 기존 개념 노트 보존 |
| [algorithm/20261001_day04_grid_bfs/input/README.md](20261001_day04_grid_bfs/input/README.md) | 표준 입출력과 함수 인자 검증의 차이, 로컬 실행 안내 |
| [algorithm/20261001_day04_grid_bfs/practice_01.cpp](20261001_day04_grid_bfs/practice_01.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261001_day04_grid_bfs/practice_02.cpp](20261001_day04_grid_bfs/practice_02.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261002_day05_binary_search/README.md](20261002_day05_binary_search/README.md) | 7개 공통 항목 및 플랫폼·이름·URL·난이도·시간·목표, 기존 개념 노트 보존 |
| [algorithm/20261002_day05_binary_search/input/README.md](20261002_day05_binary_search/input/README.md) | 표준 입출력과 함수 인자 검증의 차이, 로컬 실행 안내 |
| [algorithm/20261002_day05_binary_search/practice_01.cpp](20261002_day05_binary_search/practice_01.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261002_day05_binary_search/practice_02.cpp](20261002_day05_binary_search/practice_02.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261003_day06_dijkstra/README.md](20261003_day06_dijkstra/README.md) | 7개 공통 항목 및 플랫폼·이름·URL·난이도·시간·목표, 기존 개념 노트 보존 |
| [algorithm/20261003_day06_dijkstra/input/README.md](20261003_day06_dijkstra/input/README.md) | 표준 입출력과 함수 인자 검증의 차이, 로컬 실행 안내 |
| [algorithm/20261003_day06_dijkstra/practice_01.cpp](20261003_day06_dijkstra/practice_01.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261003_day06_dijkstra/practice_02.cpp](20261003_day06_dijkstra/practice_02.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261004_day07_week1_review/README.md](20261004_day07_week1_review/README.md) | 7개 공통 항목 및 플랫폼·이름·URL·난이도·시간·목표, 기존 개념 노트 보존 |
| [algorithm/20261004_day07_week1_review/input/README.md](20261004_day07_week1_review/input/README.md) | 표준 입출력과 함수 인자 검증의 차이, 로컬 실행 안내 |
| [algorithm/20261004_day07_week1_review/q1.cpp](20261004_day07_week1_review/q1.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261004_day07_week1_review/q2.cpp](20261004_day07_week1_review/q2.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261004_day07_week1_review/q3.cpp](20261004_day07_week1_review/q3.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261005_day08_greedy/README.md](20261005_day08_greedy/README.md) | 7개 공통 항목 및 플랫폼·이름·URL·난이도·시간·목표, 기존 개념 노트 보존 |
| [algorithm/20261005_day08_greedy/input/README.md](20261005_day08_greedy/input/README.md) | 표준 입출력과 함수 인자 검증의 차이, 로컬 실행 안내 |
| [algorithm/20261005_day08_greedy/practice_01.cpp](20261005_day08_greedy/practice_01.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261005_day08_greedy/practice_02.cpp](20261005_day08_greedy/practice_02.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261006_day09_dp/README.md](20261006_day09_dp/README.md) | 7개 공통 항목 및 플랫폼·이름·URL·난이도·시간·목표, 기존 개념 노트 보존 |
| [algorithm/20261006_day09_dp/input/README.md](20261006_day09_dp/input/README.md) | 표준 입출력과 함수 인자 검증의 차이, 로컬 실행 안내 |
| [algorithm/20261006_day09_dp/practice_01.cpp](20261006_day09_dp/practice_01.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261006_day09_dp/practice_02.cpp](20261006_day09_dp/practice_02.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261007_day10_prefix_sum/README.md](20261007_day10_prefix_sum/README.md) | 7개 공통 항목 및 플랫폼·이름·URL·난이도·시간·목표, 기존 개념 노트 보존 |
| [algorithm/20261007_day10_prefix_sum/dp2.cpp](20261007_day10_prefix_sum/dp2.cpp) | Day 10 폴더 이름 변경에 따라 내용 그대로 이동 |
| [algorithm/20261007_day10_prefix_sum/input/README.md](20261007_day10_prefix_sum/input/README.md) | 표준 입출력과 함수 인자 검증의 차이, 로컬 실행 안내 |
| [algorithm/20261007_day10_prefix_sum/practice_01.cpp](20261007_day10_prefix_sum/practice_01.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261007_day10_prefix_sum/practice_02.cpp](20261007_day10_prefix_sum/practice_02.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261007_day10_prefix_sum/prefix_sum.cpp](20261007_day10_prefix_sum/prefix_sum.cpp) | Day 10 폴더 이름 변경에 따라 내용 그대로 이동 |
| [algorithm/20261008_day11_graph_practice/README.md](20261008_day11_graph_practice/README.md) | 7개 공통 항목 및 플랫폼·이름·URL·난이도·시간·목표, 기존 개념 노트 보존 |
| [algorithm/20261008_day11_graph_practice/input/README.md](20261008_day11_graph_practice/input/README.md) | 표준 입출력과 함수 인자 검증의 차이, 로컬 실행 안내 |
| [algorithm/20261008_day11_graph_practice/practice_01.cpp](20261008_day11_graph_practice/practice_01.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261008_day11_graph_practice/practice_02.cpp](20261008_day11_graph_practice/practice_02.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261009_day12_simulation/README.md](20261009_day12_simulation/README.md) | 7개 공통 항목 및 플랫폼·이름·URL·난이도·시간·목표, 기존 개념 노트 보존 |
| [algorithm/20261009_day12_simulation/input/README.md](20261009_day12_simulation/input/README.md) | 표준 입출력과 함수 인자 검증의 차이, 로컬 실행 안내 |
| [algorithm/20261009_day12_simulation/practice_01.cpp](20261009_day12_simulation/practice_01.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261009_day12_simulation/practice_02.cpp](20261009_day12_simulation/practice_02.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261009_day12_simulation/simulation.cpp](20261009_day12_simulation/simulation.cpp) | 기존 로직 보존, 외부 문제 번호 주석 제거 |
| [algorithm/20261010_day13_backtracking/README.md](20261010_day13_backtracking/README.md) | 7개 공통 항목 및 플랫폼·이름·URL·난이도·시간·목표, 기존 개념 노트 보존 |
| [algorithm/20261010_day13_backtracking/input/README.md](20261010_day13_backtracking/input/README.md) | 표준 입출력과 함수 인자 검증의 차이, 로컬 실행 안내 |
| [algorithm/20261010_day13_backtracking/practice_01.cpp](20261010_day13_backtracking/practice_01.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261010_day13_backtracking/practice_02.cpp](20261010_day13_backtracking/practice_02.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261011_day14_week2_mini_test/README.md](20261011_day14_week2_mini_test/README.md) | 7개 공통 항목 및 플랫폼·이름·URL·난이도·시간·목표, 기존 개념 노트 보존 |
| [algorithm/20261011_day14_week2_mini_test/input/README.md](20261011_day14_week2_mini_test/input/README.md) | 표준 입출력과 함수 인자 검증의 차이, 로컬 실행 안내 |
| [algorithm/20261011_day14_week2_mini_test/q1.cpp](20261011_day14_week2_mini_test/q1.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261011_day14_week2_mini_test/q2.cpp](20261011_day14_week2_mini_test/q2.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261011_day14_week2_mini_test/q3.cpp](20261011_day14_week2_mini_test/q3.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261012_day15_weak_point/README.md](20261012_day15_weak_point/README.md) | 7개 공통 항목 및 플랫폼·이름·URL·난이도·시간·목표, 기존 개념 노트 보존 |
| [algorithm/20261012_day15_weak_point/input/README.md](20261012_day15_weak_point/input/README.md) | 표준 입출력과 함수 인자 검증의 차이, 로컬 실행 안내 |
| [algorithm/20261012_day15_weak_point/weak1.cpp](20261012_day15_weak_point/weak1.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261012_day15_weak_point/weak2.cpp](20261012_day15_weak_point/weak2.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261013_day16_mixed/README.md](20261013_day16_mixed/README.md) | 7개 공통 항목 및 플랫폼·이름·URL·난이도·시간·목표, 기존 개념 노트 보존 |
| [algorithm/20261013_day16_mixed/input/README.md](20261013_day16_mixed/input/README.md) | 표준 입출력과 함수 인자 검증의 차이, 로컬 실행 안내 |
| [algorithm/20261013_day16_mixed/q1.cpp](20261013_day16_mixed/q1.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261013_day16_mixed/q2.cpp](20261013_day16_mixed/q2.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261013_day16_mixed/q3.cpp](20261013_day16_mixed/q3.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261014_day17_speed/README.md](20261014_day17_speed/README.md) | 7개 공통 항목 및 플랫폼·이름·URL·난이도·시간·목표, 기존 개념 노트 보존 |
| [algorithm/20261014_day17_speed/input/README.md](20261014_day17_speed/input/README.md) | 표준 입출력과 함수 인자 검증의 차이, 로컬 실행 안내 |
| [algorithm/20261014_day17_speed/q1.cpp](20261014_day17_speed/q1.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261014_day17_speed/q2.cpp](20261014_day17_speed/q2.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261014_day17_speed/q3.cpp](20261014_day17_speed/q3.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261014_day17_speed/q4.cpp](20261014_day17_speed/q4.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261014_day17_speed/q5.cpp](20261014_day17_speed/q5.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261015_day18_mock_test1/README.md](20261015_day18_mock_test1/README.md) | 7개 공통 항목 및 플랫폼·이름·URL·난이도·시간·목표, 기존 개념 노트 보존 |
| [algorithm/20261015_day18_mock_test1/a.cpp](20261015_day18_mock_test1/a.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261015_day18_mock_test1/b.cpp](20261015_day18_mock_test1/b.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261015_day18_mock_test1/c.cpp](20261015_day18_mock_test1/c.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261015_day18_mock_test1/d.cpp](20261015_day18_mock_test1/d.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261015_day18_mock_test1/e.cpp](20261015_day18_mock_test1/e.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261015_day18_mock_test1/input/README.md](20261015_day18_mock_test1/input/README.md) | 표준 입출력과 함수 인자 검증의 차이, 로컬 실행 안내 |
| [algorithm/20261016_day19_mock_review/README.md](20261016_day19_mock_review/README.md) | 7개 공통 항목 및 플랫폼·이름·URL·난이도·시간·목표, 기존 개념 노트 보존 |
| [algorithm/20261016_day19_mock_review/input/README.md](20261016_day19_mock_review/input/README.md) | 표준 입출력과 함수 인자 검증의 차이, 로컬 실행 안내 |
| [algorithm/20261016_day19_mock_review/retry_a.cpp](20261016_day19_mock_review/retry_a.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261016_day19_mock_review/retry_b.cpp](20261016_day19_mock_review/retry_b.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261017_day20_final_review/README.md](20261017_day20_final_review/README.md) | 7개 공통 항목 및 플랫폼·이름·URL·난이도·시간·목표, 기존 개념 노트 보존 |
| [algorithm/20261017_day20_final_review/drill.cpp](20261017_day20_final_review/drill.cpp) | 플랫폼 중립 미완성 skeleton 및 문제 메타데이터; 정답 알고리즘 없음 |
| [algorithm/20261017_day20_final_review/input/README.md](20261017_day20_final_review/input/README.md) | 표준 입출력과 함수 인자 검증의 차이, 로컬 실행 안내 |
| [algorithm/20261017_day20_final_review/templates.cpp](20261017_day20_final_review/templates.cpp) | vector/pair·stack·map/set 회상 예제와 검사 보완 |
| [algorithm/CHANGELOG.md](CHANGELOG.md) | 현재 변경 파일 및 확인 범위 기록 |
| [algorithm/README.md](README.md) | 플랫폼 우선순위, 제출 방식, 범위·일정, No IntelliSense·AI 사용 규칙 |
| [algorithm/problem_log.md](problem_log.md) | Platform·Selected Algorithm·Retry Date와 8개 실패 원인 |

## 보존한 실행 환경

`run.sh`, `_template/main.cpp`, `.gitignore`와 C++17 설정은 이번에 변경하지 않았다. `.bin/`은 계속 Git에서 제외된다. 기존 알고리즘 예제는 마지막 STL 보완과 주석 정리 외에는 변경하지 않았다.
