#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
pair<long long, long long> a[N];
long long res[N];
void solve() {
  long long n;
  cin >> n;
  memset(res, 0, sizeof res);
  for (long long i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a + 1, a + 1 + n);
  long long sum = 0;
  for (long long i = 2; i <= n; i++) sum += a[i].first * 2;
  res[a[1].second] = -sum / a[1].first;
  for (long long i = 1; i <= n; i++)
    if (!res[i])
      cout << 2 << " ";
    else
      cout << res[i] << " ";
  puts("");
}
signed main() {
  long long T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
