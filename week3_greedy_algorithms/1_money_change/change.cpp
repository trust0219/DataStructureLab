#include <iostream>

int get_change(int m) {
  // write your code here
  int ten_dollar = 0, one_dollar = 0, ten_cent = 0, five_cent = 0;
  while (m >= 1000) {
    m -= 1000;
    ten_dollar++;
  }
  while (m >= 100) {
    m -= 100;
    one_dollar++;
  }
  while (m >= 10) {
    m -= 10;
    ten_cent++;
  }
  while (m >= 5) {
    m -= 5;
    five_cent++;
  }

  return ten_dollar * 100 + one_dollar * 10 + ten_cent + five_cent + m;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
