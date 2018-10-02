#include <iostream>
using namespace std;

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long)a * b; ++l)
    if (l % a == 0 && l % b == 0) return l;

  return (long long)a * b;
}

int gcd_efficient(int a, int b) {
  if (b == 0)
    return a;
  else {
    return gcd_efficient(b, a % b);
  }
}

long long lcm_efficient(int a, int b) {
  return (long long)a * b / gcd_efficient(a, b);
}

// void testing(int a, int b) { assert(lcm_naive(a, b) == lcm_efficient(a, b));
// }

int main() {
  int a, b;
  std::cin >> a >> b;
  // testing(a, b);
  // std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_efficient(a, b) << std::endl;
  return 0;
}
