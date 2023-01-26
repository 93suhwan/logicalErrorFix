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
void dbg_out() { cout << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cout << ' ' << H;
  dbg_out(T...);
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int sum = accumulate((a).begin(), (a).end(), 0ll);
    if ((sum * (n - 2)) % n) {
      cout << 0 << "\n";
      continue;
    }
    int req = sum - (sum * (n - 2)) / n;
    map<int, int> m;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans += m[req - a[i]];
      m[a[i]]++;
    }
    cout << ans << "\n";
  }
}
