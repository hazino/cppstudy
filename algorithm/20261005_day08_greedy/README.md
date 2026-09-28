# Day 08 — 2026-10-05: Greedy

## 오늘의 목표

오늘의 주제를 설명하고 스스로 구현한다. 예제 읽기는 20분 이내, 문제 풀이를 우선한다.

## 핵심 개념

sort + greedy, 선택의 타당성, 반례.

## No IntelliSense Drill

정렬 기준을 코드로 쓰기 전에 근거와 작은 반례 후보를 적는다.

## 온라인 문제

| Platform | Problem Name / Problem URL | Difficulty | Recommended Time | 핵심 학습 목표 | 파일 |
|---|---|---|---|---|---|
| Programmers | [체육복](https://school.programmers.co.kr/learn/courses/30/lessons/42862) | 기본 | 40분 | 조건 분석과 독립 구현 | `practice_01.cpp` |
| Programmers | [구명보트](https://school.programmers.co.kr/learn/courses/30/lessons/42885) | 실전 | 45분 | 조건 분석과 독립 구현 | `practice_02.cpp` |

Difficulty의 기본·실전·도전은 이 계획의 학습 기준이며 공식 등급이 아니다. CodeTree의 Easy/Medium/Hard는 해당 페이지 표기다.

[플랫폼별 제출·로컬 검증 방법](../README.md#플랫폼별-제출과-로컬-검증)을 따른다. 온라인 문제의 전체 지문은 저장소에 복사하지 않는다.

## 권장 시간

20분 No IntelliSense 손코딩 → 40분 기본 문제 → 45분 실전 문제 → 15분 오답·problem_log 기록 (총 120분).

## 자주 하는 실수

반례가 없다는 이유만으로 증명했다고 판단, 동률 처리.

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
../run.sh greedy.cpp
```

## Greedy를 의심할 신호
- "최대 개수", "최소 비용"인데 N이 커서 (10^5 이상) DP가 불가능
- **정렬 기준 하나**만 정하면 앞에서부터 결정 가능해 보임
- 매번 "가장 작은 것 / 가장 큰 것"을 꺼내는 구조 → `priority_queue`

## Greedy 성립 확인 (직관과 구분하기)
1. 정렬 기준을 2~3개 후보로 세운다 (시작 순, 끝 순, 길이 순...)
2. 각 후보에 **작은 반례**를 손으로 만들어 본다
3. 반례가 안 나오는 기준을 채택. 반례가 계속 나오면 → DP 검토

## 체크
- [ ] 동전 문제에서 그리디가 되는 조건 / 안 되는 조건
- [ ] 회의실 배정은 끝나는 시간 기준
- [ ] 합계가 `long long`이 필요한지


</details>
