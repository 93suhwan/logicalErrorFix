#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, m, q, qu[100005], qv[100005], qs[100005], qr[100005];
vector<pair<int, char> > G[100005];
string T[100005];
int pos[100005];
vector<int> vs[100005], vr[100005];
struct SAM {
  int cnt, nxt[200005][26], tch[200005][26], par[200005], dep[200005];
  vector<int> G[200005];
  pair<int, int> vid[200005];
  int dfn[200005], dfo[200005], tot;
  void clear() {
    cnt = 1;
    memset(nxt, -1, sizeof(nxt));
    memset(par, -1, sizeof(par));
    memset(dep, 0, sizeof(dep));
  }
  int append(int x, int ch) {
    if (nxt[x][ch] != -1) return nxt[x][ch];
    int ret = cnt++;
    dep[ret] = dep[x] + 1;
    for (; x != -1 && nxt[x][ch] == -1; x = par[x]) nxt[x][ch] = ret;
    if (x == -1)
      par[ret] = 0;
    else if (dep[x] + 1 == dep[nxt[x][ch]])
      par[ret] = nxt[x][ch];
    else {
      int nr = cnt++, fr = nxt[x][ch];
      dep[nr] = dep[x] + 1;
      par[nr] = par[fr];
      par[fr] = nr;
      for (int i = 0; i < (int)(26); i++) nxt[nr][i] = nxt[fr][i];
      par[ret] = nr;
      for (; x != -1 && nxt[x][ch] == fr; x = par[x]) nxt[x][ch] = nr;
    }
    return ret;
  }
  void dfs(int v, int coef) {
    dfn[v] = ++tot;
    for (int i = 0; i < (int)(26); i++) tch[v][i] = -1;
    for (int i = 0; i < (int)(G[v].size()); i++) {
      dfs(G[v][i], coef);
      vid[v] = vid[G[v][i]];
      tch[v][T[vid[v].first][vid[v].second + coef * dep[v]]] = G[v][i];
    }
    dfo[v] = tot;
  }
  void getre(int coef) {
    for (int i = 1; i <= (int)(cnt - 1); i++) G[par[i]].push_back(i);
    dfs(0, coef);
  }
} S, R;
pair<int, int> gnxtS(pair<int, int> cur, int ch, const SAM& X, int coef) {
  if (cur.first == -1) return make_pair(-1, cur.second + 1);
  if (X.dep[cur.first] == cur.second)
    return make_pair(X.tch[cur.first][ch], cur.second + 1);
  else
    return make_pair(T[X.vid[cur.first].first]
                      [X.vid[cur.first].second + coef * cur.second] == ch
                         ? cur.first
                         : -1,
                     cur.second + 1);
}
queue<int> que;
void gen_sam(SAM& cur, vector<int> ver[]) {
  cur.clear();
  for (int i = 0; i < (int)(m); i++) {
    pos[i] = 0;
    ver[i].push_back(0);
    que.push(i);
  }
  while (!que.empty()) {
    int id = que.front();
    que.pop();
    int cv = ver[id].back();
    ver[id].push_back(cur.append(cv, T[id][pos[id]++]));
    if (pos[id] < (int)T[id].length()) que.push(id);
  }
}
bool del[100005];
int siz[100005], cid[100005];
pair<int, int> ps[100005], pr[100005];
vector<int> hv[100005];
void dfs0(int v, int p) {
  siz[v] = 1;
  for (int i = 0; i < (int)(G[v].size()); i++) {
    int u = G[v][i].first;
    if (del[u] || u == p) continue;
    dfs0(u, v);
    siz[v] += siz[u];
  }
}
int dfs1(int v, int p, int tsz) {
  for (int i = 0; i < (int)(G[v].size()); i++) {
    int u = G[v][i].first;
    if (del[u] || u == p) continue;
    if (siz[u] * 2 > tsz) return dfs1(u, v, tsz);
  }
  return v;
}
void dfs2(int v, int p, int gr) {
  cid[v] = gr;
  for (int i = 0; i < (int)(G[v].size()); i++) {
    int u = G[v][i].first;
    if (del[u] || u == p) continue;
    ps[u] = gnxtS(ps[v], G[v][i].second, S, -1);
    pr[u] = gnxtS(pr[v], G[v][i].second, R, 1);
    dfs2(u, v, gr ? gr : u);
  }
}
void solve(int v) {
  dfs0(v, 0);
  int u = dfs1(v, 0, siz[v]);
  swap(hv[u], hv[v]);
  ps[u] = pr[u] = make_pair(0, 0);
  dfs2(u, 0, 0);
  for (int i = 0; i < (int)(hv[u].size()); i++) {
    int cq = hv[u][i];
    if (cid[qu[cq]] && cid[qv[cq]] && cid[qu[cq]] == cid[qv[cq]])
      hv[cid[qu[cq]]].push_back(cq);
    else {
      qs[cq] = ps[qu[cq]].first;
      qr[cq] = pr[qv[cq]].first;
    }
  }
  del[u] = true;
  for (int i = 0; i < (int)(G[u].size()); i++) {
    v = G[u][i].first;
    if (!del[v]) solve(v);
  }
}
struct fwt {
  int dat[262145];
  void add(int id, int val) {
    for (id++; id > 0; id -= id & -id) dat[id] += val;
  }
  int query(int id) {
    int ret = 0;
    for (id++; id <= 262144; id += id & -id) ret += dat[id];
    return ret;
  }
  int query(int l, int r) { return query(l) - query(r + 1); }
} tre;
int ans[100005];
vector<pair<int, int> > qy[100005];
vector<pair<int, pair<int, int> > > calc(int l, int r) {
  if (l == r) {
    vector<pair<int, pair<int, int> > > ret;
    for (int i = 0; i < (int)(vs[l].size()); i++)
      ret.push_back(make_pair(S.dfn[vs[l][i]], make_pair(0, R.dfn[vr[l][i]])));
    for (int i = 0; i < (int)(qy[l].size()); i++) {
      int cq = qy[l][i].first;
      if (qy[l][i].second == -1) {
        ret.push_back(make_pair(S.dfn[qs[cq]] - 1, make_pair(1, cq)));
        ret.push_back(make_pair(S.dfo[qs[cq]] + 1, make_pair(-1, cq)));
      } else {
        ret.push_back(make_pair(S.dfn[qs[cq]], make_pair(-1, cq)));
        ret.push_back(make_pair(S.dfo[qs[cq]], make_pair(1, cq)));
      }
    }
    sort(ret.begin(), ret.end());
    return ret;
  }
  int mid = (l + r) >> 1;
  vector<pair<int, pair<int, int> > > A = calc(l, mid), B = calc(mid + 1, r), C;
  C.resize(A.size() + B.size());
  int i = 0, j = 0, k = 0;
  while (i < A.size() || j < B.size()) {
    pair<int, pair<int, int> > cur;
    if (j == B.size() || (i < A.size() && A[i] < B[j])) {
      C[k++] = cur = A[i++];
      if (cur.second.first == 0) tre.add(cur.second.second, 1);
    } else {
      C[k++] = cur = B[j++];
      if (cur.second.first != 0) {
        int cq = cur.second.second, cc = cur.second.first;
        ans[cq] += cc * tre.query(R.dfn[qr[cq]], R.dfo[qr[cq]]);
      }
    }
  }
  for (int i = 0; i < (int)(C.size()); i++)
    if (C[i].second.first == 0) tre.add(C[i].second.second, -1);
  return C;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> q;
  for (int i = 0; i < (int)(n - 1); i++) {
    int u, v;
    char c;
    cin >> u >> v >> c;
    c -= 'a';
    G[u].push_back(make_pair(v, c));
    G[v].push_back(make_pair(u, c));
  }
  for (int i = 0; i < (int)(m); i++) cin >> T[i];
  for (int i = 0; i < (int)(m); i++)
    for (int j = 0; j < (int)(T[i].size()); j++) T[i][j] -= 'a';
  for (int i = 0; i < (int)(q); i++) {
    int l, r;
    cin >> qu[i] >> qv[i] >> l >> r;
    qy[l - 1].push_back(make_pair(i, -1));
    qy[r].push_back(make_pair(i, 1));
  }
  gen_sam(S, vs);
  for (int i = 0; i < (int)(m); i++) reverse(T[i].begin(), T[i].end());
  gen_sam(R, vr);
  for (int i = 0; i < (int)(m); i++) {
    reverse(T[i].begin(), T[i].end());
    reverse(vr[i].begin(), vr[i].end());
  }
  for (int i = 0; i < (int)(m); i++)
    for (int j = 0; j < (int)(T[i].length()); j++)
      S.vid[vs[i][j + 1]] = R.vid[vr[i][j]] = make_pair(i, j);
  S.getre(-1);
  R.getre(1);
  for (int i = 0; i < (int)(q); i++) hv[1].push_back(i);
  solve(1);
  calc(0, m);
  for (int i = 0; i < (int)(q); i++) cout << ans[i] << '\n';
  return 0;
}
