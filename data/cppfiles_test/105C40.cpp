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
map<int, vector<GOOD>> good;
int ans[N];
void solve() {
  int n;
  cin >> n;
  good.clear();
  for (int i = 1; i <= n; i++) {
    cin >> a[i].a >> a[i].b >> a[i].c;
    int sum = a[i].a + a[i].b - a[i].c;
    int l = max(0, a[i].a - a[i].c),
        r = a[i].a - (a[i].c - min(a[i].b, a[i].c));
    good[sum].push_back({i, l, r});
  }
  int res = 0;
  for (auto &t : good) {
    sort(t.second.begin(), t.second.end());
    int ed = -1e9;
    for (int j = 0; j < t.second.size(); j++) {
      if (ed < t.second[j].b) {
        ed = t.second[j].c;
        ans[t.second[j].a] = ed;
        res++;
      } else
        ans[t.second[j].a] = ed;
    }
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
