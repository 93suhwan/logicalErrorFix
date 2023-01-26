#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int inf = 1e9;
const long long mod = 1e9 + 7;
const int N = 1e6 + 8;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    int t1 = 1;
    int t2 = n - 1;
    bool f = 0;
    if (t2 % 2 != 0) {
      cout << t2 / 2 << " " << t2 / 2 + 1 << " " << 1 << '\n';
      f = 1;
    } else {
      for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
          int v = n / i - 1, a1, a2;
          if (v % 2 == 0) {
            a1 = v / 2 - 1, a2 = v / 2 + 1;
          } else {
            a1 = v / 2, a2 = v - a1;
          }
          cout << a1 * i << " " << a2 * i << " " << i << '\n';
          f = 1;
          break;
        }
      }
    }
    if (f) continue;
    int a1 = 1;
    int a2 = (n - 1) / 2 - 1, a3 = (n - 1) / 2 + 1;
    cout << a2 << " " << a3 << " " << a1 << '\n';
  }
}
