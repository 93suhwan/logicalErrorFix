#include <bits/stdc++.h>
using namespace std;
int t, n, a[200000];
vector<int> mvs;
void subar(int lo, int hi) {
  for (int i = lo; i < hi; i += 2) {
    mvs.push_back(i);
  }
  for (int i = hi - 4; i >= lo; i -= 2) {
    mvs.push_back(i);
  }
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    int xr = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      xr ^= a[i];
    }
    if (xr == 1) {
      cout << "NO" << endl;
      continue;
    }
    if (n % 2 == 1) {
      cout << "YES" << endl;
      subar(0, n - 1);
      cout << mvs.size() << endl;
      for (int m : mvs) {
        cout << m + 1 << " ";
      }
      cout << endl;
    } else {
      int xr = a[0];
      for (int i = 0; i < n; i += 2) {
        if (xr == 0) {
          subar(0, i);
          subar(i + 1, n - 1);
          break;
        }
        if (i < n - 2) {
          xr ^= (a[i + 1] ^ a[i + 2]);
        }
      }
      if (mvs.empty()) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
        for (int m : mvs) {
          cout << m + 1 << " ";
        }
        cout << endl;
      }
    }
    mvs.clear();
  }
}
