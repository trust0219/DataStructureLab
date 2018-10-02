#include <iostream>
#include <vector>

using std::vector;

// Requirement: n should be sum of distinct/sequential integers
// e.g. n = 1,2,3,6,10,...
vector<int> upper_bound(int n) {
  vector<int> retvec;
  if (n == 2) {
    retvec.emplace_back(2);
    return retvec;
  }

  int sum = 1;
  retvec.emplace_back(1);

  while (sum < n) {
    int next = retvec.back() + 1;
    retvec.emplace_back(next);
    sum += next;
  }
  return retvec;
}

vector<int> optimal_summands(int n) {
  vector<int> summands;
  // write your code here
  if (n == 1) {
    summands.emplace_back(1);
    return summands;
  } else if (n == 2) {
    summands.emplace_back(2);
    return summands;
  }
  // n >= 3
  summands.emplace_back(1);
  summands.emplace_back(2);
  int next = 2;
  n -= 3;
  while (true) {
    if (n == 0) {
      break;
    } else if (n <= next) {
      summands.pop_back();
      summands.push_back(next + n);
      break;
    } else {
      next++;
      summands.push_back(next);
      n -= next;
    }
  }

  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
