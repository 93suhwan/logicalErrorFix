#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int numbers[t];
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    numbers[i] = n;
  }
  for (int i = 0; i < t; i++) {
    int b1;
    int b2;
    if (numbers[i] >= 3) {
      if (numbers[i] % 3 == 0) {
        b1 = numbers[i] / 3;
        b2 = numbers[i] / 3;
      } else if (numbers[i] % 3 == 1) {
        b1 = (numbers[i] - 1) / 3 + 1;
        b2 = (numbers[i] - 1) / 3;
      } else {
        b1 = (numbers[i] - 2) / 3;
        b2 = (numbers[i] - 2) / 3 + 1;
      }
    } else if (numbers[i] == 0) {
      b1 = 0;
      b2 = 0;
    } else if (numbers[i] == 1) {
      b1 = 1;
      b2 = 0;
    } else {
      b1 = 0;
      b2 = 1;
    }
    cout << b1 << " " << b2 << "\n";
  }
}
