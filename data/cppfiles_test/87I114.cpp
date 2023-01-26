#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
long long n, m, p;
long long a[maxn];
long long b[maxn];
long long c[maxn];
long long d[maxn];
long long cmp(long long x, long long y) {
  if (a[x] <= a[y])
    return 1;
  else
    return 0;
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n * m; i++) {
    cin >> a[i];
    b[i] = i;
    c[i] = 0;
  }
  sort(b + 1, b + n * m + 1, cmp);
  for (int i = 1; i <= n * m; i++) {
    d[b[i]] = i;
  }
  long long cnt = 0;
  for (int i = 1; i <= n * m; i++) {
    long long y = (d[i] - 1) % m + 1;
    long long x = (d[i] - y);
    for (int j = x + 1; j <= b[i]; j++) {
      if (c[j]) cnt++;
    }
    c[d[i]] = 1;
  }
  cout << cnt << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
