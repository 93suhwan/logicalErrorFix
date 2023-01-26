#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 123;
const int MAX = 1000000;
const int MOD = 1000000007;
const long double pi = 3.1415926536;
void func() {
  long long n;
  cin >> n;
  long long a[n][5];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> a[i][j];
    }
  }
  for (int j = 0; j < 5; j++) {
    for (int i = j + 1; i < 5; ++i) {
      int p = 0, q = 0, c = 0;
      for (int k = 0; k < n; k++) {
        if (a[k][j] == 1) ++p;
        if (a[k][i] == 1) ++q;
        if (a[k][j] == 1 && a[k][i] == 1) {
          ++c;
          --p;
          --q;
        }
      }
      if (p <= (n / 2) && q <= (n / 2) && p + q + c == n) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
  return;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    func();
  }
  return 0;
}
