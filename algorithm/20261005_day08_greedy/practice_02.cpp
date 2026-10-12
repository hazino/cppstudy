#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    
    int left = 0;
    int right = people.size() - 1;
    
    while(left <= right) {
        if(left == right) {
            if(people[left] < limit) answer++;
            break;
        }
        int remainder = limit - people[right];
        right--;
        if(people[left] <= remainder) {
            left++;
        }
        answer++;
    }
    

    return answer;
}
