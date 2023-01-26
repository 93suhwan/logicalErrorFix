#include <bits/stdc++.h>
using namespace std;
void read(int& x) {
  static char c;
  int f = 0;
  while (!isdigit(c = getchar()))
    if (c == '-') f = 1;
  x = c ^ 48;
  while (isdigit(c = getchar())) x = (x * 10) + (c ^ 48);
  if (f) x = -x;
}
void chkmax(int& x, int y) {
  if (y > x) x = y;
}
void chkmin(int& x, int y) {
  if (y < x) x = y;
}
void chkmax(long long& x, long long y) {
  if (y > x) x = y;
}
void chkmin(long long& x, long long y) {
  if (y < x) x = y;
}
const int N = 2e5 + 10;
int n, m, q;
vector<pair<int, char> > Edge[N];
int L, bel[N];
char S[N], str[N];
void Insert(int pos, int len) {
  for (int i = 1; i <= len; ++i) S[++L] = str[i], bel[L] = pos;
  S[++L] = 'z' + 1;
}
pair<int, int> charInter[27];
namespace SA {
int sa[N], rk[N], id[N], px[N], oldrk[N * 2], height[N], Buc[N];
bool cmp(int x, int y, int w) {
  return oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w];
}
void getSA() {
  int m = 300, p = 300;
  for (int i = 1; i <= L; ++i) ++Buc[rk[i] = S[i] - 'a' + 1];
  for (int i = 1; i <= m; ++i) Buc[i] += Buc[i - 1];
  for (int i = 1; i <= 26; ++i)
    charInter[i] = make_pair(Buc[i - 1] + 1, Buc[i]);
  for (int i = L; i; --i) sa[Buc[rk[i]]--] = i;
  for (int w = 1; w < L; w <<= 1) {
    for (int i = 1; i <= m; ++i) Buc[i] = 0;
    m = p, p = 0;
    for (int i = L; i > L - w; --i) id[++p] = i;
    for (int i = 1; i <= L; ++i)
      if (sa[i] > w) id[++p] = sa[i] - w;
    for (int i = 1; i <= L; ++i) ++Buc[px[i] = rk[id[i]]];
    for (int i = 1; i <= m; ++i) Buc[i] += Buc[i - 1];
    for (int i = L; i; --i) sa[Buc[px[i]]--] = id[i];
    memcpy(oldrk, rk, sizeof rk), p = 0;
    for (int i = 1; i <= L; ++i) rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
    if (p == L) {
      for (int i = 1; i <= L; ++i) sa[rk[i]] = i;
      break;
    }
  }
}
bool comp(int pos, int mid, int w) {
  if (sa[mid] + w > L) return false;
  return pos <= rk[sa[mid] + w];
}
pair<int, int> Merge(pair<int, int> L, pair<int, int> R, int w) {
  int _l = L.first, _r = L.second;
  int l, r, mid;
  l = _l, r = _r;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (comp(R.first, mid, w))
      r = mid - 1;
    else
      _l = mid, l = mid + 1;
  }
  if (!comp(R.first, _l, w)) ++_l;
  l = _l, r = _r;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (comp(R.second + 1, mid, w))
      r = mid - 1;
    else
      _r = mid, l = mid + 1;
  }
  return make_pair(_l, _r);
}
}  // namespace SA
namespace Multi {
pair<int, int> udat[N][20], ddat[N][20];
int fat[N][20], dep[N];
void dfs(int now, int fa, int c) {
  dep[now] = dep[fa] + 1;
  if (now != 1) udat[now][0] = ddat[now][0] = charInter[c];
  fat[now][0] = fa;
  for (int i = 1; (1 << i) < n; ++i) {
    fat[now][i] = fat[fat[now][i - 1]][i - 1];
    if (!fat[now][i]) break;
    udat[now][i] =
        SA::Merge(udat[now][i - 1], udat[fat[now][i - 1]][i - 1], (1 << i - 1));
    ddat[now][i] =
        SA::Merge(ddat[fat[now][i - 1]][i - 1], ddat[now][i - 1], (1 << i - 1));
  }
  for (auto e : Edge[now])
    if (e.first != fa) dfs(e.first, now, e.second);
}
int LCA(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 19; ~i; --i)
    if (dep[fat[u][i]] >= dep[v]) u = fat[u][i];
  if (u == v) return u;
  for (int i = 19; ~i; --i)
    if (fat[u][i] != fat[v][i]) u = fat[u][i], v = fat[v][i];
  return fat[u][0];
}
pair<int, int> getInter(int u, int v) {
  int lca = LCA(u, v), w = 0;
  pair<int, int> res = make_pair(1, L), R = make_pair(1, L);
  for (int i = 19; ~i; --i)
    if (dep[fat[u][i]] >= dep[lca])
      res = SA::Merge(res, udat[u][i], w), w |= (1 << i), u = fat[u][i];
  for (int i = 19; ~i; --i)
    if (dep[fat[v][i]] >= dep[lca])
      R = SA::Merge(ddat[v][i], R, (1 << i)), v = fat[v][i];
  return SA::Merge(res, R, w);
}
}  // namespace Multi
vector<int> _add[N];
vector<pair<pair<int, int>, int> > _ask[N];
int Ans[N];
int c[N * 10];
int lb(int x) { return x & -x; }
void Add(int pos) {
  for (; pos <= L; pos += lb(pos)) ++c[pos];
}
int Ask(int pos) {
  int res = 0;
  for (; pos; pos -= lb(pos)) res += c[pos];
  return res;
}
void Work() {
  read(n), read(m), read(q);
  for (int i = 1; i < n; ++i) {
    int u, v;
    char c;
    read(u), read(v), scanf("%c", &c), c -= 'a' - 1;
    Edge[u].emplace_back(v, c), Edge[v].emplace_back(u, c);
  }
  for (int i = 1; i <= m; ++i) scanf("%s", str + 1), Insert(i, strlen(str + 1));
  SA::getSA();
  for (int i = 1; i <= L; ++i)
    if (bel[SA::sa[i]]) _add[bel[SA::sa[i]]].push_back(i);
  Multi::dfs(1, 0, 0);
  for (int i = 1; i <= q; ++i) {
    int u, v, l, r;
    read(u), read(v), read(l), read(r);
    pair<int, int> _ = Multi::getInter(u, v);
    _ask[r].emplace_back(_, i);
    if (l > 1) _ask[l - 1].emplace_back(_, -i);
  }
  for (int i = 1; i <= m; ++i) {
    for (int p : _add[i]) Add(p);
    for (auto o : _ask[i]) {
      int res = Ask(o.first.second) - Ask(o.first.first - 1);
      if (o.second < 0)
        Ans[-o.second] -= res;
      else
        Ans[o.second] += res;
    }
  }
  for (int i = 1; i <= q; ++i) printf("%d\n", Ans[i]);
}
int main() { Work(); }
