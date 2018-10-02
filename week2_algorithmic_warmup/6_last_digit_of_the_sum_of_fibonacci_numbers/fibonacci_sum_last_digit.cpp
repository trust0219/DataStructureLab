#include <iostream>
using namespace std;

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

int fibonacci_sum_naive(long long n) {
  if (n <= 1) return n;

  long long previous = 0;
  long long current = 1;
  long long sum = 1;

  for (long long i = 0; i < n - 1; ++i) {
    long long tmp_previous = previous;
    previous = current;
    current = tmp_previous + current;
    sum += current;
  }

  return sum % 10;
}

int fibonacci_sum_efficient(long long n) {
  //
  n %= 60;
  if (n == 0) return 0;
  int first = 0, second = 1, sum = 1;
  for (int i = 2; i <= n; ++i) {
    int second_copy = second;
    second = (first + second) % 10;
    first = second_copy;
    sum = (sum + second) % 10;
  }
  return sum;
}

int main() {
  long long n = 0;
  std::cin >> n;
  //   cout << "naive: ";
  //   std::cout << fibonacci_sum_naive(n) << endl;
  //   cout << "efficient:";

  cout << fibonacci_sum_efficient(n) << endl;
  //   for (int i = 0; i < n; i++) {
  //     cout << fibonacci_sum_efficient(i) << " ";
  //   }
}
