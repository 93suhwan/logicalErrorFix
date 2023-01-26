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
    bool f = 0;
    for (int i = 1; i <= n; i++) {
      if (i) {
        int a1 = i, v = n / i - 1;
        int a2, a3;
        a2 = v / 2, a3 = v - a2;
        if (a2 == a3 || a1 == a2 || a1 == a3)
          continue;
        else {
          cout << a2 * i << " " << a3 * i << " " << a1 << '\n';
          f = 1;
        }
      }
      if (f) break;
    }
    if (f)
      continue;
    else
      cout << "xoxo\n";
  }
}
