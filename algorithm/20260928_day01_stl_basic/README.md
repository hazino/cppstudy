# Day 01 — 2026-09-28: STL 기본 복구

## 오늘의 목표

오늘의 주제를 설명하고 스스로 구현한다. 예제 읽기는 20분 이내, 문제 풀이를 우선한다.

## 핵심 개념

vector, string, sort, lambda, iterator, pair.

## 반드시 직접 작성할 코드

vector 순회와 iterator 접근, pair 정렬 및 lambda 비교자를 빈 파일에 작성한다.

## 오늘 풀 문제

| 순서 | 문제 | 풀이 파일 |
|---|---|---|
| 1 | [BOJ 10818 최소, 최대](https://www.acmicpc.net/problem/10818) | `boj_10818.cpp` |
| 2 | [BOJ 11650 좌표 정렬하기](https://www.acmicpc.net/problem/11650) | `boj_11650.cpp` |

## 권장 시간

20분 개념·손코딩 → 40분 기본 문제 → 45분 실전 문제 → 15분 오답·로그 (총 120분).

## 자주 발생하는 실수

iterator 무효화, end() 역참조, 비교자에 <= 사용.

## 완료 체크리스트

- [ ] 코드를 보기 전에 직접 작성했다.
- [ ] 문제를 읽고 3~5분 안에 첫 접근과 복잡도를 적었다.
- [ ] 예제와 직접 만든 경계 사례를 확인했다.
- [ ] 결과·실패 원인·재도전 날짜를 [problem_log.md](../problem_log.md)에 기록했다.

[공통 풀이 원칙](../README.md#문제-풀이-원칙)을 따른다.

---

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

## 선택 추가 문제 (필수 풀이 완료 후)
- 1181 단어 정렬
- 11650 좌표 정렬하기
- 10814 나이순 정렬
