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
void dbg_out() { cerr << "\b\b]\n"; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << H << ", ";
  dbg_out(T...);
}
void solve() {
  int n;
  cin >> n;
  vector<array<int, 2>> A(n);
  set<array<int, 2>> s;
  for (int i = 0; i < n; ++i) {
    cin >> A[i][0];
    A[i][1] = i + 1;
    if (A[i][0]) s.insert(A[i]);
  }
  vector<array<int, 2>> ans;
  while ((int)s.size() > 1) {
    auto [a, b] = *s.begin();
    auto [c, d] = *prev(s.end());
    ans.push_back({b, d});
    s.erase({a, b});
    s.erase({c, d});
    a--;
    c--;
    if (a) s.insert({a, b});
    if (c) s.insert({c, d});
  }
  cout << (int)ans.size() << '\n';
  for (auto x : ans) {
    for (auto y : x) cout << y << ' ';
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
