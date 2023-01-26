#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 200007;
int le[N], ri[N];
int id[N], fn[N];
int a[N], nxt[N], clc;
int tag[N], dup[N];
string s;
void dfs(int x) {
  if (x == 0) return;
  dfs(le[x]);
  id[fn[x] = ++clc] = x;
  a[clc] = s[x] - 'a' + 1;
  dfs(ri[x]);
}
int gao(int x, int r) {
  if (x == 0) return 0;
  if (r <= 0) return 0;
  int use = gao(le[x], r - 1);
  if (use) {
    dup[x] = 1;
    r -= use + 1;
    return gao(ri[x], r) + use + 1;
  } else {
    if (tag[x]) {
      dup[x] = 1;
      return gao(ri[x], r - 1) + 1;
    } else {
      dup[x] = 0;
      return 0;
    }
  }
}
void solve() {
  int n, k;
  cin >> n >> k;
  cin >> s;
  s = ' ' + s;
  for (int i = 1; i <= n; i++) {
    cin >> le[i] >> ri[i];
  }
  clc = 0;
  dfs(1);
  a[clc + 1] = 0;
  for (int i = clc; i >= 1; i--) {
    if (a[i] != a[i + 1]) {
      nxt[i] = a[i + 1];
    } else {
      nxt[i] = nxt[i + 1];
    }
    assert(nxt[i] != a[i]);
    if (nxt[i] > a[i]) {
      tag[id[i]] = 1;
    } else {
      tag[id[i]] = 0;
    }
  }
  for (int i = 1; i <= n; i++) dup[i] = 0;
  gao(1, k);
  for (int i = 1; i <= n; i++) {
    char ch = s[id[i]];
    cout << ch;
    if (dup[id[i]]) cout << ch;
  }
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  while (t--) solve();
}
