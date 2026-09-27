// Day 13 - 10/10 : Combination / Backtracking
// 선택 → 재귀 → 선택 취소 (상태 복구), 가지치기(Pruning)로 탐색 공간 줄이기
#include <bits/stdc++.h>
using namespace std;

int n, r;
vector<int> picked;
vector<bool> used;

void printPicked() {
    for (int x : picked) cout << x << ' ';
    cout << '\n';
}

// 1) 순열 nPr : 순서 O, 중복 X → used 배열
void permutation() {
    if ((int)picked.size() == r) {      // 종료 조건
        printPicked();
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        used[i] = true;                 // 선택
        picked.push_back(i);
        permutation();                  // 재귀
        picked.pop_back();              // 선택 취소 (상태 복구)
        used[i] = false;
    }
}

// 2) 조합 nCr : 순서 X → start 인덱스로 "나보다 뒤"만 고른다
void combination(int start) {
    if ((int)picked.size() == r) {
        printPicked();
        return;
    }
    // Pruning : 남은 수가 부족하면 더 볼 필요 없음 → i <= n - (r - picked.size()) + 1
    for (int i = start; i <= n - (r - (int)picked.size()) + 1; i++) {
        picked.push_back(i);
        combination(i + 1);             // 중복 조합이면 combination(i)
        picked.pop_back();
    }
}

// 3) 부분 집합 합 : 합이 target인 부분 집합 개수 (선택 / 비선택 2갈래)
int subsetCount(const vector<int>& a, int idx, int sum, int target) {
    if (idx == (int)a.size()) return sum == target ? 1 : 0;
    return subsetCount(a, idx + 1, sum + a[idx], target)    // 선택
         + subsetCount(a, idx + 1, sum, target);            // 비선택
}

// 4) N-Queen : 가지치기의 대표 예
//    같은 열 / 대각선(↘ : row-col 일정, ↙ : row+col 일정)에 이미 퀸이 있으면 더 내려가지 않는다
int N;
vector<bool> colUsed, diag1, diag2;
int nQueen(int row) {
    if (row == N) return 1;
    int cnt = 0;
    for (int c = 0; c < N; c++) {
        if (colUsed[c] || diag1[row - c + N - 1] || diag2[row + c]) continue;  // Pruning
        colUsed[c] = diag1[row - c + N - 1] = diag2[row + c] = true;
        cnt += nQueen(row + 1);
        colUsed[c] = diag1[row - c + N - 1] = diag2[row + c] = false;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    n = 4;
    r = 2;
    used.assign(n + 1, false);
    cout << "=== permutation 4P2 ===\n";
    permutation();

    cout << "=== combination 4C2 ===\n";
    combination(1);

    // STL : next_permutation (정렬된 상태에서 시작해야 모든 순열이 나온다)
    cout << "=== next_permutation ===\n";
    vector<int> v = {1, 2, 3};
    do {
        for (int x : v) cout << x << ' ';
        cout << '\n';
    } while (next_permutation(v.begin(), v.end()));

    // next_permutation으로 조합 : 0/1 마스크 순열
    cout << "=== combination by mask (5C3) count ===\n";
    vector<int> mask = {0, 0, 1, 1, 1};     // 1이 r개
    int combCnt = 0;
    do combCnt++;
    while (next_permutation(mask.begin(), mask.end()));
    cout << combCnt << '\n';                // 10

    // 비트마스크로 모든 부분 집합 (N <= 20 정도)
    cout << "=== subsets by bitmask ===\n";
    vector<int> a = {-7, -3, -2, 5, 8};
    int zeroCnt = 0;
    for (int m = 1; m < (1 << a.size()); m++) {     // 공집합 제외
        int s = 0;
        for (size_t i = 0; i < a.size(); i++)
            if (m & (1 << i)) s += a[i];
        if (s == 0) zeroCnt++;
    }
    cout << "bitmask zero-sum subsets = " << zeroCnt << '\n';                    // 1
    cout << "recursive = " << subsetCount(a, 0, 0, 0) - 1 << " (공집합 제외)\n";  // 1

    N = 8;
    colUsed.assign(N, false);
    diag1.assign(2 * N - 1, false);
    diag2.assign(2 * N - 1, false);
    cout << "=== 8-Queen = " << nQueen(0) << " ===\n";  // 92
    return 0;
}
