// 개념 예제: 누적 상태와 구간 질의. 문제 풀이 후 비교한다.
#include <cassert>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// s[i]: 앞의 i개 원소 합. s[0] = 0이 경계 초기값이다.
vector<ll> prefixSum(const vector<ll>& a) {
    vector<ll> s(a.size() + 1, 0);
    for (size_t i = 0; i < a.size(); ++i) s[i + 1] = s[i] + a[i];
    return s;
}

// 1 <= l <= r <= 원소 개수, 양 끝을 포함하는 1-based 구간.
ll rangeSum(const vector<ll>& s, int l, int r) {
    return s[r] - s[l - 1];
}

int main() {
    const auto s = prefixSum({4, -2, 7, 1});
    assert(rangeSum(s, 1, 1) == 4);
    assert(rangeSum(s, 2, 3) == 5);
    assert(rangeSum(s, 1, 4) == 10);
    const auto big = prefixSum({2000000000LL, 2000000000LL});
    assert(rangeSum(big, 1, 2) == 4000000000LL);
    cout << "sum[2,3] = " << rangeSum(s, 2, 3) << '\n';
    cout << fixed << setprecision(2)
         << "average[2,3] = " << static_cast<double>(rangeSum(s, 2, 3)) / 2 << '\n';
}
