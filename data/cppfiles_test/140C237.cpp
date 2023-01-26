#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
const long long inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
long long n, m, k, a[N], b[N], c[N], y, ans, sum, l, r;
string s;
void init() {
  for (long long i = 1; i <= 100000; i++) {
    a[i] = i * i * i;
    b[i] = i * i;
  }
  for (long long i = 1; i <= 100000; i++) {
    if ((long long)sqrt(a[i]) * (long long)sqrt(a[i]) == a[i]) {
      c[y] = a[i];
      y++;
    }
  }
}
inline void run() {
  double n;
  cin >> n;
  long long sum = upper_bound(b + 1, b + 100000, n) - b;
  long long ans = upper_bound(a + 1, a + 100000, n) - a;
  long long p = upper_bound(c + 1, c + y, n) - c;
  p--;
  cout << sum + ans - p - 3 << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  long long T;
  init();
  for (cin >> T; T > 0; T--) run();
  return 0;
}
