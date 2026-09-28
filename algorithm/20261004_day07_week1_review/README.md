# Day 07 — 2026-10-04: Week 1 Review

## 오늘의 목표

오늘의 주제를 설명하고 스스로 구현한다. 예제 읽기는 20분 이내, 문제 풀이를 우선한다.

## 핵심 개념

STL 빈칸 Drill 및 핵심 알고리즘 회상.

## 반드시 직접 작성할 코드

BFS, DFS, Binary Search, Dijkstra를 자동완성 없이 작성한다.

## 오늘 풀 문제

| 순서 | 문제 | 풀이 파일 |
|---|---|---|
| 1 | [BOJ 1966 프린터 큐](https://www.acmicpc.net/problem/1966) | `q1.cpp` |
| 2 | [BOJ 2667 단지번호붙이기](https://www.acmicpc.net/problem/2667) | `q2.cpp` |
| 3 | [BOJ 2110 공유기 설치](https://www.acmicpc.net/problem/2110) | `q3.cpp` |

## 권장 시간

20분 빈칸 Drill → 40분 q1 → 45분 q2 → 15분 로그. q3는 선택 교체 문제이며 2시간에 세 문제를 모두 강제하지 않는다.

## 자주 발생하는 실수

답안 먼저 열기, 초기화 누락, 한 문제에 시간 몰아쓰기.

## 완료 체크리스트

- [ ] 코드를 보기 전에 직접 작성했다.
- [ ] 문제를 읽고 3~5분 안에 첫 접근과 복잡도를 적었다.
- [ ] 예제와 직접 만든 경계 사례를 확인했다.
- [ ] 결과·실패 원인·재도전 날짜를 [problem_log.md](../problem_log.md)에 기록했다.

[공통 풀이 원칙](../README.md#문제-풀이-원칙)을 따른다.

---

## 기존 개념 노트

## 1. 빈칸 드릴 (20분)
자료를 보지 않고 `blank_drill.cpp`의 TODO를 채운다. 테스트가 모두 PASS면 통과.
```bash
../run.sh blank_drill.cpp
```
처음 실행하면 전부 FAIL이 정상이다. 20분 안에 미완성한 항목은 Day 15 약점 대상으로 기록한다.
다 채운 뒤에 `blank_drill_answer.cpp`와 비교한다.

## Week 1 완료 조건
- [ ] C++ 기본 문법 때문에 막히지 않는다.
- [ ] 주요 STL을 바로 사용할 수 있다.
- [ ] BFS 직접 구현 가능
- [ ] DFS 직접 구현 가능
- [ ] Binary Search 직접 구현 가능
- [ ] Dijkstra 직접 구현 가능
