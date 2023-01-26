#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> a(n + 1);
  for (long long i = (1); i <= (n); i++) cin >> a[i];
  map<long long, long long> f, f2;
  for (long long i = (1); i <= (n); i++) {
    long long dt;
    if (a[i] == i)
      dt = 0;
    else if (a[i] > i)
      dt = n - a[i] + i;
    else
      dt = i - a[i];
    f[dt]++;
    f2[a[i] - i]++;
  }
  long long biswap = 0;
  for (auto [u, v] : f2) biswap += min(f2[-u], v);
  biswap /= 2;
  vector<long long> ans;
  for (long long k = (0); k <= (n - 1); k++) {
    long long wrong = n - f[k];
    if (wrong <= m + 1)
      ans.emplace_back(k);
    else if (wrong > n - 2 * m)
      continue;
    else {
      vector<pair<long long, long long>> v;
      for (long long i = (1); i <= (n); i++) {
        long long rsp = ((i <= n - k) ? (i + k) : (i - (n - k)));
        v.emplace_back(rsp, a[i]);
      }
      sort(begin(v), end(v));
      vector<long long> vg(n + 1);
      map<long long, long long> pos;
      for (auto [u, v2] : v) pos[v2] = u, vg[u] = v2;
      long long swaps = 0;
      for (long long i = (1); i <= (n); i++)
        if (pos[i] != i) {
          swaps++;
          swap(vg[pos[i]], vg[i]);
          pos[vg[pos[i]]] = pos[i];
          pos[i] = i;
        }
      if (swaps <= m) ans.emplace_back(k);
    }
  }
  cout << ans.size() << " ";
  for (auto e : ans) cout << e << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
