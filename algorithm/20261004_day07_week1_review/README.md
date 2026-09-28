# Day 07 — 2026-10-04: Week 1 Review

## 오늘의 목표

오늘의 주제를 설명하고 스스로 구현한다. 예제 읽기는 20분 이내, 문제 풀이를 우선한다.

## 핵심 개념

STL 빈칸 Drill 및 핵심 알고리즘 회상.

## No IntelliSense Drill

BFS, DFS, Grid BFS, Binary Search, Dijkstra를 자동완성 없이 작성한다. 20분 동안 기억나는 구조부터 작성하고 미완성 항목은 약점 로그에 남긴다.

## 온라인 문제

| Platform | Problem Name / Problem URL | Difficulty | Recommended Time | 핵심 학습 목표 | 파일 |
|---|---|---|---|---|---|
| CodeTree | [되돌아오기](https://www.codetree.ai/ko/trails/complete/curated-cards/challenge-come-back/description) | Easy | 40분 | 조건 분석과 독립 구현 | `q1.cpp` |
| CodeTree | [되돌아오기 2](https://www.codetree.ai/ko/trails/complete/curated-cards/challenge-come-back-2/description) | Easy | 45분 | 조건 분석과 독립 구현 | `q2.cpp` |
| CodeTree | [격자 위의 편안한 상태](https://www.codetree.ai/ko/trails/complete/curated-cards/challenge-comfortable-state-on-the-grid/description) | Medium | 30분 | 조건 분석과 독립 구현 | `q3.cpp` |

Difficulty의 기본·실전·도전은 이 계획의 학습 기준이며 공식 등급이 아니다. CodeTree의 Easy/Medium/Hard는 해당 페이지 표기다.

[플랫폼별 제출·로컬 검증 방법](../README.md#플랫폼별-제출과-로컬-검증)을 따른다. 온라인 문제의 전체 지문은 저장소에 복사하지 않는다.

## 권장 시간

20분 STL·핵심 알고리즘 Drill → q1 40분 → q2 45분 → 로그 15분. q3는 선택 교체 문제다. Day 18의 a를 처음 보는 문제로 남기려면 q3는 열지 않는다.

## 자주 하는 실수

답안 먼저 열기, 초기화 누락, 한 문제에 시간 몰아쓰기.

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

</details>
