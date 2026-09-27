// Day 8 - 10/05 : Greedy
// "지금 가장 좋아 보이는 선택"이 전체 최적이 되는지 먼저 확인한 뒤 사용한다.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 1) 동전 0 : 큰 동전부터 최대한 사용
//    성립 조건 : 각 동전이 작은 동전의 배수 (1, 5, 10, 50, ...)
//    반례 : {1, 3, 4}로 6 만들기 → 그리디 4+1+1(3개), 최적 3+3(2개) → DP로 풀어야 함
int minCoins(vector<int> coins, int amount) {
    sort(coins.rbegin(), coins.rend());
    int cnt = 0;
    for (int c : coins) {
        cnt += amount / c;
        amount %= c;
    }
    return cnt;
}

// 2) 회의실 배정 : 최대한 많은 회의를 겹치지 않게
//    "끝나는 시간이 빠른 것"부터 고른다 (시작이 빠른 순 / 짧은 순은 반례 존재)
//    끝나는 시간이 같으면 시작 시간이 빠른 것 먼저 (시작 == 끝인 회의 처리)
int maxMeetings(vector<pair<int, int>> meetings) {  // {start, end}
    sort(meetings.begin(), meetings.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });
    int cnt = 0, lastEnd = 0;
    for (auto [s, e] : meetings) {
        if (s >= lastEnd) {
            cnt++;
            lastEnd = e;
        }
    }
    return cnt;
}

// 3) ATM : 대기 시간 합 최소 → 짧은 사람부터 (정렬 + 그리디)
ll minTotalWait(vector<int> t) {
    sort(t.begin(), t.end());
    ll total = 0, acc = 0;
    for (int x : t) {
        acc += x;
        total += acc;
    }
    return total;
}

// 4) 우선순위 큐 + 그리디 : 카드 묶음 합치기
//    매번 가장 작은 두 묶음을 합친다 (허프만 코딩과 같은 구조)
ll mergeCost(const vector<int>& cards) {
    priority_queue<ll, vector<ll>, greater<>> pq(cards.begin(), cards.end());
    ll cost = 0;
    while (pq.size() > 1) {
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        cost += a + b;
        pq.push(a + b);
    }
    return cost;
}

// 5) 구간 겹침 : 선 긋기 → 시작점 정렬 후 현재 구간을 늘려가며 합치기
ll totalLength(vector<pair<int, int>> lines) {
    sort(lines.begin(), lines.end());
    ll total = 0;
    int curS = lines[0].first, curE = lines[0].second;
    for (size_t i = 1; i < lines.size(); i++) {
        auto [s, e] = lines[i];
        if (s <= curE) {
            curE = max(curE, e);        // 겹침 → 확장
        } else {
            total += curE - curS;       // 끊김 → 확정
            curS = s;
            curE = e;
        }
    }
    total += curE - curS;
    return total;
}

int main() {
    cout << "minCoins(4200) = " << minCoins({1, 5, 10, 50, 100, 500, 1000, 5000, 10000, 50000}, 4200) << '\n';  // 6
    cout << "minCoins {1,3,4} 6 (greedy, wrong) = " << minCoins({1, 3, 4}, 6) << '\n';                           // 3 (최적 2)
    cout << "maxMeetings = " << maxMeetings({{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}}) << '\n';  // 4
    cout << "minTotalWait = " << minTotalWait({3, 1, 4, 3, 2}) << '\n';  // 32
    cout << "mergeCost = " << mergeCost({10, 20, 40}) << '\n';           // 100
    cout << "totalLength = " << totalLength({{1, 3}, {2, 5}, {3, 5}, {6, 7}}) << '\n';  // 5
    return 0;
}
