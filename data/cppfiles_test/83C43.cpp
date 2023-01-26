#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
using namespace std;
const long long BIG_INF = 1e18;
const int N = 1e6 + 7;
const int T = 1 << 20;
template <class T, class G>
ostream &operator<<(ostream &os, const pair<T, G> &para) {
  os << para.first << ' ' << para.second;
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  for (const T &el : vec) os << el << ' ';
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &vec) {
  for (const T &el : vec) os << el << ' ';
  return os;
}
template <class T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (T &el : vec) is >> el;
  return is;
}
template <class T, class G>
istream &operator>>(istream &os, pair<T, G> &para) {
  os >> para.first >> para.second;
  return os;
}
template <class T>
void setmax(T &a, T b) {
  a = (a >= b ? a : b);
}
template <class T>
void setmin(T &a, T b) {
  a = (a <= b ? a : b);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
std::vector<int> zet(const std::string &w) {
  int n = (int)w.size();
  std::vector<int> p(n);
  int j = 0;
  for (int i = 1; i < n; ++i) {
    p[i] = std::max(std::min(p[j] + j - i, p[i - j]), 0);
    while (p[i] + i < n && w[p[i]] == w[p[i] + i]) p[j = i]++;
  }
  return p;
}
void solve() {
  int n;
  cin >> n;
  string second;
  cin >> second;
  vector<vector<int> > zzz;
  vector<int> dp(n);
  for (int i = 0; i < n; i++) {
    string temp = second.substr(i);
    zzz.push_back(zet(temp));
    int dl_suf = n - i;
    dp[i] = dl_suf;
    for (int j = 0; j < i; j++) {
      int dl_wsp = zzz[j][i - j];
      if (dl_wsp < dl_suf and second[j + dl_wsp] < second[i + dl_wsp])
        setmax(dp[i], dp[j] + dl_suf - dl_wsp);
    }
  }
  int ans = 0;
  for (auto &u : dp) setmax(ans, u);
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int test = 1;
  cin >> test;
  for (int i = 1; i <= test; i++) solve();
}
