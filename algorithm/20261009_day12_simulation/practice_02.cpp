#include <bits/stdc++.h>

using namespace std;

int arr[101][101];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    int a = 1;
    for(int i = 1; i <= rows; i++) 
        for(int j = 1; j <= columns; j++) 
            arr[i][j] = a++;
    vector<int> answer;
    
    for(auto n : queries) {
        auto x1 = n[0];
        auto y1 = n[1];
        auto x2 = n[2];
        auto y2 = n[3];
        int save = arr[x1][y1];
        int mval = arr[x1][y1];
        for (int i = x1; i < x2; i++) { 
             arr[i][y1] = arr[i+1][y1];
            //cout << arr[i][y1] << "->";
            if(arr[i][y1] < mval) mval = arr[i][y1];
        }
        for(int i = y1; i < y2; i++) {
            arr[x2][i] = arr[x2][i+1];
            //cout << arr[x2][i] << "->";
            if(arr[x2][i] < mval) mval = arr[x2][i];
        }
        for (int i = x2; i > x1; i--) { 
             arr[i][y2] = arr[i-1][y2];
            //cout << arr[i][y2] << "->";
            if(arr[i][y2] < mval) mval = arr[i][y2];
        }
        for(int i = y2; i > y1; i--) {
            if(i==(y1+1)) arr[x1][i] = save;
            else arr[x1][i] = arr[x1][i-1];
            //cout << arr[x1][i] << "->";
            if(arr[x1][i] < mval) mval = arr[x1][i];
        }
        //cout << endl;
        answer.push_back(mval);
    }
    return answer;
}
