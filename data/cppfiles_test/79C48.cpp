#include <bits/stdc++.h>
using namespace std;
namespace hjt {
template <typename A, typename B>
std::ostream &operator<<(std::ostream &o, const std::pair<A, B> &x) {
  return o << '(' << x.first << ',' << x.second << ')';
}
}  // namespace hjt
using namespace hjt;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e5 + 7;
int n;
int a[N], b[N], dp[N];
pair<int, int> path[N];
set<int> st;
vector<int> ans;
void update(int &x, int y) {
  if (x == -1 || y < x) x = y;
}
inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  st.clear();
  for (int i = 0; i <= n + 1; ++i) {
    dp[i] = -1;
    st.insert(i);
  }
  queue<int> q;
  dp[n] = 0;
  q.push(n);
  while (q.size()) {
    int u = q.front();
    q.pop();
    while (true) {
      int x = *st.lower_bound(u - a[u]);
      if (x > u) break;
      st.erase(x);
      int v = x + b[x];
      if (dp[v] == -1 || dp[u] + 1 < dp[v]) {
        dp[v] = dp[u] + 1;
        path[v] = {u, x};
        q.push(v);
      }
    }
  }
  if (dp[0] == -1) {
    cout << "-1\n";
    return;
  }
  ans.clear();
  for (int i = 0; i != n; i = path[i].first) {
    ans.emplace_back(path[i].second);
  }
  reverse(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for (int &i : ans) cout << i << ' ';
  cout << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}
