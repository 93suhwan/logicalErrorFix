#include <bits/stdc++.h>
using namespace std;
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v);
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) {
  return cout << '(' << p.f << ',' << ' ' << p.s << ')';
}
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
  cout << '[';
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ',';
    cout << v[i];
  }
  return cout << ']' << endl;
}
const long long mod = 1000000007;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> arr(n);
  long long ans = -1e15;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n - 1; i++) {
    ans = max(ans, (i + 1) * (i + 2) - k * (arr[i] | arr[i + 1]));
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
