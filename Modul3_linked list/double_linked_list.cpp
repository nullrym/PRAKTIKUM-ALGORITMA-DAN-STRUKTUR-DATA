#include <iostream>
#include "double_linked_list.h"

using namespace std;

void DoubleLinkedList::init() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool DoubleLinkedList::is_empty() {
    return size == 0;
}

void DoubleLinkedList::add_front(char val) {
    Node* ptr_new = new Node;
    ptr_new->data = val;
    ptr_new->next = nullptr;
    ptr_new->prev = nullptr;

    if (is_empty()) {
        head = ptr_new;
        tail = ptr_new;
        ptr_new->next = ptr_new;
        ptr_new->prev = ptr_new;
    } else {
        ptr_new->next = head;
        ptr_new->prev = tail;
        head->prev = ptr_new;
        tail->next = ptr_new;
        head = ptr_new;
    }
    size++;
}

void DoubleLinkedList::add_back(char val) {
    Node* ptr_new = new Node;
    ptr_new->data = val;
    ptr_new->next = nullptr;
    ptr_new->prev = nullptr;

    if (is_empty()) {
        head = ptr_new;
        tail = ptr_new;
        ptr_new->next = ptr_new;
        ptr_new->prev = ptr_new;
    } else {
        ptr_new->prev = tail;
        ptr_new->next = head;
        tail->next = ptr_new;
        head->prev = ptr_new;
        tail = ptr_new;
    }
    size++;
}

void DoubleLinkedList::add_idx(char val, int idx) {
    if (idx < 0 || idx > size) return; 
    
    if (idx == 0) { add_front(val); return; }
    if (idx == size) { add_back(val); return; }
    
    Node* ptr_curr = head;
    for (int i = 0; i < idx; i++) {
        ptr_curr = ptr_curr->next;
    }

    Node* ptr_new = new Node;
    ptr_new->data = val;
    ptr_new->next = ptr_curr;
    ptr_new->prev = ptr_curr->prev;

    ptr_curr->prev->next = ptr_new;
    ptr_curr->prev = ptr_new;
    size++;
}

void DoubleLinkedList::delete_front() {
    if (is_empty()) return;
    if (size == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
        size = 0;
        return;
    }
    Node* ptr_del = head;
    head = head->next;
    head->prev = tail;
    tail->next = head;
    delete ptr_del;
    size--;
}

void DoubleLinkedList::delete_back() {
    if (is_empty()) return;
    if (size == 1) { 
        delete_front(); 
        return; 
    }
    
    Node* ptr_del = tail;
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    delete ptr_del;
    size--;
}

void DoubleLinkedList::delete_idx(int idx) {
    if (is_empty() || idx < 0 || idx >= size) return; 
    
    if (idx == 0) { delete_front(); return; }
    if (idx == size - 1) { delete_back(); return; }
    
    Node* ptr_curr = head;
    for (int i = 0; i < idx; i++) {
        ptr_curr = ptr_curr->next;
    }
    ptr_curr->prev->next = ptr_curr->next;
    ptr_curr->next->prev = ptr_curr->prev;
    delete ptr_curr;
    size--;
}

void DoubleLinkedList::display() {
    if (is_empty()) {
        cout << "EMPTY" << endl;
        return;
    }
    Node* ptr_curr = head;
    for (int i = 0; i < size; i++) {
        cout << ptr_curr->data;
        if (i < size - 1) {
            cout << " <-> ";
        }
        ptr_curr = ptr_curr->next;
    }
    cout << endl;
}

char DoubleLinkedList::get(int idx) {
    if (is_empty() || idx < 0 || idx >= size) return '\0'; 
    Node* ptr_curr = head;
    for (int i = 0; i < idx; i++) {
        ptr_curr = ptr_curr->next;
    }
    return ptr_curr->data;
}

void DoubleLinkedList::set(char val, int idx) {
    if (is_empty() || idx < 0 || idx >= size) return; 
    Node* ptr_curr = head;
    for (int i = 0; i < idx; i++) {
        ptr_curr = ptr_curr->next;
    }
    ptr_curr->data = val;
}

void DoubleLinkedList::clear() {
    while (!is_empty()) {
        delete_front();
    }
}
