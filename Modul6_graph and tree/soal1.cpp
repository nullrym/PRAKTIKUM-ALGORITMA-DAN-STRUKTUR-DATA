#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    char vertex[10];
    for (int i = 0; i < N; i++) {
        cin >> vertex[i];
    }

    int M;
    cin >> M;
    
    int matrix[10][10];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < M; i++) {
        char U, V;
        int W;
        cin >> U >> V >> W;
        
        int indexU = 0, indexV = 0;
        
        for (int j = 0; j < N; j++) {
            if (vertex[j] == U) indexU = j;
            if (vertex[j] == V) indexV = j;
        }
        
        matrix[indexU][indexV] = W;
    }

    cout << "Adjacency Matrix:\n  ";
    for (int i = 0; i < N; i++) {
        cout << vertex[i];
        if (i != N - 1) cout << " ";
    }
    cout << "\n";

    for (int i = 0; i < N; i++) {
        cout << vertex[i] << " ";
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j];
            if (j != N - 1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}