#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;

struct State {
    int x, y, steps;
    set<char> usedTeleports;
};

bool isValid(int x, int y, int rows, int cols, vector<string>& grid) {
    return x >= 0 && y >= 0 && x < rows && y < cols && grid[x][y] != '#';
}

int minStepsToEnd(vector<string>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    pair<int, int> start, end;
    unordered_map<char, vector<pair<int, int>>> teleporters;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            char c = grid[i][j];
            if (c == 'S') start = {i, j};
            else if (c == 'E') end = {i, j};
            else if (isupper(c)) teleporters[c].push_back({i, j});
        }
    }

    queue<State> q;
    q.push({start.first, start.second, 0, {}});
    set<tuple<int, int, set<char>>> visited;

    int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    while (!q.empty()) {
        auto [x, y, steps, used] = q.front(); q.pop();

        if (x == end.first && y == end.second) return steps;

        if (visited.count({x, y, used})) continue;
        visited.insert({x, y, used});

        for (auto& d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if (isValid(nx, ny, rows, cols, grid)) {
                q.push({nx, ny, steps + 1, used});
            }
        }

        char c = grid[x][y];
        if (isupper(c) && used.find(c) == used.end()) {
            used.insert(c);
            for (auto& [tx, ty] : teleporters[c]) {
                if (tx != x || ty != y) {
                    q.push({tx, ty, steps + 1, used});
                }
            }
        }
    }

    return -1; 
}

int main() {
    vector<string> grid = {
        "S.A.",
        "#.#.",
        "..B.",
        "#.#.",
        "B.AE"
    };

    cout << "Minimum steps: " << minStepsToEnd(grid) << endl;
    return 0;
}


