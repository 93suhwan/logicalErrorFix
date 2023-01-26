#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5, inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
int a[maxn];
long long n;
int main() {
  int _;
  cin >> _;
  while (_--) {
    cin >> n;
    long long ans;
    if (n <= 6) {
      ans = 15;
    } else {
      ans = (n + 1) / 2 * 5;
    }
    cout << ans << '\n';
  }
  return 0;
}
