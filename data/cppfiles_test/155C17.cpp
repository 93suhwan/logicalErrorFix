#include <bits/stdc++.h>
using namespace std;
template <typename T, typename V>
void ndarray(vector<T> &vec, const V &val, int len) {
  vec.assign(len, val);
}
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto &v : vec) is >> v;
  return is;
}
template <typename T>
istream &operator>>(istream &is, vector<pair<T, T>> &vec) {
  for (auto &v : vec) is >> v.first >> v.second;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  for (auto v : vec) os << v << ' ';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<pair<T, T>> &vec) {
  for (auto v : vec) os << v.first << " " << v.second << '\n';
  return os;
}
const int mod = (int)1e9 + 7;
const int inf = (int)1e9 + 7;
const long long infll = (long long)1e18 + 7;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n), res(n);
  string s;
  cin >> a >> s;
  vector<pair<int, int>> b, c;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      b.push_back({a[i], i});
    } else {
      c.push_back({a[i], i});
    }
  }
  sort((b).rbegin(), (b).rend());
  sort((c).begin(), (c).end());
  for (int i = n; i > n - b.size(); i--) {
    res[b[n - i].second] = i;
  }
  for (int i = 1; i <= c.size(); i++) {
    res[c[i - 1].second] = i;
  }
  cout << res << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int Tc;
  if (1) {
    cin >> Tc;
    while (Tc--) solve();
  } else {
    solve();
  }
}
