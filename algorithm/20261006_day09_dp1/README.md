# Day 9 - 10/06 (화) : Dynamic Programming I

```bash
../run.sh dp1.cpp
```

## DP 풀이 순서
1. **State** : `dp[i]`가 무엇을 의미하는지 **한 문장으로** 쓴다
2. **Transition** : `dp[i]`를 더 작은 state로 표현 ("마지막 선택이 무엇이었나?")
3. **초기값** : 가장 작은 state (`dp[0]`, `dp[1]`)
4. **순서** : 작은 state → 큰 state
5. **답** : `dp[n]`인지, `max(dp[...])`인지

## Top-down vs Bottom-up
| | Top-down (재귀 + memo) | Bottom-up (반복문) |
|---|---|---|
| 장점 | 점화식 그대로, 필요한 state만 계산 | 빠름, 스택 오버플로 없음 |
| 주의 | memo 초기값(-1)과 실제 값 구분, 재귀 깊이 | 계산 순서를 직접 정해야 함 |

## 체크
- [ ] State가 한 차원으로 부족하면 차원 추가 (계단 오르기)
- [ ] 방법의 수는 `% MOD` 요구 여부 확인
- [ ] 값 크기 → `long long`

## 추천 문제 (BOJ)
- 1463 1로 만들기
- 9095 1, 2, 3 더하기
- 2579 계단 오르기
