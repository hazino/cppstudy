# Day 13 - 10/10 (토) : Combination / Backtracking

```bash
../run.sh backtracking.cpp
```

## Backtracking 기본 Template
```cpp
void dfs(int depth /* 상태 */) {
    if (종료 조건) { 결과 처리; return; }
    for (선택지 : 후보들) {
        if (불가능) continue;   // Pruning
        선택;                   // 상태 변경
        dfs(depth + 1);
        선택 취소;              // 상태 복구
    }
}
```

## 경우의 수 감각 (1초 ≈ 10^8 연산)
| 탐색 | 개수 | 가능한 N |
|---|---|---|
| 순열 N! | 10! ≈ 3.6×10^6 | N ≤ 10 |
| 부분 집합 2^N | 2^20 ≈ 10^6 | N ≤ 20 |
| 조합 nCr | 20C10 ≈ 1.8×10^5 | N ≤ 25 정도 |

## 체크
- [ ] 순열(used 배열) / 조합(start 인덱스) 구분
- [ ] 재귀 후 상태 복구 빠뜨리지 않기
- [ ] 전역 변수 초기화 (테스트 케이스 여러 개)
- [ ] `next_permutation`은 정렬된 상태에서 시작

## 추천 문제 (BOJ)
- 15649 N과 M (1) ~ 15652 N과 M (4)
- 1182 부분수열의 합
- 9663 N-Queen
- 14502 연구소 (조합 + BFS)
