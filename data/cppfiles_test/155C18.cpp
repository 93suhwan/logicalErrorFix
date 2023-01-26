#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e5 + 5;
const long long MOD = 1e9 + 7;
const long long INF = 3e18 + 19763;
long long pw(long long a, long long b) {
  return b == 0 ? 1LL : (pw(a * a, b / 2) % MOD * (b % 2 == 0 ? 1LL : a));
}
long long p[MAXN], ans[MAXN];
vector<pair<long long, long long> > on, zr;
void solve() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  on.clear();
  zr.clear();
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> p[i];
  };
  string s;
  cin >> s;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '1')
      on.push_back({p[i], i});
    else
      zr.push_back({p[i], i});
  }
  sort(on.begin(), on.end());
  sort(zr.begin(), zr.end());
  for (long long i = 0; i < zr.size(); i++) ans[zr[i].second] = i + 1;
  for (long long i = 0; i < on.size(); i++)
    ans[on[i].second] = i + 1 + zr.size();
  for (long long i = 0; i < n; i++) {
    cout << ans[i] << " ";
  };
  cout << '\n';
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
