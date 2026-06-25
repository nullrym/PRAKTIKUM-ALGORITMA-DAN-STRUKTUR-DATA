#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    char vertex[10];
    for (int i = 0; i < N; i++) {
        cin >> vertex[i];
    }

    int matrix[10][10];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Adjacency List:\n";
    for (int i = 0; i < N; i++) {
        cout << vertex[i] << " -> ";
        
        bool hasEdge = false;
        
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] > 0) { 
                if (hasEdge) {
                    cout << ", ";
                }
                cout << "(" << vertex[j] << "," << matrix[i][j] << ")";
                hasEdge = true; 
            }
        }
        
        if (!hasEdge) {
            cout << "-";
        }
        cout << "\n";
    }
    
    return 0;
}