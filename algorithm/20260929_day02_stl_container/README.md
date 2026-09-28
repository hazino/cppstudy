# Day 02 — 2026-09-29: STL 컨테이너

## 오늘의 목표

오늘의 주제를 설명하고 스스로 구현한다. 예제 읽기는 20분 이내, 문제 풀이를 우선한다.

## 핵심 개념

stack, queue, deque, priority_queue, set, map, unordered_map.

## No IntelliSense Drill

각 컨테이너의 선언·삽입·조회·삭제를 직접 작성한다.

## 온라인 문제

| Platform | Problem Name / Problem URL | Difficulty | Recommended Time | 핵심 학습 목표 | 파일 |
|---|---|---|---|---|---|
| Programmers | [올바른 괄호](https://school.programmers.co.kr/learn/courses/30/lessons/12909) | 기본 | 20분 | 조건 분석과 독립 구현 | `practice_01.cpp` |
| Programmers | [기능개발](https://school.programmers.co.kr/learn/courses/30/lessons/42586) | 실전 | 20분 | 조건 분석과 독립 구현 | `practice_02.cpp` |
| Programmers | [더 맵게](https://school.programmers.co.kr/learn/courses/30/lessons/42626) | 실전 | 45분 | 조건 분석과 독립 구현 | `practice_03.cpp` |

Difficulty의 기본·실전·도전은 이 계획의 학습 기준이며 공식 등급이 아니다. CodeTree의 Easy/Medium/Hard는 해당 페이지 표기다.

Programmers 고득점 Kit Stack/Queue 및 Heap 연습을 포함한다. 먼저 직접 풀고 컨테이너 선택 이유를 사후 기록한다.

[플랫폼별 제출·로컬 검증 방법](../README.md#플랫폼별-제출과-로컬-검증)을 따른다. 온라인 문제의 전체 지문은 저장소에 복사하지 않는다.

## 권장 시간

20분 손코딩 → practice_01 20분 + practice_02 20분 → practice_03 45분 → 로그 15분.

## 자주 하는 실수

빈 컨테이너 접근, 최대/최소 힙 방향, map 조회 중 삽입.

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
../run.sh stl_container.cpp
```

## 컨테이너 선택 기준

| 상황 | 컨테이너 | 시간 |
|---|---|---|
| 가장 최근 것부터 처리, 괄호 짝 | `stack` | O(1) |
| 들어온 순서대로 처리, BFS | `queue` | O(1) |
| 양쪽 삽입/삭제, 슬라이딩 윈도우 | `deque` | O(1) |
| 매번 최댓값/최솟값 꺼내기 | `priority_queue` | O(log N) |
| 중복 제거 + 정렬 유지, x 이상인 첫 값 | `set` / `multiset` | O(log N) |
| key-value, key 순서 필요 | `map` | O(log N) |
| key-value, 순서 불필요, 빠른 조회 | `unordered_map` | 평균 O(1) |

## 자주 하는 실수
- 빈 stack/queue에서 `top()` / `front()` 호출 → 미정의 동작
- `priority_queue`는 기본이 **최대 힙**
- `map[key]`로 조회만 해도 key가 생성됨 → `find`/`count` 사용
- `multiset.erase(x)`는 x를 **전부** 지움 → `erase(ms.find(x))`
- set에 `std::lower_bound(s.begin(), s.end(), x)` 쓰면 O(N) → `s.lower_bound(x)`


</details>
