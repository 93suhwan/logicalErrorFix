#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
long double PI = 4 * atan(1);
int n, g, h, isBd[200001], isLf[200001], cnt;
vector<int> v[200001];
void dfs(int i, int par) {
  if (v[i].size() == 1 && i != 1) {
    isLf[i] = true;
    return;
  }
  bool isL = true;
  for (int a : v[i]) {
    if (a != par) {
      dfs(a, i);
      if (isLf[a]) isL = false;
    }
  }
  if (isL)
    isLf[i] = true;
  else
    isBd[i] = true, cnt++;
}
void solve() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> g >> h;
    v[g].push_back(h);
    v[h].push_back(g);
  }
  dfs(1, -1);
  if (isBd[1]) cnt--;
  if (isBd[1]) {
    cout << n - 2 * cnt - 1 << "\n";
  } else {
    cout << n - 2 * cnt << "\n";
  }
}
void init() {
  cnt = 0;
  for (int i = 1; i < n + 1; i++)
    isBd[i] = false, isLf[i] = false, v[i].clear();
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
