#include <iostream>
#include <chrono>
#include <random>

#define N 1000000
#define MAX 1000000


int Sp1(int flag, int (&arr)[N], int x) {
    for(int resalt = 0; resalt < flag; ++resalt) 
        if(arr[resalt] == x) 
        return resalt;
    return -1;
}

int Sp2(int flag, int (&arr)[N], int x) {
    bool flag = false;
    int l = 0;  
    int r = flag-1; 
    int mid;
    while ((l <= r) && (flag != true) && r <= flag && l >= 0) {
        mid = (l + r) / 2;  
        if (arr[mid] == x) flag = true;  
        else if (arr[mid] > x) r = mid - 1; 
        else l = mid + 1;
    }
    if(flag) return mid;
    return -1;
}

int main(){
    int x[N];
    std::default_random_engine rng(time(NULL));
    int max_rand[5] = {10000, 100000, 500000, 1000000, 1500000};

    for(int j = 0; j < 5; ++j){
        std::cout << std::endl <<  "max: " << max_rand[j] << std::endl;
        for(unsigned cnt = 100; cnt <= N; cnt +=  cnt >= 1000 ? (cnt >= 10000 ? (cnt >= 100000 ? 100000 : 10000): 1000) : 100){    
            std::uniform_int_distribution <unsigned> dstr(0, max_rand[j]);
            for(unsigned i = 0; i < cnt; ++i) x[i] = dstr(rng);

            auto begin = std::chrono::steady_clock::now();
            for(unsigned j = 100000; j != 0; --j)

            Sp1(cnt, x, dstr(rng));

            auto end = std::chrono::steady_clock::now();
            auto time_span = std::chrono::duration_cast <std::chrono::milliseconds> (end - begin);
            std::cout << time_span.count() << ", ";
        }
    }
    
    std::cout << std::endl << std::endl;
    for(unsigned cnt = 100; cnt <= N; cnt +=  cnt >= 1000 ? (cnt >= 10000 ? (cnt >= 100000 ? 100000 : 10000): 1000) : 100) std::cout << cnt << ", ";

    return 0;
}
