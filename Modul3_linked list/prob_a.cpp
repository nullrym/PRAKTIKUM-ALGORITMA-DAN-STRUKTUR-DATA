#include <iostream>
#include "single_linked_list.h"

using namespace std;

int main() {
    int N, K; 
    if (!(cin >> N >> K)) return 0;

    SingleLinkedList list;
    list.init();

    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        list.add_back(val);
    }

    int init_k = K; 
    int curr_idx = 0; 

    while (list.size > 1) {
        int target_idx = (curr_idx + (K - 1)) % list.size; 
        int target_val = list.get(target_idx); 

        list.delete_idx(target_idx);

        curr_idx = target_idx % list.size;

        if (target_val % 2 == 0) {
            K++;
        } else {
            K--;
        }

        if (K <= 0) {
            K = init_k;
        }
    }

    cout << list.get(0) << endl;
    
    list.clear();
    return 0;
}
