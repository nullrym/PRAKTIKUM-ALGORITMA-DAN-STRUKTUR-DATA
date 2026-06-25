#include <iostream>

using namespace std;

int R, C;

int G[10][10];
bool visited[10][10];

int FR, FC;
int T = 0; 

int direction_row[] = {-1, 1, 0, 0};
int direction_column[] = {0, 0, -1, 1};

void dfs(int row, int column) {
    if (row == FR && column == FC) {
        T++;
        return;
    }

    visited[row][column] = true;

    for (int i = 0; i < 4; i++) {
        int next_row = row + direction_row[i];
        int next_column = column + direction_column[i];

        if (next_row >= 0 && next_row < R && next_column >= 0 && next_column < C) {
            if (G[next_row][next_column] == 0 && !visited[next_row][next_column]) {
                dfs(next_row, next_column);
            }
        }
    }

    visited[row][column] = false; 
}

int main() {
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> G[i][j];
            visited[i][j] = false;
        }
    }

    int SR, SC;
    cin >> SR >> SC;
    cin >> FR >> FC;

    dfs(SR, SC);

    cout << T << "\n";
    return 0;
}