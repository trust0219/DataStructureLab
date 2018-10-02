#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
int main() {
  srand(time(NULL));

  int num_segments = rand() % 10 + 1;
  cout << num_segments << endl;
  for (int i = 0; i < num_segments; i++) {
    int lower = rand() % 10;
    int upper = lower + (rand() % 10);
    cout << lower << " " << upper << endl;
    //
  }
}
