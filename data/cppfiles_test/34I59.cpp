#include <bits/stdc++.h>
using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 1e6 + 13;
const int K = 500;
const int A = 9000;
vector<int> wh[A];
int mn[A];
int mn1[A];
int ub[A][A];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    wh[a[i]].push_back(i);
  }
  for (int i = 0; i < A; i++) {
    int cur = 0;
    for (int j = 0; j < A; j++) {
      while (cur < wh[i].size() && wh[i][cur] <= j) cur++;
      ub[i][j] = cur;
    }
  }
  mn[0] = -1;
  for (int i = 1; i < A; i++) {
    mn[i] = n;
  }
  for (int x = 0; x < A; x++) {
    for (int y = 0; y < A; y++) mn1[y] = mn[y];
    for (int y = 0; y < A; y++) {
      int i = (mn[y] == -1 ? 0 : ub[x][mn[y]]);
      if (i < wh[x].size()) mn1[y ^ x] = min(mn[y ^ x], wh[x][i]);
    }
    for (int y = 0; y < A; y++) mn[y] = mn1[y];
  }
  int res = 0;
  for (int i = 0; i < A; i++) res += (mn[i] < n);
  cout << res << endl;
  for (int i = 0; i < A; i++) {
    if (mn[i] < n) cout << i << ' ';
  }
  cout << endl;
}
