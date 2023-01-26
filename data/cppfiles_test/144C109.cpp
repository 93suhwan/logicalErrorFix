#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    if ((n / m) * m == n) {
      for (int i = 0; k > i; ++i) {
        int cur = 1;
        for (int j = 0; m > j; ++j) {
          cout << n / m << " ";
          for (int d = 0; n / m > d; ++d) {
            cout << cur << " ";
            ++cur;
          }
          cout << endl;
        }
        cout << endl;
      }
      continue;
    }
    int c = (n % m) * (n / m + 1);
    int curstart = 0;
    for (int i = 0; k > i; ++i) {
      for (int j = 0; n % m > j; ++j) {
        cout << (n / m + 1) << " ";
        for (int l = 0; (n / m + 1) > l; ++l) {
          cout << curstart + 1 << " ";
          curstart++;
          curstart %= n;
        }
        cout << endl;
      }
      for (int j = n % m; m > j; ++j) {
        cout << (n / m) << " ";
        for (int l = 0; (n / m) > l; ++l) {
          cout << curstart + 1 << " ";
          curstart++;
          curstart %= n;
        }
        cout << endl;
      }
      curstart += c;
      curstart %= n;
      cout << endl;
    }
    cout << endl;
  }
}
