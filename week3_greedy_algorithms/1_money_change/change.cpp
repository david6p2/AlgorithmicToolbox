#include <iostream>

int get_change(int m) {
  // write your code here
  int counter10 = 0;
  int counter5 = 0;
  int counter1 = 0;
  // Check if m is divisible by 10
  if ( m / 10 >= 1) {
  // divide by 10 to count how many times is divisible by 10
    counter10 = m / 10;
  // Save the result of the module as the new m
    m = m % 10;
  }
  
  // Check if m is divisible by 5
  if ( m / 5 >= 1) {
    counter5 = m / 5;
    m = m % 5;
  }
    
  // Check if m is divisible by 1
  if ( m / 1 >= 1) {
    counter1 = m / 1;
    m = m % 1;
  }
  // Sum how many times it was divisible by 10, 5 and 1
  return counter10 + counter5 + counter1;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
