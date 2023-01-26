#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
char buffer[maxn], *S, *T;
inline char Get_Char() {
  if (S == T) {
    T = (S = buffer) + fread(buffer, 1, maxn, stdin);
    if (S == T) return EOF;
  }
  return *S++;
}
inline int read() {
  char c;
  int re = 0, f = 0;
  for (c = Get_Char(); c < '0' or c > '9'; c = Get_Char())
    if (c == '-') f = 1;
  for (; c >= '0' and c <= '9';)
    re = (re << 1) + (re << 3) + (c - '0'), c = Get_Char();
  if (f) return -re;
  return re;
}
inline void read(int& x) {
  char c;
  int re = 0, f = 0;
  for (c = Get_Char(); c < '0' or c > '9'; c = Get_Char())
    if (c == '-') f = 1;
  for (; c >= '0' and c <= '9';)
    re = (re << 1) + (re << 3) + (c - '0'), c = Get_Char();
  if (f)
    x = -re;
  else
    x = re;
}
inline void read(long long& x) {
  char c;
  long long re = 0, f = 0;
  for (c = Get_Char(); c < '0' or c > '9'; c = Get_Char())
    if (c == '-') f = 1;
  for (; c >= '0' and c <= '9';)
    re = (re << 1) + (re << 3) + (c - '0'), c = Get_Char();
  if (f)
    x = -re;
  else
    x = re;
}
vector<vector<int> > gird, pmx, pmn, smx, smn, tp1, tp2, all;
int n, m;
inline void solve() {
  cin >> n >> m;
  tp1.clear(), tp2.clear(), all.clear();
  tp1.resize(m + 1), tp2.resize(m + 1), all.resize(m + 1);
  gird.clear();
  gird.resize(n + 1);
  pmx.clear();
  pmx.resize(n + 1);
  smx.clear();
  smx.resize(n + 1);
  pmn.clear();
  pmn.resize(n + 1);
  smn.clear();
  smn.resize(n + 1);
  for (int i = 0; i < n; ++i) {
    gird[i].resize(m + 1);
    pmx[i].resize(m + 1);
    smx[i].resize(m + 1);
    pmn[i].resize(m + 1);
    smn[i].resize(m + 1);
    for (int j = 0; j < m; ++j) cin >> gird[i][j];
    pmn[i][0] = gird[i][0];
    pmx[i][0] = gird[i][0];
    for (int j = 1; j < m; ++j) pmx[i][j] = max(pmx[i][j - 1], gird[i][j]);
    for (int j = 1; j < m; ++j) pmn[i][j] = min(pmn[i][j - 1], gird[i][j]);
    smn[i][m - 1] = gird[i][m - 1];
    smx[i][m - 1] = gird[i][m - 1];
    for (int j = m - 2; j >= 0; --j) smx[i][j] = max(smx[i][j + 1], gird[i][j]);
    for (int j = m - 2; j >= 0; --j) smn[i][j] = min(smn[i][j + 1], gird[i][j]);
    for (int j = 0; j < m - 1; ++j) {
      if (pmx[i][j] < smn[i][j + 1]) tp1[j].push_back(i), all[j].push_back(i);
      if (pmn[i][j] > smx[i][j + 1]) tp2[j].push_back(i), all[j].push_back(i);
    }
  }
  for (int j = 0; j < m; ++j) {
    if (all[j].size() == n and tp1[j].size() > 0 and tp2[j].size() > 0) {
      cout << "YES\n";
      vector<int> col;
      col.resize(n + 1);
      for (int i = 0; i < tp1[j].size(); ++i) col[tp1[j][i]] = 0;
      for (int i = 0; i < tp2[j].size(); ++i) col[tp2[j][i]] = 1;
      for (int i = 0; i < n; ++i)
        if (col[i] == 0)
          cout << 'B';
        else
          cout << 'R';
      cout << ' ' << j + 1 << '\n';
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T;
  T = 1;
  cin >> T;
  for (; T--;) solve();
}
