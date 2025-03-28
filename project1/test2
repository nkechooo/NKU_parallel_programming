#include<iostream>
#include<cmath>
#include<windows.h>
using namespace std;

int n = 30;
const long long int N = pow(2,n);
long long int* arr=new long long int[N];
int loop = 300 / n;

void init() {
    for (long long int i = 0; i < N; i++) {
        arr[i] = i;
    }
}


void common_alg() {
    long long head, tail, freq;
    QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
    QueryPerformanceCounter((LARGE_INTEGER*)&head);
 
    for (int times = 0; times < loop; times++) { 
        long long int sum = 0;
        for (long long int i = 0; i < N; i++) {
            sum += arr[i];
        }
    }

    QueryPerformanceCounter((LARGE_INTEGER*)&tail);

    cout << "commom_time: " << (tail - head) * 1000.0 / freq / loop << " ms" << endl;
}


void recur(int n){
        if (n == 1) {
            return;
        }
        else {
            for (int i = 0; i < n/ 2; i++) {
                arr[i] += arr[n - i - 1];
            }
            n = n / 2;
            recur(n);
        }
    }


void recursion_alg() {
    long long head, tail, freq;
    QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
    QueryPerformanceCounter((LARGE_INTEGER*)&head);

    
    for (int times = 0; times < loop; times++) {
        recur(N);
    }

    QueryPerformanceCounter((LARGE_INTEGER*)&tail);

    cout << "recursion_time: " << (tail - head) * 1000.0 / freq / loop << " ms" << endl;
}


void LOOP_alg() {
    long long head, tail, freq;
    QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
    QueryPerformanceCounter((LARGE_INTEGER*)&head);

    for (int times = 0; times < loop; times++) {
        for (int m = N; m > 1; m = (m + 1) / 2) {
            for (int i = 0; i < m / 2; i++) {
                arr[i] = arr[i * 2] + arr[i * 2 + 1];
            }
        }
    }

    QueryPerformanceCounter((LARGE_INTEGER*)&tail);

    cout <<"LOOP_time: " << (tail - head) * 1000.0 / freq / loop << " ms" << endl;
}


void unroll_alg() {
    long long head, tail, freq;
    QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
    QueryPerformanceCounter((LARGE_INTEGER*)&head);

    for (int times = 0; times < loop; times++) {
        long long int sum = 0, sum1 = 0, sum2 = 0;
        for (long long int i = 0; i < N; i += 2) {
            sum1 += arr[i];
            sum2 += arr[i + 1];
        }
        sum = sum1 + sum2;
    }
   
    QueryPerformanceCounter((LARGE_INTEGER*)&tail);

    cout << "unroll_time: " << (tail - head) * 1000.0 / freq / loop << " ms" << endl;
}


int main() {
    init();
    common_alg();
    recursion_alg();
    LOOP_alg(); 
    unroll_alg();

    return 0;
}

