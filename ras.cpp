
#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <iostream>

int swp;

// Грубая сортировка
void stepSort(unsigned arr[], int n, int step) {
    for (int i = 0; i < n - step; i++) {
        if (arr[i] > arr[i + step]) {
            std::swap(arr[i], arr[i + step]); 
            swp++;
        }
    }
}

// Пузырь
void bubbleSort(unsigned arr[], int n) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swp++;
                swapped = true;
            }
        }
    } while (swapped); 
}

// Расчёска
void combSort(unsigned arr[], int n) {
    int swp;
    swp=0;
    int step = n; 
    bool swapped;

    do {
        
        step = step / 2; 

        if (step < 1) {
            step = 1; 
        }

        swapped = false;

        
        stepSort(arr, n, step);
     } while (step > 1 || swapped); 

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
    bubbleSort(arr, n);
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
    swp=0;
    combSort(array, n);
    auto end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << ',';
    delete[] array;
}
int main() {
    int a[1000];
    int h;
    h=0;
    for (size_t n = 1; n < 10000; n=n+10){ 
        test(n);
        a[h]=swp;
        h++;
    }
    std::cout<<'\n';
    for(int j=0; j<1000; j++){
        std::cout<<a[j]<<',';
    }
    return 0;

}