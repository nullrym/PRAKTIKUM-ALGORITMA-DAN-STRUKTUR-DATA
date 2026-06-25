#include <iostream>
#include "double_linked_list.h"

using namespace std;

int main() {
    int N, R;
    if (!(cin >> N >> R)) return 0;

    DoubleLinkedList list;
    list.init();

    for (int i = 0; i < N; i++) {
        char input_char;
        cin >> input_char;
        list.add_back(input_char);
    }

    Node* ptr_alpha = list.head; 
    Node* ptr_beta = list.tail; 

    for (int i = 0; i < R; i++) {
        long long X, Y;
        if (!(cin >> X >> Y)) break;

        if (list.size == 0) {
            break;
        }

        long long step_alpha = X % list.size;
        for (long long j = 0; j < step_alpha; j++) {
            ptr_alpha = ptr_alpha->next;
        }

        long long step_beta = Y % list.size;
        for (long long j = 0; j < step_beta; j++) {
            ptr_beta = ptr_beta->prev;
        }

        if (ptr_alpha == ptr_beta) {
            Node* ptr_del = ptr_alpha; 
            
            if (list.size == 1) {
                delete ptr_del;
                list.head = nullptr;
                list.tail = nullptr;
                list.size = 0;
                ptr_alpha = nullptr;
                ptr_beta = nullptr;
            } else {
                ptr_alpha = ptr_del->next;
                ptr_beta = ptr_del->prev;

                ptr_del->prev->next = ptr_del->next;
                ptr_del->next->prev = ptr_del->prev;

                if (list.head == ptr_del) {
                    list.head = ptr_del->next;
                }
                if (list.tail == ptr_del) {
                    list.tail = ptr_del->prev;
                }

                delete ptr_del;
                list.size--;
            }
        } 
        else if (ptr_alpha->next == ptr_beta || ptr_alpha->prev == ptr_beta) {
            bool is_edge = (ptr_alpha == list.head && ptr_beta == list.tail) || (ptr_alpha == list.tail && ptr_beta == list.head);
            if (!(is_edge && list.size > 2)) {
                char temp = ptr_alpha->data;
                ptr_alpha->data = ptr_beta->data;
                ptr_beta->data = temp;
            }
        }
    }

    if (list.size == 0) {
        cout << "EMPTY" << endl;
    } else {
        Node* ptr_curr = list.head;
        for (int i = 0; i < list.size; i++) {
            cout << ptr_curr->data;
            ptr_curr = ptr_curr->next;
        }
        cout << endl;
    }

    list.clear();
    return 0;
}
