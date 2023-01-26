#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int iinf = (int)1e9 + 10;
const long long linf = (long long)1e18 + 10;
int n, k;
string s;
const int maxn = 2e5 + 10;
int l[maxn], r[maxn], dup[maxn], ans[maxn];
void get_str(vector<int>& res, int v) {
  if (v == 0) return;
  get_str(res, l[v]);
  res.push_back(v);
  get_str(res, r[v]);
}
void dfs(int v, int left) {
  if (v == 0 || left > k) return;
  dfs(l[v], left + 1);
  if (ans[l[v]] || dup[v]) {
    if (!ans[l[v]] && dup[v]) {
      k -= left;
    }
    ans[v] = 1;
    dfs(r[v], 1);
  }
}
void out_ans(int v) {
  if (v == 0) return;
  out_ans(l[v]);
  cout << s[v];
  if (ans[v]) cout << s[v];
  out_ans(r[v]);
}
void solve() {
  cin >> n >> k;
  string t;
  cin >> t;
  s = " ";
  for (char c : t) s.push_back(c);
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }
  vector<int> res;
  get_str(res, 1);
  char prv = 0;
  for (int i = (int)res.size() - 1; i >= 0; i--) {
    if (prv != 0 && prv > s[res[i]]) {
      dup[res[i]] = 1;
    }
    if (i > 0 && s[res[i]] != s[res[i - 1]]) prv = s[res[i]];
  }
  dfs(1, 1);
  out_ans(1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
