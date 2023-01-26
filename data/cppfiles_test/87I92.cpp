#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
long long n, m, p;
long long a[maxn];
long long b[maxn];
long long c[maxn];
long long cmp(long long x, long long y) { return a[b[x]] < a[b[y]]; }
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n * m; i++) {
    cin >> a[i];
    b[i] = i;
    c[i] = 0;
  }
  sort(b + 1, b + n * m + 1, cmp);
  long long cnt = 0;
  for (int i = 1; i <= n * m; i++) {
    long long y = (b[i] - 1) % m + 1;
    long long x = (b[i] - y);
    for (int j = x + 1; j <= b[i]; j++) {
      if (c[j]) cnt++;
    }
    c[b[i]] = 1;
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
