# Day 01 — 2026-09-28: STL 기본 복구

## 오늘의 목표

오늘의 주제를 설명하고 스스로 구현한다. 예제 읽기는 20분 이내, 문제 풀이를 우선한다.

## 핵심 개념

vector, string, sort, lambda, iterator, pair.

## No IntelliSense Drill

vector 순회와 iterator 접근, pair 정렬 및 lambda 비교자를 빈 파일에 작성한다.

## 온라인 문제

| Platform | Problem Name / Problem URL | Difficulty | Recommended Time | 핵심 학습 목표 | 파일 |
|---|---|---|---|---|---|
| Programmers | [K번째수](https://school.programmers.co.kr/learn/courses/30/lessons/42748) | 기본 | 40분 | 조건 분석과 독립 구현 | `practice_01.cpp` |
| Programmers | [이상한 문자 만들기](https://school.programmers.co.kr/learn/courses/30/lessons/12930) | 기본 | 45분 | 조건 분석과 독립 구현 | `practice_02.cpp` |

Difficulty의 기본·실전·도전은 이 계획의 학습 기준이며 공식 등급이 아니다. CodeTree의 Easy/Medium/Hard는 해당 페이지 표기다.

[플랫폼별 제출·로컬 검증 방법](../README.md#플랫폼별-제출과-로컬-검증)을 따른다. 온라인 문제의 전체 지문은 저장소에 복사하지 않는다.

## 권장 시간

20분 No IntelliSense 손코딩 → 40분 기본 문제 → 45분 실전 문제 → 15분 오답·problem_log 기록 (총 120분).

## 자주 하는 실수

iterator 무효화, end() 역참조, 비교자에 <= 사용.

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
../run.sh stl_basic.cpp
```

## 체크
- [ ] vector / 2차원 vector 초기화
- [ ] string (substr, find, stoi, to_string, split)
- [ ] pair 정렬 규칙
- [ ] sort comparator (strict weak ordering: `<`는 되지만 `<=`는 안 됨)
- [ ] reverse, min/max, min_element/max_element
- [ ] lambda 캡처 ([=], [&])
- [ ] 입출력 템플릿 (`ios::sync_with_stdio(false); cin.tie(nullptr);`)


</details>
