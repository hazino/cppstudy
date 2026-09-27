// Day 2 - 09/29 : STL 자료구조
// stack / queue / deque / priority_queue / set / map / unordered_map
// 핵심 : "어떤 상황에서 어떤 컨테이너를 쓰는가?"
#include <bits/stdc++.h>
using namespace std;

// [stack] 가장 최근 것부터 처리 (LIFO) : 괄호 짝, 되돌리기, DFS
bool isValidBracket(const string& s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;       // pop/top 전에 empty 체크 필수
            char open = st.top();
            st.pop();
            if ((c == ')' && open != '(') || (c == ']' && open != '[')) return false;
        }
    }
    return st.empty();
}

// [queue] 들어온 순서대로 처리 (FIFO) : BFS, 대기열
// 요세푸스 : 1~N이 원형으로 앉아 있을 때 K번째마다 제거
vector<int> josephus(int n, int k) {
    queue<int> q;
    for (int i = 1; i <= n; i++) q.push(i);
    vector<int> order;
    while (!q.empty()) {
        for (int i = 0; i < k - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        order.push_back(q.front());
        q.pop();
    }
    return order;
}

// [deque] 양쪽 끝에서 삽입/삭제 : 슬라이딩 윈도우, 회전
// 크기 k 윈도우의 최댓값들 (monotonic deque, O(N))
vector<int> slidingMax(const vector<int>& a, int k) {
    deque<int> dq;  // 인덱스 저장, 값은 앞→뒤로 감소
    vector<int> res;
    for (int i = 0; i < (int)a.size(); i++) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();   // 윈도우 밖
        while (!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();   // 나보다 작은 건 필요 없음
        dq.push_back(i);
        if (i >= k - 1) res.push_back(a[dq.front()]);
    }
    return res;
}

void priorityQueueDemo() {
    cout << "=== priority_queue ===\n";
    // 기본 : 최대 힙 (가장 큰 값이 top)
    priority_queue<int> maxHeap;
    for (int x : {3, 1, 4, 1, 5}) maxHeap.push(x);
    cout << "max top=" << maxHeap.top() << '\n';    // 5

    // 최소 힙
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int x : {3, 1, 4, 1, 5}) minHeap.push(x);
    cout << "min top=" << minHeap.top() << '\n';    // 1

    // 최소 힙 트릭 : 음수로 넣고 꺼낼 때 다시 음수
    priority_queue<int> trick;
    trick.push(-3);
    trick.push(-1);
    cout << "trick min=" << -trick.top() << '\n';   // 1

    // pair 최소 힙 : (거리, 노드) → Dijkstra에서 사용
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({5, 1});
    pq.push({2, 3});
    pq.push({2, 1});
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        cout << "(" << d << "," << v << ") ";
    }
    cout << '\n';

    // 커스텀 comparator
    // 주의 : priority_queue는 comparator가 true인 쪽이 "뒤로" 간다 (sort와 반대 느낌)
    // 아래는 "작업 시간이 짧은 것 우선, 같으면 id가 작은 것 우선"
    struct Job {
        int id, time;
    };
    auto cmp = [](const Job& a, const Job& b) {
        if (a.time != b.time) return a.time > b.time;
        return a.id > b.id;
    };
    priority_queue<Job, vector<Job>, decltype(cmp)> jobs(cmp);
    jobs.push({1, 5});
    jobs.push({2, 2});
    jobs.push({3, 2});
    while (!jobs.empty()) {
        cout << "job" << jobs.top().id << ' ';      // job2 job3 job1
        jobs.pop();
    }
    cout << '\n';
}

void setMapDemo() {
    cout << "=== set / map / unordered_map ===\n";
    // set : 중복 제거 + 자동 정렬, O(log N)
    set<int> s = {5, 1, 3, 3, 1};
    s.insert(4);
    s.erase(1);
    for (int x : s) cout << x << ' ';               // 3 4 5
    cout << "| count(3)=" << s.count(3) << '\n';

    // set에서 x 이상인 첫 원소 : 멤버 함수 lower_bound 사용 (std::lower_bound는 O(N))
    auto it = s.lower_bound(4);
    if (it != s.end()) cout << "lower_bound(4)=" << *it << '\n';

    // multiset : 중복 허용. 값 하나만 지울 때는 iterator로 erase
    multiset<int> ms = {2, 2, 2};
    ms.erase(ms.find(2));                           // erase(2)는 전부 지움
    cout << "multiset size=" << ms.size() << '\n';  // 2

    // map : key 정렬 유지, O(log N)
    map<string, int> cnt;
    for (string w : {"apple", "banana", "apple", "cherry", "apple"}) cnt[w]++;
    for (auto& [k, v] : cnt) cout << k << "=" << v << ' ';
    cout << '\n';

    // 주의 : cnt["none"] 처럼 조회만 해도 key가 생성된다 → 존재 확인은 find/count
    if (cnt.find("none") == cnt.end()) cout << "none not found\n";

    // unordered_map : 해시, 평균 O(1), 순서 없음
    // 순서가 필요 없고 빠른 조회만 필요할 때
    unordered_map<int, int> um;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    for (int i = 0; i < (int)nums.size(); i++) {    // Two Sum
        auto f = um.find(target - nums[i]);
        if (f != um.end()) cout << "two sum: " << f->second << "," << i << '\n';
        um[nums[i]] = i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== stack ===\n";
    cout << isValidBracket("([()])") << ' ' << isValidBracket("([)]") << '\n';  // 1 0

    cout << "=== queue ===\n";
    for (int x : josephus(7, 3)) cout << x << ' ';  // 3 6 2 7 5 1 4
    cout << '\n';

    cout << "=== deque ===\n";
    for (int x : slidingMax({1, 3, -1, -3, 5, 3, 6, 7}, 3)) cout << x << ' ';  // 3 3 5 5 6 7
    cout << '\n';

    priorityQueueDemo();
    setMapDemo();
    return 0;
}
