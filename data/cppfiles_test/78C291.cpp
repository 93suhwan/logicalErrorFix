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
  long long a, b;
  cin >> a >> b;
  long long n = b / 2 + 1;
  cout << b % max(a, n) << "\n";
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
