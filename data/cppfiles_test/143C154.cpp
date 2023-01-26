#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10;
long long n, a[N], res[N], cnt[N];
vector<pair<long long, long long> > vc;
void solve() {
  cin >> n;
  vc.clear();
  for (long long i = 0; i <= n; i++) cnt[i] = 0, res[i] = 0;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  if (cnt[0] > 0) res[0] = cnt[0];
  if (cnt[0] > 1) vc.push_back({0, cnt[0] - 1});
  long long tot = 0, dist = 0;
  for (long long i = 1; i <= n; i++) {
    tot += cnt[i - 1];
    if (tot < i) {
      while (i <= n) {
        res[i] = -1;
        i++;
      }
      goto bk;
    }
    if (!cnt[i - 1]) {
      while (vc[vc.size() - 1].second == 0) vc.pop_back();
      --vc[vc.size() - 1].second;
      dist += i - vc[vc.size() - 1].first - 1;
    }
    res[i] = dist + cnt[i];
    if (cnt[i] > 1) vc.push_back({i, cnt[i] - 1});
  }
bk:;
  for (long long i = 0; i <= n; i++) cout << res[i] << ' ';
  cout << '\n';
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long _;
  cin >> _;
  while (_--) solve();
  return 0;
}
