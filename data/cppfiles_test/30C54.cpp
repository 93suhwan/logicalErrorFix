#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e, i, j, ii, jj, zx, xc, tes, t, f[150009], sac[1000009],
    msh[150009], zm[150009], p[1009], pi;
vector<int> v[150009], vv[1000009];
map<int, bool> m[150009];
int fnd(int q) {
  if (msh[q] == q)
    return q;
  else
    return msh[q] = fnd(msh[q]);
}
void mrg(int q, int w) {
  q = fnd(q);
  w = fnd(w);
  if (q == w) return;
  if (zm[q] < zm[w]) swap(q, w);
  msh[w] = q;
  if (zm[q] == zm[w]) zm[q]++;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> a >> tes;
  for (i = 1; i <= a; i++) {
    cin >> f[i];
  }
  for (i = 2; i <= 1000002; i++) {
    if (sac[i] == 0) {
      sac[i] = i;
      if (i <= 10000)
        for (j = i * i; j <= 1000002; j += i) {
          if (sac[j] == 0) sac[j] = i;
        }
    }
  }
  for (i = 1; i <= a; i++) {
    c = f[i];
    d = 0;
    while (c > 1) {
      if (sac[c] != d) {
        d = sac[c];
        v[i].push_back(d);
      }
      c /= sac[c];
    }
    for (j = 0; j < v[i].size(); j++) {
      vv[v[i][j]].push_back(i);
    }
  }
  for (i = 1; i <= a; i++) {
    msh[i] = i;
    zm[i] = 1;
  }
  for (i = 0; i <= 1000002; i++) {
    c = vv[i].size();
    for (j = 0; j < c - 1; j++) {
      mrg(vv[i][j], vv[i][j + 1]);
    }
  }
  for (i = 1; i <= a; i++) {
    pi = 0;
    c = v[i].size();
    for (j = 0; j < c; j++) {
      pi++;
      p[pi] = fnd(vv[v[i][j]][0]);
    }
    v[0].clear();
    c = f[i] + 1;
    d = 0;
    while (c > 1) {
      if (sac[c] != d) {
        d = sac[c];
        v[0].push_back(d);
      }
      c /= sac[c];
    }
    for (j = 0; j < v[0].size(); j++) {
      if (vv[v[0][j]].size() != 0) {
        pi++;
        p[pi] = fnd(vv[v[0][j]][0]);
      }
    }
    for (j = 1; j <= pi; j++) {
      for (jj = j + 1; jj <= pi; jj++) {
        if (p[j] == p[jj]) continue;
        if (p[j] < p[jj]) {
          m[p[j]][p[jj]] = 1;
        } else {
          m[p[jj]][p[j]] = 1;
        }
      }
    }
  }
  for (t = 1; t <= tes; t++) {
    cin >> c >> d;
    zx = fnd(c);
    xc = fnd(d);
    if (zx > xc) swap(zx, xc);
    if (zx == xc) {
      cout << 0 << endl;
      continue;
    }
    if (m[zx][xc] == 1) {
      cout << 1 << endl;
      continue;
    }
    cout << 2 << endl;
  }
  return 0;
}
