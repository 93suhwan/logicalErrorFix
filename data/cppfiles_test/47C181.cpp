#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
vector<int> vt[2];
void Solve() {
  int n, k;
  cin >> n >> k;
  for (int j = 0; j < 2; j++) vt[j].clear();
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a > 0)
      vt[0].push_back(a);
    else
      vt[1].push_back(-a);
  }
  long long ans = 0;
  int mx = 0;
  for (int j = 0; j < 2; j++) {
    sort(vt[j].begin(), vt[j].end());
    n = vt[j].size();
    for (int i = n - 1; i >= 0; i -= k) ans += vt[j][max(0, i)];
    if (!vt[j].empty()) mx = max(mx, vt[j].back());
  }
  cout << ans * 2 - mx << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) Solve();
}
