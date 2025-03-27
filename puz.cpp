#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <iostream>


// Пузырь
void bubblesort(unsigned arr[], unsigned n) {
    bool swapped;

    
    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        
        for (int j = 0; j < n - i - 1; j++) {
            
            if (arr[j] > arr[j + 1]) {
                
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        
        if (!swapped) {
            break;
        }
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
    bubblesort(array, n);
    auto end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << ',';
    delete[] array;
}

int main() {
    for (size_t n = 1; n < 10000; n=n+10) test(n);
    for(int j=0; j<10000; j=j+10){
        std::cout<<j<<',';
    }
    return 0;

}