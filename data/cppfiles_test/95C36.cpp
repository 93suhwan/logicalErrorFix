#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
struct line {
  int leftmn, leftmx, rightmn, rightmx, ind;
};
bool cmp1(line a, line b) { return a.leftmx < b.leftmx; }
line l[500002];
int suf1[500002], pref[500002], suf2[500002];
char ch[500002];
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n + 2);
  vector<vector<int>> mn(n + 2);
  vector<vector<int>> mx(n + 2);
  vector<vector<int>> mn1(n + 2);
  vector<vector<int>> mx1(n + 2);
  for (int i = 0; i < n + 2; i++) {
    v[i].resize(m + 2);
    mn[i].resize(m + 2);
    mx[i].resize(m + 2);
    mn1[i].resize(m + 2);
    mx1[i].resize(m + 2);
  }
  for (int i = 1; i <= n; i++) {
    mn[i][0] = 1e9;
    for (int j = 1; j <= m; j++) {
      cin >> v[i][j];
      mn[i][j] = min(mn[i][j - 1], v[i][j]);
      mx[i][j] = max(mx[i][j - 1], v[i][j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    mn1[i][m + 1] = 1e9;
    for (int j = m; j >= 1; j--) {
      mn1[i][j] = min(mn1[i][j + 1], v[i][j]);
      mx1[i][j] = max(mx1[i][j + 1], v[i][j]);
    }
  }
  bool ok = 0;
  for (int j = 1; j < m && !ok; j++) {
    for (int i = 1; i <= n; i++) {
      l[i] = {mn[i][j], mx[i][j], mn1[i][j + 1], mx1[i][j + 1], i};
    }
    sort(l + 1, l + n + 1, cmp1);
    suf1[n + 1] = pref[0] = 1e9;
    for (int i = 1; i <= n; i++) pref[i] = min(pref[i - 1], l[i].rightmn);
    suf2[n + 1] = 0;
    for (int i = n; i >= 1; i--) {
      suf1[i] = min(suf1[i + 1], l[i].leftmn);
      suf2[i] = max(suf2[i + 1], l[i].rightmx);
    }
    int ind = 0;
    for (int i = 1; i < n; i++) {
      if (l[i].leftmx < suf1[i + 1] && suf2[i + 1] < pref[i]) {
        ind = i;
        ok = 1;
        break;
      }
    }
    if (ind == 0) continue;
    for (int i = 1; i <= n; i++) {
      if (i <= ind)
        ch[l[i].ind] = 'B';
      else
        ch[l[i].ind] = 'R';
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) cout << ch[i];
    cout << " " << j;
    cout << "\n";
    return;
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
