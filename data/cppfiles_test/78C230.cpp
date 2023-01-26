#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, n, m;
  while (cin >> a) {
    for (int i = 0; i < a; i++) {
      cin >> n >> m;
      if (n > m / 2) {
        cout << m - n << endl;
      } else {
        cout << (m + 1) / 2 - 1 << endl;
      }
    }
  }
}
