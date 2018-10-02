#include <algorithm>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

struct RatioIndexPair {
  double ratio;
  int index;
  RatioIndexPair(double r = 0, int i = 0) : ratio(r), index(i) {}
  bool operator>(const RatioIndexPair &rip) const { return ratio > rip.ratio; }
  friend ostream &operator<<(ostream &os, const RatioIndexPair &rip);
  double get_ratio() { return ratio; }
  int get_index() { return index; }
};

ostream &operator<<(ostream &os, const RatioIndexPair &rip) {
  os << "(" << rip.ratio << ", " << rip.index << ")" << endl;
  return os;
}

double min(double a, double b) {
  if (a < b)
    return a;
  return b;
}

double get_optimal_value(int capacity, vector<int> weights,
                         vector<int> values) {
  double value = 0.0;
  int limit = weights.size();
  vector<RatioIndexPair> value_per_weight;
  for (int i = 0; i < limit; i++) {
    double ratio = static_cast<double>(values[i]) / weights[i];
    value_per_weight.emplace_back(RatioIndexPair(ratio, i));
  }

  std::sort(value_per_weight.begin(), value_per_weight.end(),
            greater<RatioIndexPair>());
  // v_i / w_i sorted in decreasing order
#ifdef DEBUG
  for (auto &rip : value_per_weight) {
    cout << setprecision(4) << rip;
  }
#endif
  // write your code here
  for (auto &rip : value_per_weight) {
    if (capacity == 0) {
      return value; // fix
    }
    double min_weight = min(capacity, weights[rip.get_index()]);
    value += min_weight * (rip.get_ratio());
    weights[rip.get_index()] -= min_weight;
    capacity -= min_weight;
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
