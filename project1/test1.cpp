#include<iostream>
#include<windows.h>
using namespace std;


const int N = 1600;
int Mat[N][N];
int Vec[N];
int results[N];
int loop = 6000 / N;

void init(int n) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Mat[i][j] = i + j;
        }
        Vec[i] = i;
    }
}


void common_alg() {
    long long head, tail, freq;
    QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
    QueryPerformanceCounter((LARGE_INTEGER*)&head);
    for (int times = 0; times < loop; times++) {    // 循环次数
        for (int i = 0; i < N; i++) {
            results[i] = 0;
            for (int j = 0; j < N; j++) {
                results[i] += Mat[j][i] * Vec[j];
            }
        }
    }
    QueryPerformanceCounter((LARGE_INTEGER*)&tail);

    cout << "commom_time: " << (tail - head) * 1000.0 / freq / loop << " ms" << endl;
}

void cache_alg() {
    long long head, tail, freq;
    QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
    QueryPerformanceCounter((LARGE_INTEGER*)&head);
    for (int times = 0; times < loop; times++) {
        for (int i = 0; i < N; i++) {
            results[i] = 0;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                results[j] += Mat[i][j] * Vec[i];
            }
        }
    }
    
    QueryPerformanceCounter((LARGE_INTEGER*)&tail);

    cout << "cache_time: " << (tail - head) * 1000.0 / freq / loop << " ms" << endl;
}

void unroll_alg() {
    long long head, tail, freq;
    QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
    QueryPerformanceCounter((LARGE_INTEGER*)&head);
    for (int times = 0; times < loop; times++) {
        for (int i = 0; i < N; i++) {
            results[i] = 0;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j += 10) {
                results[j] += Mat[i][j] * Vec[i];
                results[j + 1] += Mat[i][j + 1] * Vec[i];
                results[j + 2] += Mat[i][j + 2] * Vec[i];
                results[j + 3] += Mat[i][j + 3] * Vec[i];
                results[j + 4] += Mat[i][j + 4] * Vec[i];
                results[j + 5] += Mat[i][j + 5] * Vec[i];
                results[j + 6] += Mat[i][j + 6] * Vec[i];
                results[j + 7] += Mat[i][j + 7] * Vec[i];
                results[j + 8] += Mat[i][j + 8] * Vec[i];
                results[j + 9] += Mat[i][j + 9] * Vec[i];
            }
        }
    }

    QueryPerformanceCounter((LARGE_INTEGER*)&tail);

    cout << "unroll_time: " << (tail - head) * 1000.0 / freq / loop << " ms" << endl;
}


int main() {
    
    init(N);
    common_alg();
    cache_alg();
    unroll_alg();
   
    return 0;
}



