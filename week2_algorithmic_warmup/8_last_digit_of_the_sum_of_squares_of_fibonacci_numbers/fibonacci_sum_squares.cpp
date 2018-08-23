#include <iostream>

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

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int fibonacci_sum_squares_fast(long long n) {
    return (get_fibonacci_huge_fast(n, 10) * get_fibonacci_huge_fast(n+1, 10))%10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n) << '\n';
}
