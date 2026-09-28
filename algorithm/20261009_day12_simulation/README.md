# Day 12 — 2026-10-09: Implementation / Simulation

## 오늘의 목표

오늘의 주제를 설명하고 스스로 구현한다. 예제 읽기는 20분 이내, 문제 풀이를 우선한다.

## 핵심 개념

방향 이동, dx/dy, 상태 관리, 배열 처리.

## No IntelliSense Drill

규칙을 번호로 적고 상태 변화·이동·종료 조건을 함수로 작성한다.

## 온라인 문제

| Platform | Problem Name / Problem URL | Difficulty | Recommended Time | 핵심 학습 목표 | 파일 |
|---|---|---|---|---|---|
| CodeTree | [작은 구슬의 이동](https://www.codetree.ai/ko/trails/complete/curated-cards/intro-small-marble-movement/description) | Medium | 40분 | 조건 분석과 독립 구현 | `practice_01.cpp` |
| CodeTree | [빙빙 돌며 수로 직사각형 채우기](https://www.codetree.ai/ko/trails/complete/curated-cards/intro-snail-number-square/description) | Hard | 45분 | 조건 분석과 독립 구현 | `practice_02.cpp` |

Difficulty의 기본·실전·도전은 이 계획의 학습 기준이며 공식 등급이 아니다. CodeTree의 Easy/Medium/Hard는 해당 페이지 표기다.

구현 중점일이다. 두 CodeTree 문제를 브라우저에서 직접 작성하고 상태 변화와 규칙 적용 순서를 손으로 확인한다. Hard 표기는 이 레슨 안의 난이도이며 고급 알고리즘을 추가하는 뜻이 아니다.

[플랫폼별 제출·로컬 검증 방법](../README.md#플랫폼별-제출과-로컬-검증)을 따른다. 온라인 문제의 전체 지문은 저장소에 복사하지 않는다.

## 권장 시간

20분 No IntelliSense 손코딩 → 40분 기본 문제 → 45분 실전 문제 → 15분 오답·problem_log 기록 (총 120분).

## 자주 하는 실수

회전/이동 순서, 동시 갱신, 좌표 기준, 종료 누락.

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
../run.sh simulation.cpp
```

## 구현 문제 풀이 순서
1. 문제의 **규칙을 번호 매겨 한글로 정리** (코드 쓰기 전 5분)
2. 상태(State)를 정한다 : 위치, 방향, 보드, 시간, 점수...
3. 규칙 하나 = 함수 하나 (`move()`, `rotate()`, `check()`)
4. 예제 입력으로 **한 단계씩 출력**해서 손 계산과 비교

## 실수 포인트
- [ ] 방향 배열 순서 (북동남서 시계 방향으로 두면 회전 = `±1 % 4`)
- [ ] 좌회전은 `(d + 3) % 4` (음수 나머지 주의)
- [ ] 입력 좌표가 1-indexed인지 0-indexed인지
- [ ] "동시에" 일어나는 변화 → 복사본에 계산 후 한꺼번에 반영
- [ ] 이동 후 회전인지, 회전 후 이동인지 (문제 문장 그대로)


</details>
