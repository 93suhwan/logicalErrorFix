#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n >> m;
  long long a[n], b[n];
  for (long long i = 0; i < n; i++) cin >> a[i] >> b[i];
  long long pres = 0;
  for (long long i = 0; i < n; i++) pres += a[i] - b[i];
  long long l = 0, r = 0;
  for (long long i = 0; i < n; i++) {
    long long ma = min(m, a[i]);
    l -= (ma - (m - ma));
    long long mb = min(m, b[i]);
    r += (mb - (m - mb));
  }
  long long final;
  if (pres + r <= 0) {
    final = pres + r;
  } else if (pres + l >= 0) {
    final = pres + l;
  } else {
    final = ((pres - n * (m)) % 2 == 0 ? 0 : 1);
  }
  long long req = final - pres;
  long long ansa[n], ansb[n];
  long long now = 0;
  for (long long i = 0; i < n; i++) {
    long long mb = min(m, b[i]), ri = (mb - (m - mb));
    ansa[i] = m - mb;
    ansb[i] = mb;
    now += ansb[i] - ansa[i];
  }
  for (long long i = 0; i < n; i++) {
    long long ma = min(m, a[i]), mb = min(m, b[i]), li = (ma - (m - ma)),
              ri = (mb - (m - mb));
    if (now < req) break;
    if (now - ri - li >= req) {
      ansa[i] = ma;
      ansb[i] = m - ma;
      now = now - ri - li;
    } else {
      ansb[i] = (req - now + ri + m) / 2;
      ansa[i] = (m - (req - now + ri)) / 2;
      now = now - ri + ansb[i] - ansa[i];
      break;
    }
  }
  cout << abs(final) << endl;
  for (long long i = 0; i < n; i++) cout << ansa[i] << ' ' << ansb[i] << endl;
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
