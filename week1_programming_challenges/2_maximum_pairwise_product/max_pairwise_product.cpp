#include <algorithm>
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>
/*
int MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

*/

void maintain_max_pair(std::pair<int, int> &largest_pair, int next) {
  if (largest_pair.first < largest_pair.second && next > largest_pair.first) {
    largest_pair.first = next;
  } else if (next > largest_pair.second) {
    largest_pair.second = next;
  }
}

int64_t MaxPairwiseProduct(const std::vector<int> &numbers) {
  int64_t max_product = 0;
  int n = numbers.size();
  std::pair<int, int> largestPair(numbers[0], numbers[1]);
  for (int i = 2; i < n; i++) {
    maintain_max_pair(largestPair, numbers[i]);
  }
  max_product = static_cast<int64_t>(largestPair.first) *
                static_cast<int64_t>(largestPair.second);
  return max_product;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> numbers(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> numbers[i];
  }

  int64_t result = MaxPairwiseProduct(numbers);
  std::cout << result << "\n";
  return 0;
}
