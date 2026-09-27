#!/usr/bin/env bash
# 사용법:
#   ./run.sh 20260928_day01_stl_basic/stl_basic.cpp            # 컴파일 + 실행
#   ./run.sh 20261004_day07_week1_review/q1.cpp input.txt       # 입력 파일 리다이렉트
set -e
SRC="$1"
IN="$2"
[ -z "$SRC" ] && { echo "usage: $0 <file.cpp> [input.txt]"; exit 1; }

DIR="$(cd "$(dirname "$0")" && pwd)"
mkdir -p "$DIR/.bin"
BIN="$DIR/.bin/$(basename "${SRC%.cpp}")"

g++ -std=c++17 -O2 -Wall -Wextra -o "$BIN" "$SRC"
if [ -n "$IN" ]; then
    "$BIN" < "$IN"
else
    "$BIN"
fi
