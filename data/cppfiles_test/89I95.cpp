#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
long double PI = 4 * atan(1);
int n, g, h, ans;
bool isRp[200001];
vector<int> v[200001];
void dfs(int i, int par) {
  queue<int> q;
  bool lf = false;
  for (int a : v[i]) {
    if (a != par) {
      if (v[a].size() == 1) lf = true;
      q.push(a);
      dfs(a, i);
    }
  }
  bool rp = true;
  if (i == 1) {
    for (int a : v[i]) {
      if (!isRp[a]) rp = false;
    }
    if (rp) ans++;
    return;
  }
  if (q.empty()) rp = false;
  while (!q.empty()) {
    for (int a : v[q.front()]) {
      if (!isRp[a] && a != i) rp = false;
    }
    q.pop();
  }
  if (rp) {
    isRp[i] = true;
    if (lf) ans--;
  }
}
void solve() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> g >> h;
    v[g].push_back(h);
    v[h].push_back(g);
  }
  for (int i = 1; i < n + 1; i++)
    if (i != 1 && v[i].size() == 1) ans++;
  dfs(1, -1);
  cout << ans << "\n";
}
void init() {
  ans = 0;
  for (int i = 1; i < n + 1; i++) v[i].clear(), isRp[i] = false;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  for (int i = 0; i < test_cases; i++) {
    solve();
    init();
  }
  return 0;
}
