#include <iostream>
#include <vector>
using std::vector;

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

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1) {
        return n;
    }
    long long previous = 0;
    long long current  = 1;
    
    for (long long i = 1; i < n; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%m;
        //std::cout << current << '\n';
    }
    //std::cout << current << '\n';
    return current % m;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    if (n <= 1) {
        return n;
    }
    long long previous = 0;
    long long tmp_previous;
    long long current  = 1;
    long long length = 0;
    
    while(true) {
        tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%m;
        //std::cout << length << ". - " << current << '\n';
        length++;
        if (previous%m == 0 && current%m == 1){
            //std::cout << "length " << length << '\n';
            break;
        }
    }
    long long newFib = n%length;
    return get_fibonacci_huge_naive(newFib, m);
}

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    // If `Fm + Fm+1 + … + Fn = F(n) — F(m-1)`
    //if (from == to)
      //  return fibonacci_sum_fast(to);
    return ((get_fibonacci_huge_fast(to+2, 10) + 10) - get_fibonacci_huge_fast(from+1,10)) % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
