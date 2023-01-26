#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma target optimize("avx2,bmi,bmi2,lzcnt,popcnt")
void _col(int i) {
  static string _[3] = {"\e[0m", "\e[1;33m", "\e[1;32m"};
  cerr << _[i];
}
void dbg() { cerr << '\n'; }
template <class T, class... U>
void dbg(T a, U... b) {
  cerr << a << ' ', dbg(b...);
}
template <class T>
void org(T l, T r) {
  while (l != r) cerr << *l << " \n"[++l == r];
}
template <class T>
bool chmin(T &a, T b) {
  return b < a and (a = b, true);
}
template <class T>
bool chmax(T &a, T b) {
  return b > a and (a = b, true);
}
const int maxn = 2e5 + 5;
int ch[maxn][2];
int tag[maxn];
char bb[maxn][2];
string str;
void dfs(int u) {
  bb[u][0] = bb[u][1] = str[u];
  if (int c = ch[u][0]; c) {
    dfs(c);
    bb[u][0] = bb[c][0];
    if (tag[c])
      tag[u] = tag[c];
    else if (bb[c][1] < str[u])
      tag[u] = 1;
    else if (bb[c][1] > str[u])
      tag[u] = -1;
  }
  if (int c = ch[u][1]; c) {
    dfs(c);
    bb[u][1] = bb[c][1];
    if (!tag[u]) {
      if (str[u] < bb[c][0])
        tag[u] = 1;
      else if (str[u] > bb[c][0])
        tag[u] = -1;
      else if (tag[c])
        tag[u] = tag[c];
    }
  }
}
string ans;
int n, m;
void dfs2(int u) {
  if (!u) return;
  bool add = false;
  if (m) {
    if (int rs = ch[u][1]; !rs or str[u] < bb[rs][0])
      add = true;
    else if (str[u] == bb[rs][0] and tag[rs] == 1)
      add = true;
    if (add) m--;
  }
  dfs2(ch[u][0]);
  ans.push_back(str[u]);
  if (add) ans.push_back(str[u]);
  dfs2(ch[u][1]);
}
void solve() {
  cin >> n >> m;
  cin >> str;
  for (int i = 1; i <= n; i++) cin >> ch[i][0] >> ch[i][1];
  dfs(1);
  dfs2(1);
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
