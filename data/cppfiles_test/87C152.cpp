#include <bits/stdc++.h>
using namespace std;
const int N = 3e2 + 10, mod = 1e9 + 7;
int fen[N * N];
void add(int x) {
  for (; x < N * N; x += x & -x) {
    fen[x]++;
  }
}
int get(int x) {
  int ret = 0;
  for (; x; x -= x & -x) {
    ret += fen[x];
  }
  return ret;
}
void solve() {
  memset(fen, 0, sizeof(fen));
  int n, m;
  cin >> n >> m;
  vector<int> hlp;
  vector<pair<int, int> > v;
  int a[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      hlp.push_back(a[i][j]);
    }
  }
  sort(hlp.begin(), hlp.end());
  hlp.resize(unique(hlp.begin(), hlp.end()) - hlp.begin());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] = lower_bound(hlp.begin(), hlp.end(), a[i][j]) - hlp.begin() + 1;
      v.push_back({a[i][j], -(i * m + j + 1)});
    }
  }
  sort(v.begin(), v.end());
  long long ans = 0;
  for (pair<int, int> x : v) {
    int val = x.first, id = x.second;
    ans += get(-id);
    add(-id);
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  int cur = 1;
  while (t--) {
    solve();
  }
  return 0;
}
