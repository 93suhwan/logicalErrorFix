#include <bits/stdc++.h>
using namespace std;
long long inf = 1e18;
long long mod = 1e9 + 7;
void debug(vector<long long> &v) {
  for (auto i : v) cout << i << " ";
  cout << endl;
}
void debug(vector<vector<long long>> &v) {
  for (auto i : v) {
    for (auto j : i) cout << j << " ";
    cout << endl;
  }
  cout << endl;
}
void solve();
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long T = 1;
  cin >> T;
  while (T--) solve();
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> a(n * m);
  set<long long> s;
  for (long long i = 0; i < n * m; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }
  map<long long, long long> mp;
  long long cnt = 0;
  for (auto i : s) mp[i] = cnt++;
  vector<long long> b(n * m);
  for (long long i = 0; i < n * m; i++) ++b[mp[a[i]]];
  long long prev = 0;
  vector<vector<long long>> pos(n * m);
  for (long long i = 0; i < n * m; i++) {
    if (b[i]) {
      long long tmp = prev + b[i] - 1;
      pos[i] = {
          prev, min(prev + b[i], (prev / m + 1) * m) - 1, -1, -1, (tmp / m) * m,
          tmp};
      if ((tmp / m - prev / m) > 1)
        pos[i][2] = (prev / m + 1) * m, pos[i][3] = (tmp / m) * m - 1;
      prev += b[i];
    }
  }
  long long ans = 0;
  vector<long long> c(n * m);
  auto calc = [&](long long j) {
    long long i = (j / m) * m;
    long long res = 0;
    for (long long k = i; k < j; k++) res += c[k];
    c[j] = 1;
    return res;
  };
  for (long long i = 0; i < n * m; i++) {
    long long in = mp[a[i]];
    if (pos[in][1] >= pos[in][0]) {
      ans += calc(pos[in][1]);
      --pos[in][1];
    } else if (pos[in][3] != -1 && pos[in][3] >= pos[in][2]) {
      ans += calc(pos[in][3]);
      --pos[in][3];
    } else {
      ans += calc(pos[in][5]);
      --pos[in][5];
    }
  }
  cout << ans << endl;
}
