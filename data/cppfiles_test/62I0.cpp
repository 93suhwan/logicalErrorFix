#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void chmin(T &a, const T &val) {
  if (a > val) a = val;
}
template <class T>
inline void chmax(T &a, const T &val) {
  if (a < val) a = val;
}
template <class T>
long long sqr(T a) {
  return 1ll * a * a;
}
template <class T>
void compress(T &a) {
  sort(a.begin(), a.end());
  a.resize(unique(a.begin(), a.end()) - a.begin());
}
const double pi = acos(-1.00);
const double eps = 1e-6;
const int INF = 2e9;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
map<int, int> a, b;
vector<pair<int, int> > c;
void solve() {
  int n;
  cin >> n;
  a.clear();
  b.clear();
  c.clear();
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    a[x]++;
    b[y]++;
    c.push_back({x, y});
  }
  long long ans = 1ll * n * (n - 1) * (n - 2) / 6;
  for (auto [x, y] : c) {
    ans -= 1ll * (a[x] - 1) * (b[y] - 1);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
