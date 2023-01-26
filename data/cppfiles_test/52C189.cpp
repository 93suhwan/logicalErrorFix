#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
long long n, m;
long long cnt;
long long a[maxn], b[maxn], c[maxn];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    b[i] = b[i - 1] + a[i];
  }
  double ans = (double)(b[n - 1]) / (n - 1) + a[n];
  printf("%.6lf\n", ans);
}
int main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
