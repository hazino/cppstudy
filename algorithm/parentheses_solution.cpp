#include <string>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    cout << "Hello Cpp" << endl;
    int cnt = 0;
    for(char& n : s) {
        if(n =='(') cnt++;
        else if(n == ')') cnt--;
        if (cnt < 0) 
            break;
    }

    return cnt == 0;
}
