# Day 02 — 2026-09-29: STL 컨테이너

## 오늘의 목표

오늘의 주제를 설명하고 스스로 구현한다. 예제 읽기는 20분 이내, 문제 풀이를 우선한다.

## 핵심 개념

stack, queue, deque, priority_queue, set, map, unordered_map.

## 반드시 직접 작성할 코드

각 컨테이너의 선언·삽입·조회·삭제를 직접 작성한다.

## 오늘 풀 문제

| 순서 | 문제 | 풀이 파일 |
|---|---|---|
| 1 | [BOJ 10828 스택](https://www.acmicpc.net/problem/10828) | `boj_10828.cpp` |
| 2 | [BOJ 18258 큐 2](https://www.acmicpc.net/problem/18258) | `boj_18258.cpp` |
| 3 | [BOJ 11279 최대 힙](https://www.acmicpc.net/problem/11279) | `boj_11279.cpp` |

## 권장 시간

20분 손코딩 → 스택 20분 + 큐 20분 → 최대 힙 45분 → 로그 15분. 미완료는 Day 7/15에서 재도전한다.

## 자주 발생하는 실수

빈 컨테이너 접근, 최대/최소 힙 방향, map 조회 중 삽입.

## 완료 체크리스트

- [ ] 코드를 보기 전에 직접 작성했다.
- [ ] 문제를 읽고 3~5분 안에 첫 접근과 복잡도를 적었다.
- [ ] 예제와 직접 만든 경계 사례를 확인했다.
- [ ] 결과·실패 원인·재도전 날짜를 [problem_log.md](../problem_log.md)에 기록했다.

[공통 풀이 원칙](../README.md#문제-풀이-원칙)을 따른다.

---

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

## 선택 추가 문제 (필수 풀이 완료 후)
- 9012 괄호
- 1158 요세푸스 문제
- 1927 최소 힙
- 10816 숫자 카드 2 (map)
