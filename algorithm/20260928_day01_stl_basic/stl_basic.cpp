// Day 1 - 09/28 : C++ STL 기본 복구
// vector / string / pair / sort / reverse / min, max / range-based for / lambda / 입출력
#include <bits/stdc++.h>
using namespace std;

void vectorDemo() {
    cout << "=== vector ===\n";
    vector<int> v = {6, 3, 8, 1, 9};
    v.push_back(4);
    v.pop_back();
    cout << "size=" << v.size() << " front=" << v.front() << " back=" << v.back() << '\n';

    vector<int> zeros(5, 0);                    // 크기 5, 0으로 초기화
    vector<vector<int>> grid(3, vector<int>(4, -1));  // 3x4 2차원, -1로 초기화
    cout << "grid " << grid.size() << "x" << grid[0].size() << ", zeros[4]=" << zeros[4] << '\n';

    v.insert(v.begin() + 1, 100);               // index 1에 삽입 : O(N)
    v.erase(v.begin());                         // index 0 삭제   : O(N)
    for (int x : v) cout << x << ' ';
    cout << '\n';

    // 합계 : accumulate의 초기값 타입이 결과 타입 → 큰 값이면 0LL
    long long sum = accumulate(v.begin(), v.end(), 0LL);
    cout << "sum=" << sum << '\n';

    // 중복 제거 : sort → unique → erase
    vector<int> d = {3, 1, 3, 2, 1};
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    for (int x : d) cout << x << ' ';           // 1 2 3
    cout << '\n';
}

void stringDemo() {
    cout << "=== string ===\n";
    string s = "Hello World";
    cout << "length=" << s.size() << " s[0]=" << s[0] << '\n';
    cout << "substr(6,5)=" << s.substr(6, 5) << '\n';         // (시작, 길이)

    size_t pos = s.find("World");
    if (pos != string::npos) cout << "find World at " << pos << '\n';

    string up = s;
    for (char& c : up) c = toupper(c);          // 참조로 받아야 원본이 바뀐다
    cout << "upper=" << up << '\n';

    // 숫자 <-> 문자열
    int n = stoi("123");
    string t = to_string(n * 2);
    cout << "stoi/to_string: " << t << '\n';

    // 문자 → 숫자
    char ch = '7';
    cout << "digit=" << ch - '0' << '\n';

    // 공백 기준 split
    stringstream ss("apple banana cherry");
    string word;
    vector<string> words;
    while (ss >> word) words.push_back(word);
    cout << "split count=" << words.size() << '\n';

    // 구분자 기준 split
    stringstream ss2("a,b,c");
    string token;
    while (getline(ss2, token, ',')) cout << "[" << token << "]";
    cout << '\n';

    string r = "abc";
    reverse(r.begin(), r.end());
    cout << "reverse=" << r << '\n';
}

void pairSortDemo() {
    cout << "=== pair / sort ===\n";
    vector<pair<int, string>> people = {{30, "Kim"}, {25, "Lee"}, {30, "Ahn"}, {20, "Park"}};

    // pair 기본 정렬 : first 오름차순 → 같으면 second 오름차순
    sort(people.begin(), people.end());
    for (auto& [age, name] : people) cout << age << ":" << name << ' ';
    cout << '\n';

    // 내림차순
    vector<int> v = {5, 2, 9, 1};
    sort(v.begin(), v.end(), greater<int>());
    for (int x : v) cout << x << ' ';
    cout << '\n';

    // comparator : 나이 내림차순, 같으면 이름 오름차순
    // 주의 : "a가 b보다 앞에 와야 하면 true". <= 쓰면 안 된다 (strict weak ordering 위반)
    sort(people.begin(), people.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });
    for (auto& p : people) cout << p.first << ":" << p.second << ' ';
    cout << '\n';

    // 구조체 정렬
    struct Student {
        string name;
        int kor, eng;
    };
    vector<Student> st = {{"A", 90, 80}, {"B", 90, 95}, {"C", 70, 100}};
    sort(st.begin(), st.end(), [](const Student& a, const Student& b) {
        if (a.kor != b.kor) return a.kor > b.kor;   // 국어 내림차순
        return a.eng < b.eng;                       // 영어 오름차순
    });
    for (auto& s : st) cout << s.name << ' ';       // A B C
    cout << '\n';

    // 같은 값의 원래 순서를 유지해야 하면 stable_sort
}

void minMaxDemo() {
    cout << "=== min / max ===\n";
    cout << min(3, 7) << ' ' << max(3, 7) << ' ' << max({4, 9, 2}) << '\n';

    // 타입이 다르면 컴파일 에러 : max(1, 2LL) (X) → max<long long>(1, 2LL)
    long long big = max<long long>(1, 2LL);
    cout << big << '\n';

    vector<int> v = {4, 1, 7, 3};
    auto mn = min_element(v.begin(), v.end());
    auto mx = max_element(v.begin(), v.end());
    cout << "min=" << *mn << " idx=" << (mn - v.begin()) << ", max=" << *mx << '\n';
}

void lambdaDemo() {
    cout << "=== lambda ===\n";
    auto add = [](int a, int b) { return a + b; };
    cout << add(2, 3) << '\n';

    int base = 10;
    auto addBase = [base](int x) { return x + base; };  // 값 캡처
    int counter = 0;
    auto inc = [&counter]() { counter++; };              // 참조 캡처
    inc();
    inc();
    cout << addBase(5) << ' ' << counter << '\n';

    vector<int> v = {1, 2, 3, 4, 5, 6};
    int evenCount = count_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
    cout << "even=" << evenCount << '\n';

    // 재귀 lambda (C++14 이상) : function<> 사용
    function<int(int)> fact = [&](int n) { return n <= 1 ? 1 : n * fact(n - 1); };
    cout << "5!=" << fact(5) << '\n';
}

int main() {
    // 코딩테스트 입출력 기본
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vectorDemo();
    stringDemo();
    pairSortDemo();
    minMaxDemo();
    lambdaDemo();
    return 0;
}
