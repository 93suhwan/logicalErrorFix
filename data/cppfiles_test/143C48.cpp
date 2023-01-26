#include <bits/stdc++.h>
using namespace std;
template <class T>
void minn(T& a, T b) {
  if (a > b) a = b;
}
template <class T>
void maxx(T& a, T b) {
  if (a < b) a = b;
}
void debug() { return; }
template <class H, class... T>
void debug(H a, T... b) {
  cerr << a;
  debug(b...);
}
void is() { return; }
template <class H, class... T>
void is(H& a, T&... b) {
  cin >> a;
  is(b...);
}
void os() { return; }
template <class H, class... T>
void os(H a, T... b) {
  cout << a;
  os(b...);
}
const long long mod = 1e9 + 7;
const long long N = 2e5 + 5;
long long n;
void solve() {
  is(n);
  multiset<long long> q;
  map<long long, long long> mp;
  vector<long long> dp(n + 1, -1);
  for (long long i = 0; i < n; i++) {
    long long x;
    is(x);
    mp[x]++;
    q.insert(n - x);
  }
  long long l = 0;
  for (long long i = 1; i <= n; i++) {
    auto x = q.lower_bound(n - i + 1);
    if (x == q.end()) {
      break;
    }
    long long tmp = n - *x;
    l += abs(i - 1 - tmp);
    dp[i] = l + mp[i];
    q.erase(x);
  }
  dp[0] = mp[0];
  for (long long i = 0; i <= n; i++) {
    os(dp[i], " ");
  }
  os('\n');
}
signed main() {
  long long T = 1;
  is(T);
  while (T--) {
    solve();
  }
}
