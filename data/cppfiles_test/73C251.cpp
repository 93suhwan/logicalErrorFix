#include <bits/stdc++.h>
using namespace std;
int main() {
  int q, n, k, start, lc;
  vector<int> a;
  cin >> q;
  while (q--) {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    k = 0;
    lc = 0;
    while (++k) {
      start = 2 - (k % 2);
      for (int i = start; i < n; i += 2) {
        if (a[i] > a[i + 1]) {
          swap(a[i], a[i + 1]);
          lc = k;
        }
      }
      if (lc == k - 2) {
        break;
      }
    }
    cout << lc << endl;
  }
}
