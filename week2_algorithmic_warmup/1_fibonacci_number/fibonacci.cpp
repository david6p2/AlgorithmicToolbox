#include <iostream>
#include <cassert>
#include <vector>

// The following code calls a naive algorithm for computing a Fibonacci number.
//
// What to do:
// 1. Compile the following code and run it on an input "40" to check that it is slow.
//    You may also want to submit it to the grader to ensure that it gets the "time limit exceeded" message.
// 2. Implement the fibonacci_fast procedure.
// 3. Remove the line that prints the result of the naive algorithm, comment the lines reading the input,
//    uncomment the line with a call to test_solution, compile the program, and run it.
//    This will ensure that your efficient algorithm returns the same as the naive one for small values of n.
// 4. If test_solution() reveals a bug in your implementation, debug it, fix it, and repeat step 3.
// 5. Remove the call to test_solution, uncomment the line with a call to fibonacci_fast (and the lines reading the input),
//    and submit it to the grader.

long long fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

long long fibonacci_fast(int n) {
    // write your code here
    int fibonacciNumbers[n];
    if (n <= 1)
        return n;
    fibonacciNumbers[0] = 0;
    fibonacciNumbers[1] = 1;
    std::cout << fibonacciNumbers[1] << '\n';
    for (int i = 2; i < n+1; i++) {
        std::cout << "Fast for i = ";
        std::cout << i << '\n';
        fibonacciNumbers[i] = fibonacciNumbers[i-1] + fibonacciNumbers[i-2];
        std::cout << fibonacciNumbers[i] << '\n';
    }
    return fibonacciNumbers[n];
}

void test_solution() {
    std::cout << "For 3" << '\n';
    assert(fibonacci_fast(3) == 2);
    std::cout << "For 10" << '\n';
    assert(fibonacci_fast(10) == 55);
    std::cout << "Testing" << '\n';
    //std::cout << fibonacci_fast(3) << '\n';
    for (int n = 0; n < 20; ++n) {
        std::cout << "This is for" << '\n';
        std::cout << n << '\n';
        long long fast = fibonacci_fast(n);
        std::cout << "This is fast" << '\n';
        std::cout << fast << '\n';
        long long naive = fibonacci_naive(n);
        std::cout << "This is naive" << '\n';
        std::cout << naive << '\n';
        assert(fast == naive);
    }
}

int main() {
    //int n = 0;
    //std::cin >> n;

    //std::cout << fibonacci_naive(n) << '\n';
    test_solution();
    //std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
