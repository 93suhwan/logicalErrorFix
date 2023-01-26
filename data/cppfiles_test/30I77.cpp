#include <bits/stdc++.h>
using namespace std;
bool pd[1000500 * 2 + 1];
int p[1000500 * 2], p_num[1000500 * 2], p_fa[1000500 * 2], acc = 0,
                                                           fa[1000500 * 2];
int n, q, a[1000500 * 2], b[1000500 * 2];
int get(int x) {
  if (x == fa[x])
    return x;
  else
    return fa[x] = get(fa[x]);
}
int merge(int x, int y) {
  x = get(x);
  y = get(y);
  fa[x] = y;
}
vector<int> zy[1000500 * 2];
map<int, int> MAP[1000500 * 2];
int main() {
  int k;
  memset(pd, false, sizeof(pd));
  for (int i = 2; i <= 1000500; i++) {
    if (pd[i]) continue;
    for (int j = i; j <= 1000500; j += i) {
      pd[j] = true;
      k++;
      zy[j].push_back(i);
    }
    p[++acc] = i;
  }
  for (int i = 1; i < 1000500; i++) fa[i] = i;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i], b[a[i]] = i;
  for (int i = 1; i <= acc; i++) {
    int bc = 0;
    for (int j = 1; j <= 1000500; j++) {
      if (p[i] * j > 1000000) break;
      if (b[p[i] * j]) {
        p_num[p[i]] = b[p[i] * j];
        if (bc != 0) merge(bc, b[p[i] * j]);
        bc = b[p[i] * j];
      }
    }
  }
  for (int i = 1; i <= acc; i++) {
    p_fa[p[i]] = get(p_num[p[i]]);
  }
  int s, t;
  for (int i = 1; i <= n; i++) {
    int A = i, B = a[i] + 1;
    A = get(A);
    for (int i = 0; i <= zy[B].size() - 1; i++) {
      int ys = zy[B][i];
      if (MAP[A].find(p_fa[ys]) == MAP[A].end()) MAP[A][p_fa[ys]] = 1;
    }
  }
  for (int i = 1; i <= q; i++) {
    cin >> s >> t;
    if (get(s) == get(t)) {
      cout << 0 << endl;
      continue;
    }
    s = get(s), t = get(t);
    if (MAP[s].find(t) != MAP[s].end() || MAP[t].find(s) != MAP[t].end()) {
      cout << 1 << endl;
      continue;
    }
    cout << 2 << endl;
  }
  return 0;
}
