#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, N = 330;
const int MOD = 1e9 + 7;
const double eps = 1e-6;
const double PI = acos(-1);
inline int lowbit(int x) { return x & (-x); }
long long tr[N];
int n, m;
void add(int u, int x) {
  for (int i = u; i <= m; i += lowbit(i)) tr[i] += x;
}
long long pre(int u) {
  long long res = 0;
  for (int i = u; i; i -= lowbit(i)) res += tr[i];
  return res;
}
inline void solve() {
  cin >> n >> m;
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    vector<pair<int, int> > v(m + 1);
    for (int j = 1; j <= m; j++) cin >> v[j].first, v[j].second = j;
    sort(v.begin() + 1, v.end(), [&](pair<int, int> A, pair<int, int> B) {
      if (A.first != B.first) return A.first < B.first;
      return A.second > B.second;
    });
    int cnt = 0;
    vector<int> a(m + 1);
    for (int j = 1; j <= m; j++) a[v[j].second] = ++cnt;
    for (int j = 1; j <= m; j++) {
      res += pre(a[j]);
      add(a[j], 1);
    }
    for (int j = 1; j <= m; j++) tr[j] = 0;
  }
  cout << res << '\n';
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  cout << fixed << setprecision(2);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
