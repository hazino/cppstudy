// Day 5 - 10/02 : Binary Search
// 직접 구현 / lower_bound / upper_bound / Parameter Search
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 1) 기본 이분 탐색 : 정렬된 배열에서 target의 인덱스, 없으면 -1
//    [lo, hi] 닫힌 구간 → while (lo <= hi)
int binarySearch(const vector<int>& a, int target) {
    int lo = 0, hi = (int)a.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;   // (lo+hi)/2 는 overflow 가능
        if (a[mid] == target) return mid;
        if (a[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

// 2) lower_bound 직접 구현 : target "이상"이 처음 나오는 위치
//    [lo, hi) 반닫힌 구간 → while (lo < hi), 답이 없으면 n 반환
int myLowerBound(const vector<int>& a, int target) {
    int lo = 0, hi = a.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] >= target) hi = mid;   // upper_bound는 여기를 > 로
        else lo = mid + 1;
    }
    return lo;
}

// 3) Parameter Search : "정답 자체"를 이분 탐색
//    나무 자르기 : 높이 H로 잘랐을 때 얻는 나무 합이 M 이상이 되는 최대 H
//    check(H)가 단조 : H가 작을수록 많이 얻는다 → true...true false...false
//    → 마지막 true를 찾는다
ll cutWood(const vector<ll>& trees, ll h) {
    ll sum = 0;
    for (ll t : trees)
        if (t > h) sum += t - h;
    return sum;
}

ll maxCutHeight(const vector<ll>& trees, ll need) {
    ll lo = 0, hi = *max_element(trees.begin(), trees.end());
    ll answer = 0;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (cutWood(trees, mid) >= need) {
            answer = mid;   // 조건 만족 → 기록하고 더 높은 쪽 시도
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return answer;
}

// 4) Parameter Search (최소화) : 공유기 설치 반대 유형
//    N개 작업을 K명에게 연속 구간으로 나눌 때, 한 사람의 최대 작업량의 최솟값
//    check(limit) : limit 이하로 나눴을 때 K명 이하로 가능한가? → false...false true...true
//    → 첫 true를 찾는다
bool canSplit(const vector<int>& jobs, int k, ll limit) {
    int people = 1;
    ll cur = 0;
    for (int j : jobs) {
        if (j > limit) return false;
        if (cur + j > limit) {
            people++;
            cur = 0;
        }
        cur += j;
    }
    return people <= k;
}

ll minMaxLoad(const vector<int>& jobs, int k) {
    ll lo = 1, hi = accumulate(jobs.begin(), jobs.end(), 0LL);
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (canSplit(jobs, k, mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a = {1, 3, 3, 3, 5, 7, 9};   // 반드시 정렬되어 있어야 한다
    cout << "binarySearch(7)=" << binarySearch(a, 7) << ", (4)=" << binarySearch(a, 4) << '\n';
    cout << "myLowerBound(3)=" << myLowerBound(a, 3) << ", (4)=" << myLowerBound(a, 4) << '\n';

    // STL : iterator 반환 → 인덱스는 - a.begin()
    int lb = lower_bound(a.begin(), a.end(), 3) - a.begin();   // 3 이상 첫 위치
    int ub = upper_bound(a.begin(), a.end(), 3) - a.begin();   // 3 초과 첫 위치
    cout << "lower_bound(3)=" << lb << ", upper_bound(3)=" << ub << ", count(3)=" << ub - lb << '\n';
    cout << "binary_search(5)=" << binary_search(a.begin(), a.end(), 5) << '\n';

    // 범위 [l, r]에 속하는 원소 개수
    int l = 2, r = 6;
    cout << "count in [2,6]=" << upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l) << '\n';

    // 내림차순 배열에서는 comparator를 같이 넘긴다
    vector<int> desc = {9, 7, 5, 3, 1};
    cout << "desc lower_bound(5)=" << lower_bound(desc.begin(), desc.end(), 5, greater<int>()) - desc.begin() << '\n';

    cout << "maxCutHeight=" << maxCutHeight({20, 15, 10, 17}, 7) << '\n';   // 15
    cout << "minMaxLoad=" << minMaxLoad({7, 2, 5, 10, 8}, 2) << '\n';       // 18
    return 0;
}
