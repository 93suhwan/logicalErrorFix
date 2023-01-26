#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  while (test--) {
    long long x, m, pos;
    cin >> x >> m;
    if (x % 2 == 0) {
      if (m % 2 == 0) {
        if (m % 4 == 0) {
          pos = x;
        } else
          pos = x + 1;
      } else {
        if ((m + 1) % 4 == 0) {
          pos = x + m + 1;
        } else if ((m - 1) % 4 == 0) {
          pos = x - m;
        }
      }
    } else {
      if (m % 2 != 0) {
        if ((m + 1) % 4 == 0) {
          pos = x - m - 1;
        } else if ((m - 1) % 4 == 0) {
          pos = x + m;
        }
      } else {
        if (m % 4 == 0) {
          pos = x;
        } else {
          pos = x - 1;
        }
      }
    }
    cout << pos << "\n";
  }
  return 0;
}
