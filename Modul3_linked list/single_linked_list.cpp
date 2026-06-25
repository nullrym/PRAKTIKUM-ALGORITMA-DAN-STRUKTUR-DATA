#include <iostream>
#include "single_linked_list.h"

using namespace std;

void SingleLinkedList::init() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool SingleLinkedList::is_empty() {
    return size == 0;
}

void SingleLinkedList::add_front(int val) {
    Node* ptr_new = new Node;
    ptr_new->data = val;
    ptr_new->next = nullptr;

    if (is_empty()) {
        head = tail = ptr_new;
        ptr_new->next = head; 
    } else {
        ptr_new->next = head;
        head = ptr_new;
        tail->next = head;
    }
    size++;
}

void SingleLinkedList::add_back(int val) {
    Node* ptr_new = new Node;
    ptr_new->data = val;
    ptr_new->next = nullptr;

    if (is_empty()) {
        head = tail = ptr_new;
        ptr_new->next = head;
    } else {
        tail->next = ptr_new;
        ptr_new->next = head;
        tail = ptr_new;
    }
    size++;
}

void SingleLinkedList::add_idx(int val, int idx) {
    if (idx < 0 || idx > size) throw "Indeks di luar batas"; 
    
    if (idx == 0) { add_front(val); return; }
    if (idx == size) { add_back(val); return; }
    
    Node* ptr_new = new Node;
    ptr_new->data = val;
    ptr_new->next = nullptr;

    Node* ptr_curr = head;
    for (int i = 0; i < idx - 1; i++) {
        ptr_curr = ptr_curr->next;
    }
    ptr_new->next = ptr_curr->next;
    ptr_curr->next = ptr_new;
    size++;
}

void SingleLinkedList::delete_front() {
    if (is_empty()) throw "Senarai kosong"; 
    
    if (size == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
        size = 0;
        return;
    }
    Node* ptr_del = head;
    head = head->next;
    tail->next = head;
    delete ptr_del;
    size--;
}

void SingleLinkedList::delete_back() {
    if (is_empty()) throw "Senarai kosong"; 
    
    if (size == 1) { 
        delete_front(); 
        return; 
    }
    
    Node* ptr_curr = head;
    while (ptr_curr->next != tail) {
        ptr_curr = ptr_curr->next;
    }
    delete tail;
    tail = ptr_curr;
    tail->next = head;
    size--;
}

void SingleLinkedList::delete_idx(int idx) {
    if (is_empty() || idx < 0 || idx >= size) throw "Indeks di luar batas"; 
    
    if (idx == 0) { delete_front(); return; }
    if (idx == size - 1) { delete_back(); return; }
    
    Node* ptr_curr = head;
    for (int i = 0; i < idx - 1; i++) {
        ptr_curr = ptr_curr->next;
    }
    Node* ptr_del = ptr_curr->next;
    ptr_curr->next = ptr_del->next;
    delete ptr_del;
    size--;
}

void SingleLinkedList::display() {
    if (is_empty()) {
        cout << "EMPTY" << endl;
        return;
    }
    Node* ptr_curr = head;
    for (int i = 0; i < size; i++) {
        cout << ptr_curr->data;
        if (i < size - 1) {
            cout << " -> ";
        }
        ptr_curr = ptr_curr->next;
    }
    cout << endl;
}

int SingleLinkedList::get(int idx) {
    if (is_empty() || idx < 0 || idx >= size) throw "Indeks di luar batas"; 
    
    Node* ptr_curr = head;
    for (int i = 0; i < idx; i++) {
        ptr_curr = ptr_curr->next;
    }
    return ptr_curr->data;
}

void SingleLinkedList::set(int val, int idx) {
    if (is_empty() || idx < 0 || idx >= size) throw "Indeks di luar batas"; 
    
    Node* ptr_curr = head;
    for (int i = 0; i < idx; i++) {
        ptr_curr = ptr_curr->next;
    }
    ptr_curr->data = val;
}

void SingleLinkedList::clear() {
    while (!is_empty()) {
        delete_front();
    }
}
