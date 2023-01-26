#include <bits/stdc++.h>
using namespace std;
int l[200005], r[200005];
int ans_string_pos[200005];
int pre[200005];
int to_pos = 0;
int check_double[200005], check_fa[200005];
char s[200005];
int n, k;
void build(int pos) {
  if (pos) {
    build(l[pos]);
    ans_string_pos[pos] = ++to_pos;
    pre[to_pos] = pos;
    build(r[pos]);
  }
}
void pri(int pos) {
  if (pos) {
    pri(l[pos]);
    cout << s[pos];
    if (check_double[pos]) cout << s[pos];
    pri(r[pos]);
  }
}
int dfs(int pos, int dep) {
  if (l[pos] && dfs(l[pos], dep + 1)) check_double[pos] = 1;
  if (r[pos]) {
    if (check_double[pos] || (check_fa[ans_string_pos[pos]] && k >= dep)) {
      if (!check_double[pos]) {
        check_double[pos] = 1;
        k -= dep;
      }
      dfs(r[pos], 1);
    } else if (dfs(r[pos], 0x3f3f3f3f))
      check_double[pos] = 1;
  } else if (!check_double[pos] && check_fa[ans_string_pos[pos]] && k >= dep) {
    check_double[pos] = 1;
    k -= dep;
  }
  return check_double[pos];
}
void solve() {
  cin >> n >> k >> (s + 1);
  for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
  build(1);
  for (int i = n - 1; i > 0; i--) {
    if (s[pre[i]] != s[pre[i + 1]]) {
      check_fa[i] = (s[pre[i]] < s[pre[i + 1]]);
    } else {
      check_fa[i] = check_fa[i + 1];
    }
  }
  dfs(1, 1);
  pri(1);
}
int main() {
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
