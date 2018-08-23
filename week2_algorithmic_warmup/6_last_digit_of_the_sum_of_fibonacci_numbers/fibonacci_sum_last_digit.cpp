#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
        sum = (sum + current)%10;
    }

    return sum;
}

int fibonacci_sum_fast(long long n) {
    long long firstSum = 0;
    //If n / 60 > 1
    if (n/60 >= 1) {
         // find the sum of the first 60 fib
        firstSum = fibonacci_sum_naive(60);
        // multiply this sum by n / 60
        firstSum *= n/60;
    }
    // find the fib for n % 60
    long long lastSum = fibonacci_sum_naive(n%60);
    
    // sum both results
    return firstSum + lastSum;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n) << '\n';
}
