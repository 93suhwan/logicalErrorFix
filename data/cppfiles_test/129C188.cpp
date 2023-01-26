#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
const double pi = acosl(-1);
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < (n); i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  set<long long> s;
  for (long long i = 1; i < (n + 1); i++) s.insert(i);
  vector<long long> vis(n);
  for (long long i = 0; i < (n); i++) {
    long long x = a[i];
    if (x <= n && s.find(x) != s.end()) {
      s.erase(x);
      vis[i] = 1;
    }
  }
  long long count = 0;
  for (long long i = 0; i < (n); i++) {
    if (vis[i]) continue;
    long long x = a[i] / 2;
    if (a[i] % 2 == 0) x--;
    if (*s.begin() <= x) {
      count++;
      s.erase(s.begin());
    }
  }
  if (s.size() == 0) {
    cout << count << '\n';
  } else {
    cout << -1 << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
