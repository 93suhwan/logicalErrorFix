#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long k, last = 0, first = 0, row = 0, col = 0;
    cin >> k;
    if (k == 2) {
      cout << 1 << " " << 2 << endl;
    } else if (k == 3) {
      cout << 2 << " " << 2 << endl;
    } else {
      for (int i = 1;; i++) {
        if (i * i == k) {
          row = i;
          col = 1;
          break;
        } else {
          if (i * i > k) {
            last = i;
            first = i - 1;
            break;
          }
        }
      }
      if (first != 0 && last != 0) {
        if (k >= first * first + last) {
          row = last;
        } else {
          row = (k % first);
        }
        if (k <= first * first + last) {
          col = last;
        } else {
          col = last - (k % last) + 1;
        }
      }
      cout << row << " " << col << endl;
    }
  }
  return 0;
}
