#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
long long T;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n + 5);
  long long mx = 0;
  for (int i = 1; i <= n; i++) cin >> a[i], mx = max(mx, a[i]);
  int x = n, ans = 0;
  while (x > 0) {
    if (a[x] == mx) break;
    ans++;
    int fp = 0;
    for (int i = x; i >= 1; i--) {
      if (a[i] > a[x]) {
        x = i;
        break;
      }
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  T = 1;
  cin >> T;
  for (int t = 1; t <= T; t++) solve();
  cout.flush();
  return 0;
}
