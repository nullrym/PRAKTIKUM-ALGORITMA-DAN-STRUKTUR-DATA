#include <iostream>
#include <string>
#include "RedBlackTree.h"

using namespace std;

void print_preorder(const RedBlackTree::Node* node) {
    if (node->isNil) return;
    
    cout << " " << node->key;
    print_preorder(node->left);
    print_preorder(node->right);
}

void print_inorder(const RedBlackTree::Node* node) {
    if (node->isNil) return;
    
    print_inorder(node->left);
    cout << " " << node->key;
    print_inorder(node->right);
}

void print_postorder(const RedBlackTree::Node* node) {
    if (node->isNil) return;
    
    print_postorder(node->left);
    print_postorder(node->right);
    cout << " " << node->key;
}

int main() {
    int N;
    cin >> N;

    RedBlackTree rbt;
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        
        if (!rbt.contains(A)) {
            rbt.insert(A);
        }
    }

    int Q;
    cin >> Q;
    
    for (int i = 0; i < Q; i++) {
        string T;
        cin >> T;

        if (rbt.empty()) {
            cout << "Tree kosong. Tidak ada yang bisa ditampilkan.\n";
            continue;
        }

        if (T == "PREORDER" || T == "ALL") {
            cout << "[Preorder] :";
            print_preorder(rbt.root());
            cout << "\n";
        }
        if (T == "INORDER" || T == "ALL") {
            cout << "[Inorder] :";
            print_inorder(rbt.root());
            cout << "\n";
        }
        if (T == "POSTORDER" || T == "ALL") {
            cout << "[Postorder]:";
            print_postorder(rbt.root());
            cout << "\n";
        }
    }

    return 0;
}