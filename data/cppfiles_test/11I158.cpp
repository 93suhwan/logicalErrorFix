#include <bits/stdc++.h>
using namespace std;
template <typename T>
T min_(T a, T b) {
  return a > b ? b : a;
}
template <typename T, typename... Ts>
T min_(T first, Ts... last) {
  return min_(first, min_(last...));
}
template <typename T, typename T1>
T amax(T& a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T& a, T1 b) {
  if (b < a) a = b;
  return a;
}
template <class T, class S>
std::ostream& operator<<(std::ostream& os, const std::pair<T, S>& t) {
  os << "(" << t.first << ", " << t.second << ")";
  return os;
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  out << "[";
  size_t last = v.size() - 1;
  for (size_t i = 0; i < v.size(); ++i) {
    out << v[i];
    if (i != last) out << ", ";
  }
  out << "]";
  return out;
}
bool comp(pair<int, int> a, pair<int, int> b) {
  if (a.second - a.first < b.second - b.first) return true;
  if (a.second - a.first > b.second - b.first) return false;
  if (a.first > b.first) return true;
  return false;
}
void solve() {
  int n;
  cin >> n;
  string s[n];
  for (auto i = 0; i < n; i++) cin >> s[i];
  vector<vector<pair<int, int>>> a(27, vector<pair<int, int>>(n, {0, 0}));
  for (auto i = 0; i < n; i++) {
    for (auto j = 0; j < 26; j++) {
      a[j][i].second = s[i].length();
    }
  }
  for (auto i = 0; i < n; i++) {
    for (auto j = 0; j < s[i].length(); j++) {
      a[s[i][j] - 'a'][i].first++;
    }
  }
  int ans = 0;
  for (auto i = 0; i < 26; i++) {
    sort(a[i].begin(), a[i].end(), comp);
    int tt = 0;
    int num = 0;
    for (auto j = 0; j < n; j++) {
      num += a[i][j].first;
      tt += a[i][j].second;
      if (num <= tt - num) break;
      ans = max(j + 1, ans);
    }
  }
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
