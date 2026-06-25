#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;
    if (k < 1) return 0;

    Queue q;
    init(&q);

    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        enqueue(&q, x);
        sum += x;
        
        if (i >= k) {
            sum -= front(&q);
            dequeue(&q);
        }
        
        if (i >= k - 1) {
            if (i > k - 1) cout << " ";
            cout << sum;
        }
    }
    cout << endl;
    
    return 0;
}
