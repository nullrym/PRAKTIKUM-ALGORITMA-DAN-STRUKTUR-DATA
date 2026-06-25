#include <iostream>
#include <queue>

using namespace std;

struct Position {
    int row, column, distance;
};

int G[105][105];
bool visited[105][105];

int main() {
    int R, C;
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> G[i][j];
            visited[i][j] = false; 
        }
    }

    int SR, SC;
    cin >> SR >> SC;
    
    int FR, FC;
    cin >> FR >> FC;

    queue<Position> queue_positions;
    queue_positions.push({SR, SC, 0});
    visited[SR][SC] = true;

    int X = -1; 
    int direction_row[] = {-1, 1, 0, 0};
    int direction_column[] = {0, 0, -1, 1};

    while (!queue_positions.empty()) {
        Position current = queue_positions.front();
        queue_positions.pop();

        if (current.row == FR && current.column == FC) {
            X = current.distance;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int next_row = current.row + direction_row[i];
            int next_column = current.column + direction_column[i];

            if (next_row >= 0 && next_row < R && next_column >= 0 && next_column < C) {
                if (G[next_row][next_column] == 0 && !visited[next_row][next_column]) {
                    visited[next_row][next_column] = true;
                    queue_positions.push({next_row, next_column, current.distance + 1});
                }
            }
        }
    }

    cout << X << "\n";
    return 0;
}