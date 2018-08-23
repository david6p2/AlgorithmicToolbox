//
//  my_max_pairwise_product.cpp
//  
//
//  Created by David A Cespedes R on 7/26/18.
//

#include <iostream>
#include <vector>
#include <algorithm>


long long MaxPairwiseProduct(const std::vector<long long>& numbers) {
    long long max_product = 0;
    long long n = numbers.size();
    
    long long firstIndex = -1;
    
    for (int first = 0; first < n; ++first) {
        if (firstIndex == -1 || numbers[first] > numbers[firstIndex]) {
            firstIndex = first;
        }
    }
    long long secondIndex = -1;
    
    for (int second = 0; second < n; ++second) {
        if ((second != firstIndex) && ((secondIndex == -1) || (numbers[second] > numbers[secondIndex]))) {
            secondIndex = second;
        }
    }
    
    return ((long long)(numbers[firstIndex])) * numbers[secondIndex];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    
    long long result = MaxPairwiseProduct(numbers);
    std::cout << result << "\n";
    return 0;
}
