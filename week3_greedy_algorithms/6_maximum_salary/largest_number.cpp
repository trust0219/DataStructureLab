#include <assert.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int firstDigit(int x) {
  int firstD = 0;
  while (true) {
    if (x < 10) {
      firstD = x;
      break;
    } else {
      x /= 10;
    }
  }
  assert(0 <= x && x <= 9);
  return firstD;
}

int exceptFirstDigit(int x) {
  if (x < 10) {
    return x;
  }
  int retval = 0;
  int expt = 0;
  while (true) {
    if (x < 10) {
      break;
    } else {
      if (expt == 0) {
        retval += (x % 10);
      } else {
        retval += (10 * expt * (x % 10));
      }
      x /= 10;
      expt++;
    }
  }
  return retval;
}

#ifdef ORIG
bool isGreaterOrEqual(int d, int md) {
  int d_fd = firstDigit(d), md_fd = firstDigit(md);
#ifdef DEBUG
  cout << "d: " << d << " md: " << md << endl;
  cout << "d_fd: " << d_fd << " md_fd: " << md_fd << endl;
#endif
  if (d_fd > md_fd) {
    return true;
  } else if (d_fd == md_fd) {
    if (d < 10 && md < 10) {
      return true;
    } else {
      return isGreaterOrEqual(exceptFirstDigit(d), exceptFirstDigit(md));
    }
    return false;
  } else {
    return false;
  }
}
#endif

int num_digits(int x) {
  int retval = 0;
  while (true) {
    if (x < 10) {
      retval++;
      break;
    } else {
      x /= 10;
      retval++;
    }
  }
  return retval;
}

int power_of_ten(int x, int expt) { return x * pow(10, expt); }

bool isGreaterOrEqual(int digit, int maxDigit) {
  //
  // 1.concatenate(digit, maxDigit)
  // 2.concatenate(maxDigit, digit)
  // if case1 > case2; then true
  // otherwise; false
  int case1 = power_of_ten(digit, num_digits(maxDigit)) + maxDigit;
  int case2 = power_of_ten(maxDigit, num_digits(digit)) + digit;
  return case1 > case2;
}

string largest_number(vector<string> a) {
  string result;
  while (a.size() > 0) {
    int maxDigit = 0;
    int currIndex = -1, removeIndex = 0;
    // going through numbers to find the suitable maximum digit
    for (string &num : a) {
      currIndex++;
      istringstream iss(num);
      int digit;
      iss >> digit;

      if (isGreaterOrEqual(digit, maxDigit)) {
        maxDigit = digit;
        removeIndex = currIndex;
      }
    }
    result += to_string(maxDigit);
    a.erase(a.begin() + removeIndex);
  }
  return result;
  // write your code here
  // std::stringstream ret;
  // for (size_t i = 0; i < a.size(); i++) {
  //   ret << a[i];
  // }
  // string result;
  // ret >> result;
  // return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
