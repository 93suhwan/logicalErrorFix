#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-4;
const int Mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 10;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  long long n;
  cin >> T;
  while (T--) {
    cin >> n;
    if (n < 6) {
      cout << 15 << "\n";
      continue;
    }
    long long x = n / 6;
    long long ans = x * 15;
    int res = n % 6;
    if (res == 1 || res == 2) {
      ans += 5;
    } else if (res == 3 || res == 4) {
      ans += 10;
    } else if (res == 5) {
      ans += 15;
    }
    cout << ans << "\n";
  }
  return 0;
}
