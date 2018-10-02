#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
  if (n <= 1) return n;

  long long previous = 0;
  long long current = 1;
  long long sum = 1;

  for (long long i = 0; i < n - 1; ++i) {
    long long tmp_previous = previous;
    previous = current;
    current = tmp_previous + current;
    sum += current * current;
  }

  return sum % 10;
}

long long fibonacci_sum_efficient(long long n) {
  //
  n %= 60;
  if (n == 0) return 0;
  long long first = 0, second = 1, sum = 1;
  for (int i = 2; i <= n; ++i) {
    long long second_copy = second;
    second = (first + second) % 10;
    first = second_copy;
    sum = (sum + second) % 10;
  }
  return sum;
}
/*
0 1 2 4 7 2 0 3 4 8
3 2 6 9 6 6 3 0 4 5
0 6 7 4 2 7 0 8 9 8
8 7 6 4 1 6 8 5 4 0
5 6 2 9 2 2 5 8 4 3
8 2 1 4 6 1 8 0 9 0
*/
long long get_fibonacci_partial_sum_efficient(long long from, long long to) {
  long long smaller_sum, larger_sum;
  if (from == 0) {
    smaller_sum = 0;
  } else {
    smaller_sum = fibonacci_sum_efficient(from - 1);
  }
  if (to == 0) {
    larger_sum = 0;
  } else {
    larger_sum = fibonacci_sum_efficient(to);
  }

  if (larger_sum < smaller_sum) {
    return 10 + larger_sum - smaller_sum;
  } else {
    return larger_sum - smaller_sum;
  }
}

int fibonacci_sum_squares_efficient(long long n) {
  if (n == 0) return 0;
  int length = get_fibonacci_partial_sum_efficient(n, n);
  int width = get_fibonacci_partial_sum_efficient(n + 1, n + 1);
  return (width * length) % 10;
}

int main() {
  long long n = 0;
  std::cin >> n;

  std::cout << fibonacci_sum_squares_efficient(n) << std::endl;
}
