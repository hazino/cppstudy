#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int release = 1;
    int workday_before =(100 - progresses[0]) / speeds[0];
    if((100 - progresses[0]) % speeds[0] > 0)
        workday_before++;
    
    size_t sz = progresses.size();
    for(int i = 1; i < sz; i++) {
        int progress = progresses[i];
        int speed = speeds[i];
        int workday =(100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i] > 0)
            workday++;
        if(workday <= workday_before)
            release++;
        else{
            answer.push_back(release);
            release = 1;
            workday_before = workday;
        }
    }
    answer.push_back(release);
    
    
    return answer;
}
