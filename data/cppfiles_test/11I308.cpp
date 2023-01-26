#include <bits/stdc++.h>
using namespace std;
const long long fk = 1000000007;
const long long fk1 = 998244353;
const long long inf = 1e18;
const long long N = 1005;
long long power(long long x, long long n, long long mod) {
  if (not x) return 0;
  if (not n) return 1;
  if (n % 2) return ((x % mod) * (power(x, n - 1, mod)) % mod) % mod;
  return power((x * x) % mod, n / 2, mod) % mod;
}
long long top(long long x, long long y) {
  if (x % y)
    return x / y + 1;
  else
    return x / y;
}
bool srt(pair<long long, string> &a, pair<long long, string> &b) {
  if (a.first > b.first) return true;
  if (a.first < b.first) return false;
  if (((long long)(a.second.size()) - a.first) <
      ((long long)(b.second.size()) - b.first))
    return true;
  return false;
}
void solve() {
  long long n;
  cin >> n;
  vector<string> s(n);
  for (auto &i : s) cin >> i;
  vector<pair<long long, string>> v[5];
  for (auto i : s) {
    vector<long long> cnt(5);
    for (auto j : i) cnt[j - 'a']++;
    for (long long j = 0; j < 5; j++) v[j].push_back({cnt[j], i});
  }
  long long ans = 0;
  for (long long i = 0; i < 5; i++) {
    sort(v[i].begin(), v[i].end(), srt);
    long long cnt = 0, cnt1 = 0, ans1 = 0;
    for (auto j : v[i]) {
      if ((cnt + j.first) > (cnt1 + (long long)(j.second.size()) - j.first)) {
        cnt += j.first;
        cnt1 += ((long long)(j.second.size()) - j.first);
        ans1++;
      }
    }
    ans = max(ans, ans1);
  }
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
