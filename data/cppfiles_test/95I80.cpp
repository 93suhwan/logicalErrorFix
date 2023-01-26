#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int base = 131;
const double eps = 1e-6;
const double PI = acos(-1);
inline long long read() {
  long long x = 0;
  char ch;
  bool f = true;
  for (ch = getchar(); !isdigit(ch); ch = getchar())
    if (ch == '-') f ^= f;
  for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
  return f ? x : -x;
}
void ptr(int id, vector<pair<int, int>> ans, int n, int tt) {
  vector<bool> res(ans.size(), false);
  for (int i = n; i >= id; i--) res[ans[i].second] = true;
  cout << "YES\n";
  for (int i = 1; i < ans.size(); i++) cout << (res[i] ? 'R' : 'B');
  cout << " " << tt << "\n";
}
void solve() {
  int n = read(), m = read();
  vector<vector<int>> s(n + 1, vector<int>(m + 1)),
      Lmax(n + 1, vector<int>(m + 2)), Lmin(n + 1, vector<int>(m + 2, INF)),
      Rmax(n + 1, vector<int>(m + 2)), Rmin(n + 1, vector<int>(m + 2, INF));
  vector<char> ans(m + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) s[i][j] = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) Lmax[i][j] = max(Lmax[i][j - 1], s[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) Lmin[i][j] = min(Lmin[i][j - 1], s[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = m; j; j--) Rmax[i][j] = max(Rmax[i][j - 1], s[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = m; j; j--) Rmin[i][j] = min(Rmin[i][j - 1], s[i][j]);
  for (int i = 1; i < m; i++) {
    vector<pair<int, int>> L(n + 1);
    for (int j = 1; j <= n; j++) L[j] = {Lmax[j][i], j};
    sort(begin(L), end(L));
    vector<int> lmm(n + 2), lxx(n + 2, INF), rmm(n + 2), rxx(n + 2, INF);
    for (int j = n; j; j--) {
      int id = L[j].second;
      lxx[j] = min(lxx[j + 1], Lmin[id][i]);
      rmm[j] = max(rmm[j + 1], Rmax[id][i + 1]);
    }
    for (int j = 1; j <= n; j++) {
      int id = L[j].second;
      lmm[j] = max(lmm[j - 1], Lmax[id][i]);
      rxx[j] = min(rxx[j - 1], Rmin[id][i + 1]);
    }
    for (int j = 2; j <= n; j++) {
      int id = L[j].second;
      if (lmm[j - 1] < lxx[j] && rmm[j] < rxx[j - 1]) return ptr(j, L, n, i);
    }
  }
  puts("NO");
}
int main() {
  long long T = 1;
  T = read();
  for (int i = 1; i <= T; i++) solve();
}
