#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n <= 6) {
      cout << 15 << endl;
      continue;
    } else if (n <= 8) {
      cout << 20 << endl;
      continue;
    } else if (n <= 10) {
      cout << 25 << endl;
      continue;
    }
    long long small = 0;
    long long medium = 0;
    long long large = 0;
    large = n / 10;
    if (large * 10 != n) {
      large++;
    }
    long long empty = (large * 10) - n;
    if (empty <= 1) {
      large = large;
    } else if (empty <= 3) {
      large--;
      medium++;
    } else if (empty <= 5) {
      large--;
      small++;
    } else if (empty <= 7) {
      large = large - 2;
      medium++;
      small++;
    } else {
      large = large - 2;
      small += 2;
    }
    cout << 15 * small + 20 * medium + 25 * large << endl;
  }
}
