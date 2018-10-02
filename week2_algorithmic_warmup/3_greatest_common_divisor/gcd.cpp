#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_efficient(int a, int b) {
  if (b == 0)
    return a;
  else {
    return gcd_efficient(b, a % b);
  }
}

// void testing(int a, int b) { assert(gcd_naive(a, b) == gcd_efficient(a, b));
// }

int main() {
  int a, b;
  std::cin >> a >> b;
  // testing(a, b);
  // std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd_efficient(a, b) << std::endl;
  return 0;
}
