#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma target optimize("avx2,bmi,bmi2,lzcnt,popcnt")
template <class T>
bool chmin(T &a, T b) {
  return b < a and (a = b, true);
}
template <class T>
bool chmax(T &a, T b) {
  return b > a and (a = b, true);
}
const int maxn = 2e5 + 5;
vector<int> vec;
vector<int> stk;
int ch[maxn][2];
bool add[maxn];
bool dub[maxn];
int n, m;
void dfs(int u) {
  if (!u) return;
  dfs(ch[u][0]);
  vec.emplace_back(u);
  ((void)0);
  dfs(ch[u][1]);
}
void dfs2(int u) {
  if (!u) return;
  stk.emplace_back(u);
  dfs2(ch[u][0]);
  if (m >= stk.size() and add[u] and !dub[u]) {
    for (int v : stk) dub[v] = 1;
    m -= stk.size();
    stk.clear();
  }
  if (add[u] or dub[u]) dfs2(ch[u][1]);
  if (!stk.empty() and stk.back() == u) stk.pop_back();
}
void solve() {
  string str, tmp;
  cin >> n >> m;
  cin >> str;
  str = "@" + str;
  for (int i = 1; i <= n; i++) cin >> ch[i][0] >> ch[i][1];
  dfs(1);
  for (int i = n - 2; ~i; i--)
    add[vec[i]] = (str[vec[i]] < str[vec[i + 1]]) or
                  (str[vec[i]] == str[vec[i + 1]] and add[vec[i + 1]]);
  dfs2(1);
  ((void)0);
  ((void)0);
  ((void)0);
  string ans;
  for (int v : vec) {
    ans.push_back(str[v]);
    if (dub[v]) ans.push_back(str[v]);
  }
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int T = 1;
  while (T--) solve();
  return 0;
}
