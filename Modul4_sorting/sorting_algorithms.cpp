#include "sorting_algorithms.h"
#include <algorithm>
#include <chrono>

using Clock = std::chrono::high_resolution_clock;
// Algoritma Bubble Sort
void bubble_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; 
        for (int j = 0; j < n - i - 1; j++) {
            m.comparisons++;
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
                m.swaps++;
                swapped = true; 
            }
        }
        
        if (!swapped) break;
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}


// Algoritma Selection Sort
void selection_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

    for (int i = 0; i < n - 1; i++) {
        int index_terkecil = i;
        for (int j = i + 1; j < n; j++) {
            m.comparisons++;
            if (data[j] < data[index_terkecil]) {
                index_terkecil = j;
            }
        }
        if (index_terkecil != i) {
            std::swap(data[i], data[index_terkecil]);
            m.swaps++;
        }
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}


// Algoritma Insertion Sort
void insertion_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

    for (int i = 1; i < n; i++) {
        int temp = data[i];
        int j = i - 1;
        
        while (j >= 0) {
            m.comparisons++;
            if (data[j] > temp) {
                data[j + 1] = data[j];
                m.shifts++;
                j--;
            } else {
                break;
            }
        }
        data[j + 1] = temp;
        m.shifts++; 
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}


// Helper Merge Sort
void proses_merge(std::vector<int>& data, int kiri, int tengah, int kanan, Metrics& m) {
    int size_kiri = tengah - kiri + 1;
    int size_kanan = kanan - tengah;

    std::vector<int> arr_kiri(size_kiri);
    std::vector<int> arr_kanan(size_kanan);

    for (int i = 0; i < size_kiri; i++) arr_kiri[i] = data[kiri + i];
    for (int j = 0; j < size_kanan; j++) arr_kanan[j] = data[tengah + 1 + j];

    int i = 0, j = 0, k = kiri;
    while (i < size_kiri && j < size_kanan) {
        m.comparisons++;
        if (arr_kiri[i] <= arr_kanan[j]) {
            data[k] = arr_kiri[i];
            i++;
        } else {
            data[k] = arr_kanan[j];
            j++;
        }
        k++;
    }

    while (i < size_kiri) {
        data[k] = arr_kiri[i];
        i++; k++;
    }
    while (j < size_kanan) {
        data[k] = arr_kanan[j];
        j++; k++;
    }
}

// Helper Merge Sort
void rekursif_merge(std::vector<int>& data, int kiri, int kanan, Metrics& m) {
    m.recursive_calls++;
    if (kiri < kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        rekursif_merge(data, kiri, tengah, m);
        rekursif_merge(data, tengah + 1, kanan, m);
        proses_merge(data, kiri, tengah, kanan, m);
    }
}

// Algoritma Merge Sort
void merge_sort(std::vector<int>& data, Metrics& m) {
    auto start = Clock::now();

    if (data.size() > 1) {
        rekursif_merge(data, 0, data.size() - 1, m);
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}


// Helper Quick Sort
int partisi(std::vector<int>& data, int low, int high, Metrics& m) {
    int pivot = data[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        m.comparisons++;
        if (data[j] < pivot) {
            i++;
            std::swap(data[i], data[j]);
            m.swaps++;
        }
    }
    std::swap(data[i + 1], data[high]);
    m.swaps++;
    return (i + 1);
}

// Helper Quick Sort
void rekursif_quick(std::vector<int>& data, int low, int high, Metrics& m) {
    m.recursive_calls++;
    if (low < high) {
        int titik_partisi = partisi(data, low, high, m);
        rekursif_quick(data, low, titik_partisi - 1, m);
        rekursif_quick(data, titik_partisi + 1, high, m);
    }
}

// Algoritma Quick Sort
void quick_sort(std::vector<int>& data, Metrics& m) {
    auto start = Clock::now();

    if (data.size() > 1) {
        rekursif_quick(data, 0, data.size() - 1, m);
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}


// Helper Radix Sort (Counting Sort) 
void counting_sort(std::vector<int>& data, int exp, Metrics& m) {
    int n = data.size();
    std::vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int digit = (data[i] / exp) % 10;
        count[digit]++;
        m.array_accesses++; 
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
        m.array_accesses += 2; 
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (data[i] / exp) % 10;
        output[count[digit] - 1] = data[i];
        count[digit]--;
        m.array_accesses += 3; 
    }

    for (int i = 0; i < n; i++) {
        data[i] = output[i];
        m.array_accesses++;
    }
}

// Algoritma Radix Sort
void radix_sort(std::vector<int>& data, Metrics& m) {
    if (data.empty()) return;
    auto start = Clock::now();

    int angka_max = data[0];
    for (size_t i = 1; i < data.size(); i++) {
        if (data[i] > angka_max) {
            angka_max = data[i];
        }
    }

    for (int exp = 1; angka_max / exp > 0; exp *= 10) {
        counting_sort(data, exp, m);
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}
