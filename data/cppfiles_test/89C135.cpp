#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
const int M = 1e5 + 7;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;
int t;
int n, m;
int a[M];
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int sign = 1;
    for (int i = 1; i <= n; i++) {
      int flag = 0;
      for (int j = 2; j <= i + 1; j++) {
        if (a[i] % j != 0) {
          flag = 1;
          break;
        }
      }
      if (flag == 0) sign = 0;
    }
    if (!sign)
      cout << "NO" << '\n';
    else
      cout << "YES" << '\n';
  }
  return 0;
}
