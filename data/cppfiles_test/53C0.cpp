#include <bits/stdc++.h>
using namespace std;
const long long MAX = 900000;
const long long MOD = 1000000007;
const long long OO = 0x3f3f3f3f;
const double EPS = 1e-9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long sum(long long l, long long r) { return (l + r) * (r - l + 1) / 2; }
long long cnt[MAX];
void solve() {
  long long n;
  char c;
  string s;
  cin >> n >> c >> s;
  for (long long i = 0; i <= n; i++) cnt[i] = 0;
  for (long long d = 1; d <= n; d++)
    for (long long i = d; i <= n; i += d)
      if (s[i - 1] != c) cnt[d]++;
  if (count(s.begin(), s.end(), c) == n) {
    cout << "0\n";
    return;
  }
  vector<long long> ans;
  for (long long i = 1; i <= n and ans.empty(); i++)
    if (cnt[i] == 0) ans.push_back(i);
  if (ans.empty()) {
    ans.push_back(n);
    ans.push_back(n - 1);
  }
  cout << ans.size() << '\n';
  for (long long d : ans) cout << d << ' ';
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  for (long long it = 1; it <= t; ++it) {
    solve();
  }
  return 0;
}
