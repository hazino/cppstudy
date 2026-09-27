# Day 2 - 09/29 (화) : STL 자료구조

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

## 추천 문제 (BOJ)
- 9012 괄호
- 1158 요세푸스 문제
- 1927 최소 힙
- 10816 숫자 카드 2 (map)
