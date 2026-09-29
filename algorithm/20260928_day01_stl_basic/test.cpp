#include <bits/stdc++.h>

using namespace std;

void vectorTest() {
    vector<int> vec (3, -1);
    for(auto n : vec)
        cout << n << " ";
    cout << endl;

    vector<vector<int>> vec2 (3, vector<int>(5,-1));

    for(auto n : vec2)
    {
        for (auto nn : n)
            cout << nn << " ";
        cout << endl;
    }
    
    vec.insert(vec.begin(), 5);
    vec.insert(vec.begin()+1, 4);
    for(auto n : vec)
        cout << n << " ";
    cout << endl;
    vec.erase(vec.begin()+2);
    for(auto n : vec)
        cout << n << " ";
    cout << endl;

    vector<int> vec3 = {5,3,-1,4,5};

    sort(vec3.begin(), vec3.end());
    for(auto n : vec3) 
        cout << n <<" ";
    cout << endl;

    vec3.erase(unique(vec3.begin(), vec3.end()), vec3.end());
    for(auto n : vec3) 
        cout << n <<" ";
    cout << endl;
}

void stringTest() {
    string s = "hey, honey!";
    cout << s.substr(5,5) << endl;
    size_t pos = s.find("honey");
    if(pos != string::npos) cout << "pos: " << pos << endl;
    
    string up = s;
    for(char& c : up) 
        c = toupper(c);
    cout << "s:" << s << endl;
    cout << "up:" << up << endl;

    int n = stoi("12345");
    string ss = to_string(n*2);

    cout << ss << endl;
    char ch = '5';

    cout << "digit= " << ch << endl;
    cout << "digit= " << ch-'0'<<endl;

    stringstream sss("orange apple banana");
    string word;
    vector<string> words;

    while(sss >> word) 
        words.push_back(word);
    for(auto n : words)
        cout << n << " ";
    cout << endl;

    stringstream st ( "a,b,c");
    string token;
    while(getline(st, token, ',')){
        cout << "[" << token << "]" << endl;
    }

    string rr = "abc";
    reverse(rr.begin(), rr.end());
    cout << "reverse:" << rr <<'\n';
}

void pairSortTest()
{
    vector<pair<int, string>> people = {
        {91,"진호"}, {90, "준궁"}, {99, "시로"}, {90, "로로"}
    };
    sort(people.begin(), people.end());

    for(const auto& [age, name]: people ) cout << age << ":" << name << endl;
   
    cout << "---------------------"<<endl;
    sort(people.begin(), people.end(), greater<pair<int,string>>());
    for(const auto& [age, name]: people ) cout << age << ":" << name << endl;

    cout << "---------------------"<<endl;
    vector<int> ages { 1,5, 3, 30,99,50};
    sort(ages.begin(), ages.end(), greater<int>());
    for(const auto& n : ages) cout << n << " " ;
    cout << endl;

    cout << "---------------------"<<endl;
    sort(people.begin(), people.end(), [](const pair<int,string>& a, const pair<int,string>&b){
        if(a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });
    for(const auto& [age, name]: people ) cout << age << ":" << name << endl;
}

void minMaxTest()
{
    cout << min(3,6) << " " << max(-1,1) << " " << max({3,5,111}) << endl;
    long long big = max<long long>(1, 2LL);
    cout << big << '\n';

    vector<int> v = {99, 4, 1, 7, 3, 101, -33};
    auto mn = min_element(v.begin(), v.end());
    auto mx = max_element(v.begin(), v.end());
    cout << "min=" << *mn << " idx=" << (mn - v.begin()) << ", max=" << *mx << '\n';

    //-----------------------------------
    // int a = 100000;
    // int b = 100000;

    // long long x = a * b;       // ❌ 이미 int * int에서 오버플로우
    // long long y = 1LL * a * b; // ✅ long long으로 계산
}

void lamdaTest()
{
    auto lamda = [](int a, int b) {
       return a+b; 
    };

    cout << lamda(5,10) << " " << lamda(15, 50) << endl;
    int base = 50;

    auto addBase = [base](int n ){
        return base+n;
    };
    int cnt = 0;
    auto inc = [&cnt]() {
        cnt++;
    };
    inc();
    inc();
    cout << addBase(30) << " " << addBase(50) << endl;
    cout << cnt << endl;

    vector<int> vec {1,2,3,4,5,6,7};
    int evenCnt = count_if(vec.begin(), vec.end(), [](int x){ return x%2;});
    cout <<"evenCnt:" <<evenCnt << endl;

    function<int(int)> fact = [&](int n) { return n <=1? 1: n*fact(n-1);};
    cout <<"fact(6):" <<fact(6) << endl;
}

int main() { 
    //vectorTest();
    //stringTest();
    //pairSortTest();
    // minMaxTest();
    lamdaTest();

}
