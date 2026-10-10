# 문제 링크 점검 — 2026-10-05 (Asia/Seoul)

저장소의 중복을 제외한 문제 링크 38개를 Codex 내장 브라우저의 로그아웃 상태에서 실제로 열어 확인했다. 검색 결과나 HTTP 응답 코드만으로 판정하지 않았다.

## 결과와 한계

- Programmers 28개: 문제 제목·본문·편집기 표시 확인. 로그아웃 상태의 로그인 링크 표시. 로그인 후 실행·제출은 확인하지 않았다.
- CodeTree 9개: 로딩 완료 후 제목·입력 본문·편집기 표시 확인. 계정별 이용권 및 실제 제출 성공은 확인하지 않았다.
- LeetCode 1개: 문제 본문 표시 확인. 실행·제출에 로그인이 필요하다는 안내 표시.
- 12930은 사용자 환경에서 “여긴 당신이 찾는 웹페이지가 아니에요 / 404 Page not found”가 보고됐다. 확인 브라우저에서는 본문과 편집기가 열려 결과가 불일치한다. 원인은 미확정이며 정상 이용을 보장하지 않는다.
- 대체 문제 12917(문자열 내림차순으로 배치하기)도 확인 브라우저에서 제목·본문·편집기가 열렸다. 사용자 환경의 접근 성공은 아직 확인하지 않았다.

## 12930이 열리지 않을 때

주소 끝의 문장부호 없이 원래 링크를 복사해 일반 브라우저에서 확인한다. 같은 404라면 [공식 문제 목록](https://school.programmers.co.kr/learn/challenges)에서 제목으로 검색하거나 [대체 문제](https://school.programmers.co.kr/learn/courses/30/lessons/12917)를 사용한다. 로그인·캐시·브라우저·네트워크 중 어느 것이 원인인지는 현재 증거로 특정할 수 없다.

Day 1의 practice_02.cpp와 Day 17의 q4.cpp를 그대로 사용하고, 대체 문제를 선택했을 때만 상단 메타데이터를 변경한다. 정답 파일을 추가하거나 온라인 지문을 복사하지 않는다.

## 2026-10-10 구성 변경

Day 3의 두 번째 문제를 네트워크 재풀이에서 타겟 넘버로 변경하고 아래 사용 파일 목록에 반영했다. 타겟 넘버 공식 페이지의 본문을 다시 확인했다. 아래 브라우저 점검 결과의 기준일은 기존 2026-10-05이며, 이번에 전체 링크를 재점검한 것은 아니다.

## 전체 문제별 확인

| Platform | 문제 | 확인 결과 | 사용 파일 |
|---|---|---|---|
| LeetCode | [Network Delay Time](https://leetcode.com/problems/network-delay-time/) | 본문 표시; 실행·제출 로그인 필요 | [20261003_day06_dijkstra/practice_02.cpp](20261003_day06_dijkstra/practice_02.cpp) |
| Programmers | [성격 유형 검사하기](https://school.programmers.co.kr/learn/courses/30/lessons/118666) | 본문·편집기 표시; 제출 미확인 | [20261014_day17_speed/q3.cpp](20261014_day17_speed/q3.cpp) |
| Programmers | [올바른 괄호](https://school.programmers.co.kr/learn/courses/30/lessons/12909) | 본문·편집기 표시; 제출 미확인 | [20260929_day02_stl_container/practice_01.cpp](20260929_day02_stl_container/practice_01.cpp) |
| Programmers | [멀리 뛰기](https://school.programmers.co.kr/learn/courses/30/lessons/12914) | 본문·편집기 표시; 제출 미확인 | [20261006_day09_dp/practice_02.cpp](20261006_day09_dp/practice_02.cpp) |
| Programmers | [야근 지수](https://school.programmers.co.kr/learn/courses/30/lessons/12927) | 본문·편집기 표시; 제출 미확인 | [20261015_day18_mock_test1/c.cpp](20261015_day18_mock_test1/c.cpp) |
| Programmers | [이상한 문자 만들기](https://school.programmers.co.kr/learn/courses/30/lessons/12930) | 사용자: 404 / 확인 브라우저: 본문·편집기 표시 — 불일치 | [20260928_day01_stl_basic/practice_02.cpp](20260928_day01_stl_basic/practice_02.cpp), [20261014_day17_speed/q4.cpp](20261014_day17_speed/q4.cpp) |
| Programmers | [피보나치 수](https://school.programmers.co.kr/learn/courses/30/lessons/12945) | 본문·편집기 표시; 제출 미확인 | [20261006_day09_dp/practice_01.cpp](20261006_day09_dp/practice_01.cpp) |
| Programmers | [배달](https://school.programmers.co.kr/learn/courses/30/lessons/12978) | 본문·편집기 표시; 제출 미확인 | [20261003_day06_dijkstra/practice_01.cpp](20261003_day06_dijkstra/practice_01.cpp), [20261008_day11_graph_practice/practice_02.cpp](20261008_day11_graph_practice/practice_02.cpp) |
| Programmers | [예산](https://school.programmers.co.kr/learn/courses/30/lessons/12982) | 본문·편집기 표시; 제출 미확인 | [20261014_day17_speed/q5.cpp](20261014_day17_speed/q5.cpp) |
| Programmers | [무인도 여행](https://school.programmers.co.kr/learn/courses/30/lessons/154540) | 본문·편집기 표시; 제출 미확인 | [20261011_day14_week2_mini_test/q2.cpp](20261011_day14_week2_mini_test/q2.cpp) |
| Programmers | [미로 탈출](https://school.programmers.co.kr/learn/courses/30/lessons/159993) | 본문·편집기 표시; 제출 미확인 | [20261015_day18_mock_test1/d.cpp](20261015_day18_mock_test1/d.cpp) |
| Programmers | [게임 맵 최단거리](https://school.programmers.co.kr/learn/courses/30/lessons/1844) | 본문·편집기 표시; 제출 미확인 | [20261001_day04_grid_bfs/practice_01.cpp](20261001_day04_grid_bfs/practice_01.cpp), [20261001_day04_grid_bfs/practice_02.cpp](20261001_day04_grid_bfs/practice_02.cpp) |
| Programmers | [다리를 지나는 트럭](https://school.programmers.co.kr/learn/courses/30/lessons/42583) | 본문·편집기 표시; 제출 미확인 | [20261011_day14_week2_mini_test/q1.cpp](20261011_day14_week2_mini_test/q1.cpp) |
| Programmers | [기능개발](https://school.programmers.co.kr/learn/courses/30/lessons/42586) | 본문·편집기 표시; 제출 미확인 | [20260929_day02_stl_container/practice_02.cpp](20260929_day02_stl_container/practice_02.cpp) |
| Programmers | [프로세스](https://school.programmers.co.kr/learn/courses/30/lessons/42587) | 본문·편집기 표시; 제출 미확인 | [20261011_day14_week2_mini_test/q3.cpp](20261011_day14_week2_mini_test/q3.cpp) |
| Programmers | [더 맵게](https://school.programmers.co.kr/learn/courses/30/lessons/42626) | 본문·편집기 표시; 제출 미확인 | [20260929_day02_stl_container/practice_03.cpp](20260929_day02_stl_container/practice_03.cpp) |
| Programmers | [K번째수](https://school.programmers.co.kr/learn/courses/30/lessons/42748) | 본문·편집기 표시; 제출 미확인 | [20260928_day01_stl_basic/practice_01.cpp](20260928_day01_stl_basic/practice_01.cpp) |
| Programmers | [체육복](https://school.programmers.co.kr/learn/courses/30/lessons/42862) | 본문·편집기 표시; 제출 미확인 | [20261005_day08_greedy/practice_01.cpp](20261005_day08_greedy/practice_01.cpp) |
| Programmers | [구명보트](https://school.programmers.co.kr/learn/courses/30/lessons/42885) | 본문·편집기 표시; 제출 미확인 | [20261005_day08_greedy/practice_02.cpp](20261005_day08_greedy/practice_02.cpp) |
| Programmers | [네트워크](https://school.programmers.co.kr/learn/courses/30/lessons/43162) | 본문·편집기 표시; 제출 미확인 | [20260930_day03_bfs_dfs/practice_01.cpp](20260930_day03_bfs_dfs/practice_01.cpp) |
| Programmers | [단어 변환](https://school.programmers.co.kr/learn/courses/30/lessons/43163) | 본문·편집기 표시; 제출 미확인 | [20261008_day11_graph_practice/practice_01.cpp](20261008_day11_graph_practice/practice_01.cpp) |
| Programmers | [타겟 넘버](https://school.programmers.co.kr/learn/courses/30/lessons/43165) | 본문·편집기 표시; 제출 미확인 | [20260930_day03_bfs_dfs/practice_02.cpp](20260930_day03_bfs_dfs/practice_02.cpp), [20261013_day16_mixed/q2.cpp](20261013_day16_mixed/q2.cpp) |
| Programmers | [입국심사](https://school.programmers.co.kr/learn/courses/30/lessons/43238) | 본문·편집기 표시; 제출 미확인 | [20261002_day05_binary_search/practice_01.cpp](20261002_day05_binary_search/practice_01.cpp), [20261002_day05_binary_search/practice_02.cpp](20261002_day05_binary_search/practice_02.cpp) |
| Programmers | [방문 길이](https://school.programmers.co.kr/learn/courses/30/lessons/49994) | 본문·편집기 표시; 제출 미확인 | [20261015_day18_mock_test1/b.cpp](20261015_day18_mock_test1/b.cpp) |
| Programmers | [문자열 압축](https://school.programmers.co.kr/learn/courses/30/lessons/60057) | 본문·편집기 표시; 제출 미확인 | [20261013_day16_mixed/q1.cpp](20261013_day16_mixed/q1.cpp) |
| Programmers | [합승 택시 요금](https://school.programmers.co.kr/learn/courses/30/lessons/72413) | 본문·편집기 표시; 제출 미확인 | [20261015_day18_mock_test1/e.cpp](20261015_day18_mock_test1/e.cpp) |
| Programmers | [괄호 회전하기](https://school.programmers.co.kr/learn/courses/30/lessons/76502) | 본문·편집기 표시; 제출 미확인 | [20261013_day16_mixed/q3.cpp](20261013_day16_mixed/q3.cpp) |
| Programmers | [최소직사각형](https://school.programmers.co.kr/learn/courses/30/lessons/86491) | 본문·편집기 표시; 제출 미확인 | [20261010_day13_backtracking/practice_01.cpp](20261010_day13_backtracking/practice_01.cpp) |
| Programmers | [피로도](https://school.programmers.co.kr/learn/courses/30/lessons/87946) | 본문·편집기 표시; 제출 미확인 | [20261010_day13_backtracking/practice_02.cpp](20261010_day13_backtracking/practice_02.cpp) |
| CodeTree | [되돌아오기 2](https://www.codetree.ai/ko/trails/complete/curated-cards/challenge-come-back-2/description) | 본문·편집기 표시; 제출 미확인 | [20261004_day07_week1_review/q2.cpp](20261004_day07_week1_review/q2.cpp) |
| CodeTree | [되돌아오기](https://www.codetree.ai/ko/trails/complete/curated-cards/challenge-come-back/description) | 본문·편집기 표시; 제출 미확인 | [20261004_day07_week1_review/q1.cpp](20261004_day07_week1_review/q1.cpp) |
| CodeTree | [격자 위의 편안한 상태](https://www.codetree.ai/ko/trails/complete/curated-cards/challenge-comfortable-state-on-the-grid/description) | 본문·편집기 표시; 제출 미확인 | [20261004_day07_week1_review/q3.cpp](20261004_day07_week1_review/q3.cpp), [20261015_day18_mock_test1/a.cpp](20261015_day18_mock_test1/a.cpp) |
| CodeTree | [방향에 맞춰 이동](https://www.codetree.ai/ko/trails/complete/curated-cards/intro-move-in-direction/description) | 본문·편집기 표시; 제출 미확인 | [20261014_day17_speed/q1.cpp](20261014_day17_speed/q1.cpp) |
| CodeTree | [작은 구슬의 이동](https://www.codetree.ai/ko/trails/complete/curated-cards/intro-small-marble-movement/description) | 본문·편집기 표시; 제출 미확인 | [20261009_day12_simulation/practice_01.cpp](20261009_day12_simulation/practice_01.cpp) |
| CodeTree | [빙빙 돌며 수로 직사각형 채우기](https://www.codetree.ai/ko/trails/complete/curated-cards/intro-snail-number-square/description) | 본문·편집기 표시; 제출 미확인 | [20261009_day12_simulation/practice_02.cpp](20261009_day12_simulation/practice_02.cpp) |
| CodeTree | [정수 N개의 합 2](https://www.codetree.ai/ko/trails/complete/curated-cards/intro-sum-of-n-integers-2/description) | 본문·편집기 표시; 제출 미확인 | [20261007_day10_prefix_sum/practice_01.cpp](20261007_day10_prefix_sum/practice_01.cpp) |
| CodeTree | [정수 N개의 합 3](https://www.codetree.ai/ko/trails/complete/curated-cards/intro-sum-of-n-integers-3/description) | 본문·편집기 표시; 제출 미확인 | [20261007_day10_prefix_sum/practice_02.cpp](20261007_day10_prefix_sum/practice_02.cpp) |
| CodeTree | [문자에 따른 명령 2](https://www.codetree.ai/ko/trails/complete/curated-cards/intro-text-based-commands2/description) | 본문·편집기 표시; 제출 미확인 | [20261014_day17_speed/q2.cpp](20261014_day17_speed/q2.cpp) |
