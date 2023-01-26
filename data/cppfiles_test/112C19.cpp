#include <bits/stdc++.h>
using namespace std;
const int N = 100050;
const int M = 4 * N;
char s[M];
int fir[N], len[N], tot;
int id[M], sa[M], nsa[M], cnt[M], td[M], tmp[M];
void buildSuffixArray() {
  int mx = 0;
  for (int i = 0; i < tot; i++) id[i] = s[i], sa[i] = i, mx = max(mx, id[i]);
  sort(sa, sa + tot, [&](int i, int j) { return id[i] < id[j]; });
  for (int j = 1;; j <<= 1) {
    for (int i = 0; i <= mx; ++i) cnt[i] = 0;
    for (int i = 0; i < tot; ++i) cnt[id[i]]++;
    for (int i = 0, sum = 0; i <= mx; i++) sum += cnt[i], cnt[i] = sum - cnt[i];
    for (int i = 0; i < tot; ++i) {
      int k = sa[i];
      if (k >= j) nsa[cnt[id[k - j]]++] = k - j;
      td[i] = i + j < tot ? id[i + j] : 0;
    }
    for (int i = tot - j; i < tot; ++i) nsa[cnt[id[i]]++] = i;
    for (int i = 0; i < tot; ++i) sa[i] = nsa[i];
    int c = 0;
    for (int i = 0; i < tot; ++i) {
      tmp[sa[i]] = c;
      c += i + 1 == tot || id[sa[i]] != id[sa[i + 1]] ||
           td[sa[i]] != td[sa[i + 1]];
      id[sa[i]] = tmp[sa[i]];
    }
    mx = c - 1;
    if (c == tot) break;
  }
}
int lcp[M];
void buildLCPArray() {
  for (int i = 0, k = 0; i < tot; i++) {
    if (id[i] + 1 != tot) {
      int j = sa[id[i] + 1];
      while (s[i + k] == s[j + k]) k++;
      lcp[id[i]] = k;
      if (k) k--;
    }
  }
}
const int L = 19;
int rmq[M][L], lgs[M];
void buildSparseTable() {
  for (int i = 2; i <= tot; i++) lgs[i] = lgs[i >> 1] + 1;
  for (int i = 0; i < tot; i++) rmq[i][0] = lcp[i];
  for (int j = 1; j < L; j++)
    for (int i = 0; i < tot - (1 << j) + 1; i++)
      rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << j - 1)][j - 1]);
}
int LCP(int i, int j) {
  i = id[i];
  j = id[j];
  if (i > j) swap(i, j);
  if (i == j) return tot - sa[i];
  j--;
  int k = lgs[j - i + 1];
  return min(rmq[i][k], rmq[j - (1 << k) + 1][k]);
}
int LCP(int st, const vector<pair<int, int>>& path, char& nxt) {
  int ans = 0;
  for (int i = 0; i < path.size(); i++) {
    int now = LCP(st + ans, path[i].first);
    if (now >= path[i].second) {
      ans += path[i].second;
    } else {
      ans += now;
      nxt = s[path[i].first + now];
      return ans;
    }
  }
  nxt = 0;
  return ans;
}
int cmp(int st, const vector<pair<int, int>>& path) {
  char nxt = 0;
  int pref = LCP(st, path, nxt);
  if (nxt == 0) return 0;
  return s[st + pref] < nxt ? -1 : 1;
}
struct BIT {
  int sum[M];
  BIT() {}
  void Add(int i, int f) {
    for (i++; i < M; i += i & -i) sum[i] += f;
  }
  int Get(int i) {
    int ans = 0;
    for (i++; i; i -= i & -i) ans += sum[i];
    return ans;
  }
} BT;
vector<pair<int, char>> E[N];
int sz[N], par[N], lid[N], head[N], tid, dep[N];
char ch[N];
void DFS(int u, int p) {
  par[u] = p;
  sz[u] = 1;
  dep[u] = dep[p] + 1;
  for (auto v : E[u])
    if (v.first != p) {
      DFS(v.first, u);
      sz[u] += sz[v.first];
      ch[v.first] = v.second;
    }
}
void HLD(int u, int p) {
  if (!head[u]) head[u] = u;
  lid[u] = ++tid;
  int HC = 0;
  for (auto v : E[u])
    if (v.first != p && sz[v.first] > sz[HC]) HC = v.first;
  if (HC) {
    head[HC] = head[u];
    HLD(HC, u);
  }
  for (auto v : E[u])
    if (v.first != p && v.first != HC) HLD(v.first, u);
}
int soh, n, m, q;
vector<pair<int, int>> getPath(int u, int v) {
  vector<pair<int, int>> fw, bw;
  while (head[u] != head[v]) {
    if (dep[head[u]] > dep[head[v]]) {
      fw.push_back({soh + (n - 1) + (n - lid[u]), dep[u] - dep[head[u]] + 1});
      u = par[head[u]];
    } else {
      bw.push_back({soh + lid[head[v]] - 2, dep[v] - dep[head[v]] + 1});
      v = par[head[v]];
    }
  }
  if (dep[u] > dep[v]) {
    fw.push_back({soh + (n - 1) + (n - lid[u]), dep[u] - dep[v]});
  } else if (dep[v] > dep[u]) {
    bw.push_back({soh + lid[u] - 1, dep[v] - dep[u]});
  }
  for (int i = bw.size(); i > 0; i--) fw.push_back(bw[i - 1]);
  return fw;
}
int qu[N], qv[N], ql[N], qr[N], ans[N], sal[N], sar[N];
vector<pair<int, int>> Qs[N];
int main() {
  scanf("%i %i %i", &n, &m, &q);
  for (int i = 1; i < n; i++) {
    int u, v;
    char c;
    scanf("%i %i %c", &u, &v, &c);
    E[u].push_back({v, c});
    E[v].push_back({u, c});
  }
  for (int i = 1; i <= m; i++) {
    scanf("%s", s + fir[i]);
    len[i] = strlen(s + fir[i]);
    s[fir[i] + len[i]] = 'a' - 1;
    fir[i + 1] = fir[i] + len[i] + 1;
  }
  DFS(1, 0);
  HLD(1, 0);
  soh = fir[m + 1];
  for (int i = 2; i <= n; i++) {
    s[soh + lid[i] - 2] = ch[i];
    s[soh + (n - 1) + (n - lid[i])] = ch[i];
  }
  s[soh + (n - 1) * 2] = 'a' - 2;
  tot = soh + (n - 1) * 2 + 1;
  buildSuffixArray();
  buildLCPArray();
  buildSparseTable();
  for (int i = 1; i <= q; i++) {
    scanf("%i %i %i %i", &qu[i], &qv[i], &ql[i], &qr[i]);
    Qs[ql[i] - 1].push_back({i, -1});
    Qs[qr[i]].push_back({i, 1});
    vector<pair<int, int>> path = getPath(qu[i], qv[i]);
    int top = tot - 1, bot = 0;
    while (top >= bot) {
      int mid = top + bot >> 1;
      if (cmp(sa[mid], path) < 0) {
        sal[i] = mid;
        bot = mid + 1;
      } else
        top = mid - 1;
    }
    top = tot - 1, bot = 0;
    while (top >= bot) {
      int mid = top + bot >> 1;
      if (cmp(sa[mid], path) <= 0) {
        sar[i] = mid;
        bot = mid + 1;
      } else
        top = mid - 1;
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int o = fir[i]; o < fir[i] + len[i]; o++) {
      BT.Add(id[o], 1);
    }
    for (auto qq : Qs[i]) {
      int qi = qq.first;
      int mul = qq.second;
      ans[qi] += mul * (BT.Get(sar[qi]) - BT.Get(sal[qi]));
    }
  }
  for (int i = 1; i <= q; i++) printf("%i\n", ans[i]);
  return 0;
}
