#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
long double PI = 4 * atan(1);
int n, g, h, ans;
bool isCh[200001], isRp[200001];
vector<int> v[200001];
void solve(int i, int par) {
  if (v[i].size() == 1 && i != 1) {
    isCh[i] = true;
    return;
  }
  int cnt = 0, ch = 0;
  for (int a : v[i]) {
    if (a != par) {
      solve(a, i);
      if (isCh[a]) {
        ch = 1;
        cnt++;
      } else if (isRp[a]) {
        cnt++;
      }
    }
  }
  if (i == 1) {
    if (cnt == v[1].size() && ch == 0) {
      ans++;
    }
    return;
  }
  if (cnt == v[i].size() - 1 && ch > 0) {
    isRp[i] = true;
    ans--;
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
  solve(1, -1);
  cout << max(ans, 1) << "\n";
}
void init() {
  ans = 0;
  for (int i = 1; i < n + 1; i++)
    v[i].clear(), isCh[i] = false, isRp[i] = false;
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
