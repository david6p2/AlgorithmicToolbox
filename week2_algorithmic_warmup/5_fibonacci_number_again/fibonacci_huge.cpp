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

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
