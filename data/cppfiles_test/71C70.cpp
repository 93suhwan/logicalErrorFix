#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<long long, long long>;
using ti = tuple<long long, long long, long long>;
using vi = vector<long long>;
using ull = unsigned long long;
const long long MOD = 1e9 + 7;
const ll INF = 2e15;
const long long ALP = 26;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
vector<long long> db[10];
long long c[2];
long long num[11];
void func(long long dep, long long n) {
  if (dep == n) {
    long long base = 1, ans = 0;
    for (long long i = (0); i < (n); ++i) {
      ans += base * num[i];
      base *= 10;
    }
    db[n].push_back(ans);
    return;
  }
  for (long long i = (0); i < (2); ++i) {
    num[n - 1 - dep] = c[i];
    func(dep + 1, n);
  }
}
void init() {
  for (long long n = (1); n < (10); ++n) {
    for (long long i = (0); i < (10); ++i) {
      for (long long j = (i + 1); j < (10); ++j) {
        c[0] = i, c[1] = j;
        func(0, n);
      }
    }
  }
  for (long long n = (1); n < (10); ++n) {
    sort((db[n]).begin(), (db[n]).end());
    db[n].erase(unique((db[n]).begin(), (db[n]).end()), db[n].end());
  }
}
void solve() {
  long long n, k;
  cin >> n >> k;
  if (n == 1e9) {
    if (k == 1)
      cout << "1111111111\n";
    else
      cout << n << '\n';
    return;
  }
  deque<long long> a;
  long long tmp = n;
  while (tmp) {
    a.push_front(tmp % 10);
    tmp /= 10;
  }
  long long m = (long long)(a).size();
  if (k == 1) {
    long long base = 1;
    long long ans = 0;
    for (long long i = (0); i < (m); ++i) {
      ans += a[0] * base;
      base *= 10;
    }
    if (ans >= n) {
      cout << ans << '\n';
      return;
    }
    base = 1, ans = 0;
    for (long long i = (0); i < (m); ++i) {
      ans += (a[0] + 1) * base;
      base *= 10;
    }
    cout << ans << '\n';
    return;
  }
  long long idx =
      lower_bound((db[m]).begin(), (db[m]).end(), n) - db[m].begin();
  for (long long i = -2; i <= 2; ++i) {
    long long ni = idx + i;
    if (ni < 0) continue;
    if (db[m][ni] >= n) {
      cout << db[m][ni] << '\n';
      return;
    }
  }
}
signed main() {
  init();
  long long tc;
  cin >> tc;
  for (long long i = 1; i <= tc; ++i) solve();
  return 0;
}
