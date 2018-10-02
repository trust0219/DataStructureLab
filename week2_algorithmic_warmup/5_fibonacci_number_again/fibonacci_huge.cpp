#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void vector_print(vector<long long> &v) {
  for (auto n : v) {
    cout << n << " ";
  }
  cout << endl;
}

long long get_fibonacci_huge_naive(long long n, long long m) {
  if (n <= 1) return n;

  long long previous = 0;
  long long current = 1;

  for (long long i = 0; i < n - 1; ++i) {
    long long tmp_previous = previous;
    previous = current;
    current = tmp_previous + current;
  }

  return current % m;
}

long long fibonacci_fast(long long n) {
  // write your code here
  if (n <= 1) return n;
  vector<long long> fib_sequence;
  fib_sequence.emplace_back(0);
  fib_sequence.emplace_back(1);
  fib_sequence.emplace_back(1);
  for (long long i = 2; i < n; ++i) {
    long long b = fib_sequence[1];
    fib_sequence[0] = b;
    fib_sequence[1] = fib_sequence[2];
    fib_sequence[2] = fib_sequence[0] + fib_sequence[1];
  }
  return fib_sequence[2];
}

long long get_fibonacci_huge_efficient(long long n, long long m) {
  long long first = 0;
  long long second = 1;
  long long pisano_period = 2;

  while (true) {
    long long second_copy = second;
    second = (first + second) % m;
    first = second_copy;
    pisano_period++;
    if (first == 0 && second == 1) break;
  }
  pisano_period -= 2;
  int pisanoed_num = n % pisano_period;

  first = 0;
  second = 1;
  if (pisanoed_num == 0) {
    return first;
  } else if (pisanoed_num == 1) {
    return second;
  }
  int counter = 2;
  while (counter <= pisanoed_num) {
    long long second_copy = second;
    second = (first + second) % m;
    first = second_copy;
    counter++;
  }
  return second;
  //
}

void testing() {
  assert(get_fibonacci_huge_efficient(2816213588, 239) == 151);
  assert(get_fibonacci_huge_efficient(1000, 100) == 75);
  assert(get_fibonacci_huge_efficient(239, 1000) == 161);
  //
}

int main() {
  // testing();
  long long n, m;
  std::cin >> n >> m;
  cout << get_fibonacci_huge_efficient(n, m) << endl;
}
