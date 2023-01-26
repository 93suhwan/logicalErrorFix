#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
const int inf = 1e4;
vector<vector<int>> nxt;
void init(string& p, vi& f) {
  nxt.resize(f.size() + 1, vi(2));
  int k = 0;
  for (int i = 1; i < p.size(); ++i) {
    while (k && p[i] != p[k]) k = f[k];
    if (p[i] == p[k]) k++;
    f[i + 1] = k;
  }
  for (int i = 0; i < p.size(); i++)
    for (int j = 0; j < 2; j++)
      nxt[i][j] = p[i] - '0' == j ? i + 1 : bool(i) * nxt[f[i]][j];
  return;
}
string a, b;
int dp[500][500][500];
int n, m;
vi B;
int f(int k, int i, int j) {
  if (k < 0) return inf;
  if (j >= m) return f(k - 1, i, B[j]);
  if (i >= n) return (k == 0 ? 0 : inf);
  if (dp[k][i][j] > -1) return dp[k][i][j];
  int mx = inf;
  mx = min(mx, f(k, i + 1, nxt[j][a[i] == '1']));
  char c = a[i] ^ 1;
  mx = min(mx, 1 + f(k, i + 1, nxt[j][c == '1']));
  return dp[k][i][j] = mx;
}
int main() {
  memset(dp, -1, sizeof dp);
  cin >> n >> m;
  cin >> a >> b;
  B.resize(b.size() + 1);
  init(b, B);
  for (int i = 0; i < n - m + 2; ++i) {
    int rx = f(i, 0, 0);
    if (rx >= inf)
      cout << "-1 ";
    else
      cout << rx << ' ';
  }
  return 0;
}
