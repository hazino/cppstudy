#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int mval = health;
    int answer = 0;
    int span = bandage[0];
    int heal = bandage[1];
    int extra = bandage[2];
    int time = 0;
    for(auto atk : attacks){
        auto tic = atk[0];
        auto damage = atk[1];
        auto dist = tic - time -1;
        time = tic;
        health += (dist * heal);
        health += (dist / span)* extra;
        if(health > mval) health = mval;
        health -= damage;
            
        if (health <= 0) return -1;
    }
    answer = health;
    return answer;
}
