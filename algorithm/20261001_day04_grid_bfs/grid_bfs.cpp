// Day 4 - 10/01 : BFS / DFS 응용 (2D Grid)
// dx/dy → Queue → Current → Next → Boundary Check → Visited Check
#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};    // 상 하 좌 우
const int dy[4] = {0, 0, -1, 1};

int R, C;
vector<string> board;

bool inRange(int x, int y) { return 0 <= x && x < R && 0 <= y && y < C; }

// 1) 최단거리 BFS : (sx,sy) → (ex,ey), '#'은 벽. 도달 불가면 -1
//    dist를 -1로 초기화하면 visited 배열을 따로 둘 필요 없다
int shortestPath(int sx, int sy, int ex, int ey) {
    vector<vector<int>> dist(R, vector<int>(C, -1));
    queue<pair<int, int>> q;
    dist[sx][sy] = 0;
    q.push({sx, sy});
    while (!q.empty()) {
        auto [x, y] = q.front();                // Current Position
        q.pop();
        if (x == ex && y == ey) return dist[x][y];
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d]; // Next Position
            if (!inRange(nx, ny)) continue;     // Boundary Check (배열 접근보다 먼저!)
            if (board[nx][ny] == '#') continue;
            if (dist[nx][ny] != -1) continue;   // Visited Check
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    return -1;
}

// 2) Multi-source BFS : 시작점이 여러 개 → 처음에 전부 큐에 넣고 한 번에 BFS
//    예) 토마토 : 'S'(익은 토마토)에서 퍼져서 모든 '.'가 익는 데 걸리는 시간
int multiSourceBfs() {
    vector<vector<int>> dist(R, vector<int>(C, -1));
    queue<pair<int, int>> q;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (board[i][j] == 'S') {
                dist[i][j] = 0;
                q.push({i, j});
            }

    int answer = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        answer = max(answer, dist[x][y]);
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (!inRange(nx, ny) || board[nx][ny] == '#' || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    // 도달 못한 칸이 있으면 -1
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (board[i][j] != '#' && dist[i][j] == -1) return -1;
    return answer;
}

// 3) Flood Fill (DFS) : 벽이 아닌 영역의 개수와 각 영역 크기
int fillDfs(int x, int y, vector<vector<bool>>& vis) {
    vis[x][y] = true;
    int size = 1;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (!inRange(nx, ny) || board[nx][ny] == '#' || vis[nx][ny]) continue;
        size += fillDfs(nx, ny, vis);
    }
    return size;
}

vector<int> areas() {
    vector<vector<bool>> vis(R, vector<bool>(C, false));
    vector<int> sizes;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (board[i][j] != '#' && !vis[i][j]) sizes.push_back(fillDfs(i, j, vis));
    sort(sizes.begin(), sizes.end());
    return sizes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    board = {
        "S..#....",
        ".#.#.##.",
        ".#...#..",
        "##.#.#.#",
        "...#...S",
    };
    R = board.size();
    C = board[0].size();

    cout << "shortest (0,0)->(4,7): " << shortestPath(0, 0, 4, 7) << '\n';
    cout << "multi-source time: " << multiSourceBfs() << '\n';

    board[2][4] = '#';  // 벽을 추가해서 영역을 나눠 본다
    cout << "areas:";
    for (int s : areas()) cout << ' ' << s;
    cout << '\n';
    return 0;
}
