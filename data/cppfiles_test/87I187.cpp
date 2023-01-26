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
  vector<int> a(n);
  cin >> a;
  long long ans = 0;
  long long cur = 0;
  for (int i = 0; i < n; i++) {
    if (cur < a[i]) {
      ans += (a[i] - cur - 1);
      cur = a[i];
    }
    cur = max(cur, i + 1LL);
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
