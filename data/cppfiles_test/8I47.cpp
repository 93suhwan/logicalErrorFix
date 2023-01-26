#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long R = 7 + 1e9, R1 = 19491001, R2 = 236, NUMTESTCASE;
const long long NN = 10 + 5e5, MM = 10 + 13e5, KK = 26, Inverse2 = 500000004;
const double pi = acos(-1.0);
int di[8] = {1, 0, -1, 0, 1, -1, 1, -1}, dj[8] = {0, 1, 0, -1, 1, -1, -1, 1};
int Dsu[NN], n, q, u, v, x, Timer, Arr[NN];
int Anc[NN][KK], Xor[NN], Depth[NN], Hash[NN];
int Heavy[NN], Chain[NN], TotH, Head[NN], UpHead[NN];
int STree[MM], Lazy[MM], t;
vector<int> G[NN];
int Root(int u) { return Dsu[u] == u ? u : Dsu[u] = Root(Dsu[u]); }
bool Merge(int u, int v) {
  u = Root(u);
  v = Root(v);
  if (u == v) return false;
  if (u > v) swap(u, v);
  Dsu[u] = v;
  return true;
}
void Hld(int Ver) {
  UpHead[Chain[Ver]] = Anc[Ver][0];
  if (Heavy[Anc[Ver][0]] == Ver)
    Hld(Head[Chain[Anc[Ver][0]] = Chain[Ver]] = Anc[Ver][0]);
}
int Dfs(int Ver, int Par) {
  Depth[Ver] = Depth[Par] + 1;
  Anc[Ver][0] = Par;
  for (int k = 1; k < KK; k++) Anc[Ver][k] = Anc[Anc[Ver][k - 1]][k - 1];
  int Size = 1, Temp;
  pair<int, int> Max = {1, Ver};
  for (auto u : G[Ver])
    if (u ^ Par) Max = max(Max, {Temp = Dfs(u, Ver), u}), Size += Temp;
  Heavy[Ver] = Max.second;
  if (Max.second == Ver) Heavy[Ver] = -1;
  return Size;
}
int Lca(int u, int v) {
  if (Depth[u] < Depth[v]) swap(u, v);
  for (int k = KK - 1; k >= 0; k--)
    if (Depth[Anc[u][k]] >= Depth[v]) u = Anc[u][k];
  if (u == v) return u;
  for (int k = KK - 1; k >= 0; k--)
    if (Anc[u][k] != Anc[v][k]) u = Anc[u][k], v = Anc[v][k];
  return Anc[u][0];
}
int Kth(int Ver, int k) {
  for (int j = 0; j < KK; j++)
    if (k >> j & 1) Ver = Anc[Ver][j];
  return Ver;
}
int XXXX;
void UpdateLazy(int Node, int Len, int p) {
  if (!Lazy[Node]) return;
  assert(Len == 0);
  STree[Node] = max(abs(Arr[p] + Arr[Anc[p][0]]), abs(Arr[p] - Arr[Anc[p][0]]));
  STree[Node] = XXXX;
  if (Len) Lazy[2 * Node] = Lazy[2 * Node + 1] = 1;
  Lazy[Node] = 0;
}
void UpdateSeg(int s, int e, int st = 1, int en = n, int Node = 1) {
  UpdateLazy(Node, en - st, st);
  if (s > en || e < st) return;
  if (s <= st && e >= en) {
    Lazy[Node] = 1;
    return UpdateLazy(Node, en - st, st);
  }
  UpdateSeg(s, e, st, (st + en) / 2, 2 * Node);
  UpdateSeg(s, e, (st + en) / 2 + 1, en, 2 * Node + 1);
  STree[Node] = STree[2 * Node] + STree[2 * Node + 1];
}
int GetSeg(int s, int e, int st = 1, int en = n, int Node = 1) {
  UpdateLazy(Node, en - st, st);
  if (s > en || e < st) return 0;
  if (s <= st && e >= en) return STree[Node];
  return GetSeg(s, e, st, (st + en) / 2, 2 * Node) +
         GetSeg(s, e, (st + en) / 2 + 1, en, 2 * Node + 1);
}
int GetSim(int u, int p) {
  if (Chain[u] == Chain[p]) return GetSeg(Hash[p], Hash[u]);
  return GetSim(u, Head[Chain[u]]) + GetSim(UpHead[Chain[u]], p);
}
int GetPath(int u, int v) {
  int Lca_ = Lca(u, v);
  int Res = 0;
  if (u ^ Lca_) Res += GetSim(u, Kth(u, Depth[u] - Depth[Lca_] - 1));
  if (v ^ Lca_) Res += GetSim(v, Kth(v, Depth[v] - Depth[Lca_] - 1));
  return Res;
}
void Update(int u) { UpdateSeg(Hash[u], Hash[u]); }
void UpdateSim(int u, int p) {
  if (Chain[u] == Chain[p]) return UpdateSeg(Hash[p], Hash[u]);
  UpdateSim(UpHead[Chain[u]], p);
  UpdateSim(u, Head[Chain[u]]);
}
void UpdatePath(int u, int v) {
  int Lca_ = Lca(u, v);
  if (u ^ Lca_) UpdateSim(u, Kth(u, Depth[u] - Depth[Lca_] - 1));
  if (v ^ Lca_) UpdateSim(v, Kth(v, Depth[v] - Depth[Lca_] - 1));
}
int main() {
  cin >> n >> q;
  for (int i = (1); i <= (n); ++i) {
    Dsu[i] = i;
    scanf("%d", Arr + i);
  }
  for (int i = (2); i <= (n); ++i)
    scanf("%d%d", &u, &v), G[u].push_back(v), G[v].push_back(u);
  Dfs(1, 1);
  for (int u = (1); u <= (n); ++u)
    if (Heavy[u] == -1) {
      Hld(Head[Chain[u] = ++TotH] = u);
      for (int v = Head[TotH]; v + 1; v = Heavy[v]) Hash[v] = ++Timer;
    }
  for (int u = (1); u <= (n); ++u) {
    XXXX = max(abs(Arr[u] + Arr[Anc[u][0]]), abs(Arr[u] - Arr[Anc[u][0]]));
    Update(u);
  }
  for (int i = (1); i <= (q); ++i) {
    scanf("%d%d%d", &t, &u, &v);
    if (t == 2)
      printf("%d\n", GetPath(v, u));
    else {
      Arr[u] = v;
      XXXX = max(abs(Arr[u] + Arr[Anc[u][0]]), abs(Arr[u] - Arr[Anc[u][0]]));
      Update(u);
      for (int p : G[u]) {
        if (p ^ Anc[u][0]) {
          XXXX =
              max(abs(Arr[p] + Arr[Anc[p][0]]), abs(Arr[p] - Arr[Anc[p][0]]));
          Update(p);
        }
      }
    }
  }
  return 0;
}
