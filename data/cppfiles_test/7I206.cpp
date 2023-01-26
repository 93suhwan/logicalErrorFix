#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1);
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 5, M = 20;
int n, m, lg[N], f[N][M];
long long a[N], b[N];
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void init() {
  for (int i = 1; i <= n; ++i) f[i][0] = a[i];
  for (int i = 1; (1 << i) <= n; ++i)
    for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
      f[j][i] = gcd(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);
    }
}
long long query(int l, int r) {
  int k = lg[r - l + 1] - 1;
  return gcd(f[l][k], f[r - (1 << k) + 1][k]);
}
void show() {
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << ' ';
  }
  puts("");
}
void solve() {
  scanf("%d", &n);
  long long g = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &b[i]);
  }
  for (int i = 1; i < n; ++i) {
    a[i] = abs(b[i] - b[i + 1]);
  }
  --n;
  int res = 0;
  init();
  for (int i = 1; i <= n; ++i) {
    int l = i, r = n;
    while (l < r) {
      int mid = l + r + 1 >> 1;
      if (query(i, mid) > 1)
        l = mid;
      else
        r = mid - 1;
    }
    res = max(res, r - i + 1);
  }
  printf("%d\n", res + 1);
  if (n == 199999)
    cout << "query(1, n)"
         << " = " << query(1, n) << endl;
}
int main() {
  for (int i = 1; i < N; ++i) lg[i] = lg[i >> 1] + 1;
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
