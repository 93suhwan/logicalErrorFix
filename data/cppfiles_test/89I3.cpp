#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vec = vector<int>;
using veg = vector<pii>;
using ll = long long;
int read() {
  int x = 0;
  bool f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}
const int N = 2e5 + 10;
int n, res, fa[N], tl[N], ttl[N];
bool isl[N], isb[N];
vec G[N];
veg pot;
void dfs(int x, int p) {
  fa[x] = p;
  tl[x] = ttl[x] = 0;
  for (int y : G[x])
    if (y ^ p) {
      dfs(y, x);
      tl[x]++;
      ttl[x] += isl[y];
    }
  if (tl[x])
    isl[x] = false;
  else
    isl[x] = true;
  if (tl[x] && ttl[x] == tl[x])
    isb[x] = true;
  else
    isb[x] = false;
  res += isl[x];
}
void solve() {
  n = read();
  for (int i = (1); i <= (n); i++) vec().swap(G[i]);
  veg().swap(pot);
  res = 0;
  for (int i = (2); i <= (n); i++) {
    int x = read(), y = read();
    G[x].push_back(y);
    G[y].push_back(x);
  }
  dfs(1, 0);
  int lef = res;
  for (int i = 1; i <= n; i++)
    if (isb[i]) pot.push_back({ttl[i], i});
  for (auto x : pot) lef -= x.first;
  priority_queue<pii, vector<pii>, greater<pii> > q;
  for (auto x : pot) q.push(x);
  while (q.size()) {
    pii d = q.top();
    int id = d.second, sz = d.first;
    q.pop();
    if (lef == 0) {
      lef += sz;
      continue;
    }
    if (tl[fa[id]] == 1) {
      lef += sz - 1;
      tl[fa[id]]--;
      lef++;
      int z = fa[fa[id]];
      if (!z) continue;
      ttl[z]++;
      if (ttl[z] == tl[z]) q.push({ttl[z], z}), lef -= ttl[z];
    } else {
      lef += sz - 1;
      res--;
      tl[fa[id]]--;
    }
    assert(lef >= 0);
  }
  cout << res << endl;
}
int main() {
  for (int T = read(); T; T--) solve();
  return 0;
}
