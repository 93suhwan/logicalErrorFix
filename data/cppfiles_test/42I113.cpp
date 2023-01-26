#include <bits/stdc++.h>
using namespace std;
const int dim = 300009, dim1 = 4000009, inf = 1e7;
struct seg {
  int l, r, w;
} v[dim];
int aint[dim1], lazy[dim1];
void push(int nod) {
  lazy[2 * nod] += lazy[nod];
  lazy[2 * nod + 1] += lazy[nod];
  aint[nod] += lazy[nod];
  lazy[nod] = 0;
}
void Update(int nod, int st, int dr, int l, int r, int val) {
  push(nod);
  if (l >= r) return;
  if (st == l && dr == r) {
    aint[nod] += val;
    return;
  } else {
    int mij = (st + dr) / 2;
    Update(2 * nod, st, mij, l, min(mij, r), val);
    Update(2 * nod + 1, mij + 1, dr, max(mij + 1, l), r, val);
  }
  aint[nod] = min(aint[2 * nod], aint[2 * nod + 1]);
}
bool cmp(seg a, seg b) { return a.w <= b.w; }
void fast() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
signed main() {
  fast();
  int n, m, ans = inf;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> v[i].l >> v[i].r >> v[i].w;
    v[i].r--;
  }
  m--;
  sort(v + 1, v + n + 1, cmp);
  int j = 1;
  for (int i = 1; i <= n; i++) {
    while (j <= n && !aint[1]) {
      Update(1, 1, m, v[j].l, v[j].r, 1);
      j++;
    }
    if (!aint[1]) {
      break;
    }
    ans = min(ans, v[j - 1].w - v[i].w);
    Update(1, 1, m, v[i].l, v[i].r, -1);
  }
  cout << ans;
}
