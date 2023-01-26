#include <bits/stdc++.h>
using namespace std;
long long inf = 1e18;
void solve();
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long T = 1;
  while (T--) solve();
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
long long n, m;
void add(long long &a, long long b) {
  a += b;
  a %= m;
}
void solve() {
  cin >> n >> m;
  vector<long long> suf(n + 1, 0);
  suf[n] = 1LL;
  for (long long i = n - 1; i > 0; i--) {
    long long tmp = 0;
    for (long long j = 2; i * j <= n; j++)
      add(tmp, suf[i * j] - (i * j + j <= n ? suf[i * j + j] : 0LL));
    add(suf[i], tmp + 2LL * suf[i + 1]);
  }
  cout << ((suf[1] - suf[2]) % m + m) % m << endl;
}
