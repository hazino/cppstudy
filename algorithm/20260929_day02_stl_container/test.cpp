#include <bits/stdc++.h>
#include <queue>

using namespace std;

bool testStack(const string& s)
{
    stack<char> stk;
    
    for(auto n : s) {
        stk.push(n);
    }

    cout << stk.top() << endl;
    
    
    while(!stk.empty()){ 
        stk.pop();
    }
    return false;
}


void testPQ()
{
    priority_queue<int> maxHeap;
    for(int x : {3, 5, 1, 2, 5}) maxHeap.push(x);
    cout << "maxHeap:" << maxHeap.top()<< endl;

    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int x : {3, 5, 1, 2, 5}) minHeap.push(x);
    cout << "minHeap:" << minHeap.top()<< endl;

    //dijkstra에서 사용
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({5,1});
    pq.push({2,1});
    pq.push({3,2});
    pq.push({3,3});

    while(!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        cout << "(" << d <<","<< v << ") ";
    }
    cout << endl;

    struct Job {
        int id, time;
    };

    auto cmp = [](const Job& a, const Job& b) {
        if(a.time!=b.time) return a.time > b.time;  
        return a.id > b.id;
    };
    priority_queue<Job, vector<Job>, decltype(cmp)> Jobs(cmp);

    Jobs.push({1,5});
    Jobs.push({2,1});
    Jobs.push({4,0});
    Jobs.push({2,3});

    while(!Jobs.empty()){
        auto [d, v] = Jobs.top();
        Jobs.pop();
        cout << "(" << d <<","<< v << ") ";
    } 
    cout << endl;
}

void testSetMap()
{
    //set
    set<int> s = {5, 1, 3, 3, 1};
    s.insert(4);
    s.insert(2);
    s.erase(1);
    for(int x : s ) cout << x << ' ';
    cout << "count(3):" << s.count(3) <<endl;

    auto it = s.lower_bound(4);
    if(it != s.end()) cout << "lower_bound(4): " << *it << endl;

    //multiset
    multiset<int> ms = {2,2,2,1,3,3};
    for(int x : ms ) cout << x << ' ';
    ms.erase(2);
    for(int x : ms ) cout << x << ' ';
    ms.erase(ms.find(3));
    for(int x : ms ) cout << x << ' ';
    cout << endl;

    //map
    map<string,int> cnt;
    for(string w : {"cat", "zoo", "apple", "bowling"}) cnt[w]++;
    for(auto&[k, v]: cnt) cout << k << "=" << v << endl;
    cout << endl;
    if(cnt.find("none") ==  cnt.end()) cout << "not found" << endl;

    //unordered_map
    unordered_map<int, int> um;
    vector<int> nums = {4, 5, 1, 51};
 
}

int main()
{
    testStack("hello world!");
    testPQ();
    testSetMap();
}
