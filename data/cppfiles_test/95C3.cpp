#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
T firstTrue(T lo, T hi, U f) {
  assert(lo <= hi);
  ++hi;
  while (lo < hi) {
    T mid = lo + (hi - lo) / 2;
    f(mid) ? hi = mid : lo = mid + 1;
  }
  return lo;
}
template <class T, class U>
T lastTrue(T lo, T hi, U f) {
  assert(lo <= hi);
  --lo;
  while (lo < hi) {
    T mid = lo + (hi - lo + 1) / 2;
    f(mid) ? lo = mid : hi = mid - 1;
  }
  return lo;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> a(n, vector<int>(m)), pmn(n), pmx(n), smn(n), smx(n);
    for (vector<int> &aa : a)
      for (int &x : aa) scanf("%d", &x);
    int MX = 0;
    for (int i = 0; i < n; i++) {
      int mn = 0x3f3f3f3f, mx = 0;
      for (int x : a[i]) {
        pmn[i].push_back(mn = min(mn, x));
        pmx[i].push_back(mx = max(mx, x));
      }
      reverse(begin(a[i]), end(a[i]));
      mn = 0x3f3f3f3f, mx = 0;
      for (int x : a[i]) {
        smn[i].push_back(mn = min(mn, x));
        smx[i].push_back(mx = max(mx, x));
      }
      MX = max(MX, mx);
      reverse(begin(smn[i]), end(smn[i]));
      reverse(begin(smx[i]), end(smx[i]));
      reverse(begin(a[i]), end(a[i]));
    }
    for (int j = 0; j + 1 < m; j++) {
      vector<int> c(n, -1), ii(n), ij(n);
      queue<int> q;
      for (int i = 0; i < n; i++) ii[i] = i, ij[i] = i;
      sort(begin(ii), end(ii),
           [&](int aa, int bb) { return pmn[aa][j] < pmn[bb][j]; });
      sort(begin(ij), end(ij),
           [&](int aa, int bb) { return smx[aa][j + 1] > smx[bb][j + 1]; });
      c[ii[0]] = 1, q.push(ii[0]);
      c[ij[0]] = 1, q.push(ij[0]);
      int li = 0, lj = 0;
      while (!q.empty()) {
        int x = q.front();
        q.pop();
        int mx = pmx[x][j];
        int idi =
            lastTrue(li, n - 1, [&](int iii) { return pmn[ii[iii]][j] <= mx; });
        for (int k = li + 1; k <= idi; k++) {
          if (c[ii[k]] == -1) {
            c[ii[k]] = 1;
            q.push(ii[k]);
          }
        }
        li = idi;
        int mn = smn[x][j + 1];
        int idj = lastTrue(lj, n - 1,
                           [&](int iii) { return smx[ij[iii]][j + 1] >= mn; });
        for (int k = lj + 1; k <= idj; k++) {
          if (c[ij[k]] == -1) {
            c[ij[k]] = 1;
            q.push(ij[k]);
          }
        }
        lj = idj;
      }
      for (int &i : c) {
        if (i == -1) i = 0;
      }
      int mn = 0x3f3f3f3f, mx = 0;
      for (int i = 0; i < n; i++)
        if (c[i])
          mx = max(mx, pmx[i][j]);
        else
          mn = min(mn, pmn[i][j]);
      if (mx < mn && mn != 0x3f3f3f3f && mx != 0) {
        mn = 0x3f3f3f3f, mx = 0;
        for (int i = 0; i < n; i++)
          if (!c[i])
            mx = max(mx, smx[i][j + 1]);
          else
            mn = min(mn, smn[i][j + 1]);
        if (mx < mn && mn != 0x3f3f3f3f && mx != 0) {
          printf("YES\n");
          for (int i = 0; i < n; i++) printf(c[i] ? "B" : "R");
          printf(" %d\n", 1 + j);
          goto end;
        }
      }
    }
    printf("NO\n");
  end:;
  }
  return 0;
}
