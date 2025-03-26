#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <iostream>

// прямой проход
void forward_step(unsigned arr[], unsigned const begin_idx, unsigned const end_idx) {
    for (unsigned i = begin_idx; i < end_idx; ++i) {
        if (arr[i] > arr[i + 1]) {
            std::swap(arr[i], arr[i + 1]);
        }
    }
}

// обратный проход
void backward_step(unsigned arr[], unsigned const begin_idx, unsigned const end_idx) {
    for (unsigned i = end_idx; i > begin_idx; --i) {
        if (arr[i - 1] > arr[i]) {
            std::swap(arr[i - 1], arr[i]);
        }
    }
}

// Шейкерная сортировка
void shaker_sort(unsigned arr[], unsigned const begin_idx, unsigned const end_idx) {
    bool swapped = true;
    unsigned start = begin_idx;
    unsigned end = end_idx;

    while (swapped) {
        swapped = false;

        for (unsigned i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;

        --end;

        for (unsigned i = end; i > start; --i) {
            if (arr[i - 1] > arr[i]) {
                std::swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        }

        ++start;
    }
}




constexpr int upper_bound = 1'0'000;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());


unsigned* generate_array(size_t n) {
    unsigned* array = new unsigned[n];
    for (size_t i = 0; i < n; i++) {
        array[i] = rng() % upper_bound;
    }
    return array;
}

void test(size_t n) {
    unsigned* array = generate_array(n);
    auto begin = std::chrono::steady_clock::now();
    shaker_sort(array, 0, n);
    auto end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << ',';
    delete[] array;
}

int main() {
    for (size_t n = 1; n < 10000; n=n+10) test(n);
    for(int j=0; j<10000; j=j+100){
        std::cout<<j<<',';
    }
    return 0;

}
