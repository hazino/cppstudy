# Day 20 - 시험 전날 또는 D-2 : Final Review

> 시험 날짜가 정해지면 폴더 이름의 날짜를 맞춰 바꾼다.

```bash
../run.sh templates.cpp
```

새로운 알고리즘 학습 X. `templates.cpp`를 보고 **빈 파일에 한 번씩 다시 써 본다.**

- [ ] BFS
- [ ] DFS
- [ ] Dijkstra
- [ ] Binary Search
- [ ] Priority Queue
- [ ] Sort Comparator
- [ ] DP 기본
- [ ] Backtracking
- [ ] Grid Search

## 입력 크기 → 허용 복잡도 (1초 ≈ 10^8)
| N | 복잡도 | 대표 알고리즘 |
|---|---|---|
| ≤ 10 | O(N!) | 순열 완전 탐색 |
| ≤ 20 | O(2^N) | 부분 집합, 비트마스크 |
| ≤ 500 | O(N³) | Floyd-Warshall, 3중 루프 DP |
| ≤ 5,000 | O(N²) | 2중 루프 DP |
| ≤ 10^6 | O(N log N) | 정렬, 이분 탐색, Dijkstra, 우선순위 큐 |
| ≤ 10^8 | O(N) | 투 포인터, 누적합, 그리디 |
| > 10^8 | O(log N) | 이분 탐색, 수학 |

## 시험 전략
1. 전체 문제를 먼저 확인한다.
2. 확실히 풀 수 있는 문제부터 해결한다.
3. 한 문제에 과도하게 시간을 사용하지 않는다.
4. 제출 전 Boundary / Overflow / Index를 확인한다.

## 제출 전 체크리스트
- [ ] `int` 범위 (약 2.1×10^9) 넘는 값 → `long long`
- [ ] 배열 크기 / 1-indexed 여부
- [ ] N = 1, N = 최대일 때
- [ ] 테스트 케이스가 여러 개면 전역 변수 초기화
- [ ] 출력 형식 (공백, 줄바꿈, 소수점)
- [ ] 디버그 출력 지웠는지
