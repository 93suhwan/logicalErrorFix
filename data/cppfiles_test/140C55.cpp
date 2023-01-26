#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    int a, b;
    for (int i = 1;; i++) {
      a = i;
      if (i * i > n) {
        break;
      }
    }
    for (int i = 1;; i++) {
      b = i;
      if (i * i * i > n) {
        break;
      }
    }
    a = a - 1;
    b = b - 1;
    int x, c;
    if (b >= 4) {
      for (int i = 1;; i++) {
        c = i;
        if (i * i > b) {
          break;
        }
      }
      c = c - 1;
      x = c - 1;
    }
    cout << a + b - x - 1 << endl;
    a = 0;
    b = 0;
    c = 0;
    x = 0;
  }
}
