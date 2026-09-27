// Day 12 - 10/09 : Simulation / Implementation
// 문제 조건을 그대로 코드로 옮긴다. State / Direction / Boundary / 반복
#include <bits/stdc++.h>
using namespace std;

// 방향 : 북(0) 동(1) 남(2) 서(3) - 시계 방향 순서로 두면 회전이 쉬워진다
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int turnRight(int d) { return (d + 1) % 4; }
int turnLeft(int d) { return (d + 3) % 4; }    // (d - 1) % 4 는 음수가 나올 수 있다
int reverseDir(int d) { return (d + 2) % 4; }

// 1) 로봇 명령 시뮬레이션
//    'L' 왼쪽 회전, 'R' 오른쪽 회전, 'F' 한 칸 전진 (벽/경계면 제자리)
struct Robot {
    int x, y, dir;
};

Robot runCommands(const vector<string>& board, Robot r, const string& cmds) {
    int R = board.size(), C = board[0].size();
    for (char c : cmds) {
        if (c == 'L') r.dir = turnLeft(r.dir);
        else if (c == 'R') r.dir = turnRight(r.dir);
        else if (c == 'F') {
            int nx = r.x + dx[r.dir], ny = r.y + dy[r.dir];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C || board[nx][ny] == '#') continue;
            r.x = nx;
            r.y = ny;
        }
    }
    return r;
}

// 2) 2D 배열 회전 (시계 방향 90도) : N x M → M x N
//    new[j][N-1-i] = old[i][j]
vector<vector<int>> rotateCW(const vector<vector<int>>& a) {
    int n = a.size(), m = a[0].size();
    vector<vector<int>> b(m, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) b[j][n - 1 - i] = a[i][j];
    return b;
}

// 3) 뱀 게임 (deque로 몸 관리)
//    머리가 앞으로 이동 → 사과 있으면 꼬리 유지, 없으면 꼬리 제거
//    벽 또는 자기 몸에 부딪히면 종료 → 종료 시각 반환
//    turns : {시각, 'L'/'D'} - 해당 시각이 "끝난 뒤" 회전
int snakeGame(int n, set<pair<int, int>> apples, map<int, char> turns) {
    vector<vector<bool>> body(n, vector<bool>(n, false));
    deque<pair<int, int>> snake;    // front = 머리, back = 꼬리
    snake.push_back({0, 0});
    body[0][0] = true;
    int dir = 1;                    // 오른쪽(동)으로 시작
    int t = 0;
    while (true) {
        t++;
        auto [hx, hy] = snake.front();
        int nx = hx + dx[dir], ny = hy + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || body[nx][ny]) break;

        snake.push_front({nx, ny});
        body[nx][ny] = true;
        if (apples.count({nx, ny})) {
            apples.erase({nx, ny});     // 사과는 한 번만
        } else {
            auto [tx, ty] = snake.back();
            body[tx][ty] = false;
            snake.pop_back();
        }

        if (turns.count(t)) dir = (turns[t] == 'D') ? turnRight(dir) : turnLeft(dir);
    }
    return t;
}

// 4) 달팽이 배열 : 방향 전환 규칙을 "막히면 오른쪽 회전"으로 표현
vector<vector<int>> spiral(int n) {
    vector<vector<int>> a(n, vector<int>(n, 0));
    int x = 0, y = 0, d = 1;
    for (int k = 1; k <= n * n; k++) {
        a[x][y] = k;
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || a[nx][ny] != 0) {
            d = turnRight(d);
            nx = x + dx[d];
            ny = y + dy[d];
        }
        x = nx;
        y = ny;
    }
    return a;
}

void printGrid(const vector<vector<int>>& a) {
    for (auto& row : a) {
        for (int v : row) cout << setw(3) << v;
        cout << '\n';
    }
}

int main() {
    vector<string> board = {
        ".....",
        ".#...",
        ".....",
    };
    Robot r = runCommands(board, {2, 0, 0}, "FFRFFFRFLF");
    cout << "robot : (" << r.x << "," << r.y << ") dir=" << r.dir << '\n';  // (1,4) dir=1

    cout << "rotateCW :\n";
    printGrid(rotateCW({{1, 2, 3}, {4, 5, 6}}));

    // BOJ 3190 뱀 예제 1 : 답 9
    cout << "snake : " << snakeGame(6, {{2, 3}, {1, 4}, {3, 3}}, {{3, 'D'}, {15, 'L'}, {17, 'D'}}) << '\n';

    cout << "spiral :\n";
    printGrid(spiral(4));
    return 0;
}
