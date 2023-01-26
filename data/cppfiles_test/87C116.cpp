#include <bits/stdc++.h>
using namespace std;
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v) is >> x;
  return is;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i) os << ' ' << v[i];
  }
  return os;
}
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n + 1);
  for (long long i = 1; i <= n; i++) cin >> a[i];
  long long add = 0, ans = 0;
  for (long long i = 1; i <= n; i++) {
    if (i + add < a[i]) {
      ans += a[i] - (i + add);
      add += a[i] - (i + add);
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
