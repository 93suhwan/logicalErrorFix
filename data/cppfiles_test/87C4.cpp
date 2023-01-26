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
using ll = long long;
using ull = unsigned long long;
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 10;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int _;
  cin >> _;
  while (_--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n * m);
    for (int i = 0; i < n * m; i++) {
      int x;
      cin >> x;
      a[i].first = x;
      a[i].second = i;
    }
    sort(a.begin(), a.end());
    int ans = 0, nx = 1, ny = 1;
    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1));
    vector<vector<pair<int, int>>> who(n + 1, vector<pair<int, int>>(m + 1));
    for (auto x : a) {
      for (int i = int(1); i <= (int)(ny - 1); i++) {
        if (who[nx][i].first < x.first && who[nx][i].second < x.second) ans++;
      }
      who[nx][ny] = x;
      ny++;
      if (ny > m) {
        nx++;
        ny -= m;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
