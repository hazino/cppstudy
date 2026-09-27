# Day 5 - 10/02 (금) : Binary Search

```bash
../run.sh binary_search.cpp
```

## 두 가지 구간 스타일 (하나만 골라서 손에 익히기)
| | 닫힌 구간 `[lo, hi]` | 반닫힌 구간 `[lo, hi)` |
|---|---|---|
| 반복 조건 | `lo <= hi` | `lo < hi` |
| 이동 | `lo = mid + 1`, `hi = mid - 1` | `lo = mid + 1`, `hi = mid` |
| 결과 | 조건 만족 시 `answer = mid`로 기록 | 루프 끝난 `lo`가 답 |

## Parameter Search 판별법
- "~의 **최댓값/최솟값**을 구하라" + 답의 범위가 매우 큼 (10^9 이상)
- 답을 X로 **고정**하면 "가능/불가능" 판정이 쉬움
- 판정 결과가 단조 (`T T T F F` 또는 `F F T T T`)

## 체크
- [ ] 정렬 안 된 배열에 이분 탐색하지 않기
- [ ] `lo`, `hi`, 합계는 `long long` (특히 Parameter Search)
- [ ] `hi` 초기값이 가능한 답을 전부 포함하는지

## 추천 문제 (BOJ)
- 1920 수 찾기
- 10816 숫자 카드 2 (lower/upper_bound)
- 2805 나무 자르기
- 1654 랜선 자르기
