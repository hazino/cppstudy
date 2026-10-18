#include <bits/stdc++.h>

using namespace std;

int cnt_ = 0;
string tgt;
bool visited[51] = {0,};

bool diff(const string& a, const string& b) {
    int sz = a.size();
    int diff = 0;
    for(int i = 0; i <sz; i++) {
        if(a[i] != b[i]) diff++;
        if(diff > 1) return true; 
    }
    return false;
}

void dfs(int idx, 
         int cnt,
         const string& cur, 
         const vector<string>& words) {
    if(cur == tgt) {
        if(cnt_ > cnt) {
             cnt_ = cnt;
        }
        return;
    } 
    int sz = words.size();

    for(int i = 0; i < sz; i++) {
        string curWord = words[i];
        if(diff(cur, curWord)) continue;
        if(visited[i] == true) continue;
        visited[i] = true;
        dfs(i, cnt+1, curWord, words);
        visited[i] = false;
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    cnt_ = 1e7;
    tgt = target;
    dfs(0, 0, begin, words);
    if(cnt_ <= words.size()) answer = cnt_;
    return answer;
}
