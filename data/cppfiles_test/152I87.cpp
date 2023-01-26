#include <bits/stdc++.h>
using namespace std;
const int MX = 1e6 + 4;
int p[MX], dp[MX][2][2];
pair<int, int> from[MX][2][2];
void upd(int i, int j, int k, int val, int pj, int pk) {
  if (val < dp[i][j][k]) {
    dp[i][j][k] = val;
    from[i][j][k] = make_pair(pj, pk);
  }
}
bool ans(int i, int j, int k) {
  if (dp[i][j][k] == INT_MAX) return false;
  int n = i + 1;
  int o[n];
  while (i >= 0) {
    o[i] = j ? p[i] : -p[i];
    pair<int, int> p = from[i][j][k];
    j = p.first;
    k = p.second;
    i--;
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) cout << o[i] << ' ';
  cout << '\n';
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++) dp[i][j][k] = INT_MAX;
    dp[0][0][0] = INT_MIN;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++)
          for (int w = 0; w < 2; w++) {
            if (dp[i - 1][j][k] == INT_MAX) continue;
            int pmax = p[i - 1];
            int pmyx = dp[i - 1][j][k];
            if (!j) pmax *= -1;
            if (k) swap(pmax, pmyx);
            int curr = p[i];
            if (!w) curr *= -1;
            if (curr < pmyx) continue;
            if (curr < pmax)
              upd(i, w, 1, pmax, j, k);
            else
              upd(i, w, 0, pmyx, j, k);
          }
    }
    bool ok;
    ok = ans(n - 1, 1, 0);
    if (!ok) ok = ans(n - 1, 1, 1);
    if (!ok) cout << "NO\n";
  }
}
