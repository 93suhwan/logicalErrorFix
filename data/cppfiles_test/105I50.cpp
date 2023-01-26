#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
const int M = 1000010;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
struct GOOD {
  int a, b, c;
  bool operator<(const GOOD t) const { return c < t.c; }
} a[N];
vector<GOOD> good[N];
int ans[N];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].a >> a[i].b >> a[i].c;
    int sum = a[i].a + a[i].b - a[i].c;
    int l = max(0, a[i].a - a[i].c);
    good[sum].push_back({i, l, a[i].a});
  }
  int res = 0;
  for (int i = 0; i <= (int)2e6; i++) {
    if (good[i].size() == 0) continue;
    sort(good[i].begin(), good[i].end());
    int ed = -1e9;
    for (int j = 0; j < good[i].size(); j++) {
      if (ed < good[i][j].b) {
        ed = good[i][j].c;
        ans[good[i][j].a] = ed;
        res++;
      } else
        ans[good[i][j].a] = ed;
    }
    good[i].clear();
  }
  cout << res << '\n';
  for (int i = 1; i <= n; i++) {
    cout << (a[i].a - ans[i]) << ' ' << a[i].c - (a[i].a - ans[i]) << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int T(1);
  cin >> T;
  for (int o = 1; o <= T; o++) {
    solve();
  }
  return 0;
}
