#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
const int MAX_N = 1e5 + 5;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long double EPS = 1e-9;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  vector<bool> p(1e6 + 1, 0);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    p[a[i]] = 1;
  }
  sort(a, a + n);
  vector<pair<long long, long long>> ans;
  for (long long i = 1; i < n; i++) {
    for (long long j = 0; j < i; j++) {
      if (p[a[i] % a[j]] == 0) ans.pb({a[i], a[j]});
      if (ans.size() >= (n / 2)) break;
    }
    if (ans.size() >= (n / 2)) break;
  }
  for (long long i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
