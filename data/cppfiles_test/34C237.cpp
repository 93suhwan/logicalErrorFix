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
  vector<pair<long long, long long> > arr(n);
  long long ans = -1e15;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = i + 1;
  }
  reverse(arr.begin(), arr.end());
  for (int i = 0; i < min(n, 1000LL); i++) {
    for (int j = i + 1; j < min(n, 1000LL); j++) {
      ans = max(ans, arr[i].second * arr[j].second -
                         k * (arr[i].first | arr[j].first));
    }
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
