#include <bits/stdc++.h>
using namespace std;
const int N = int(5e5 + 5);
const int mod = int(998244353);
vector<int> a[N], pmin[N], pmax[N], smin[N], smax[N];
inline void res(int n, int m) {
  for (int i = 0; i < n; i++) {
    a[i].resize(m);
    pmin[i].resize(m);
    pmax[i].resize(m);
    smin[i].resize(m);
    smax[i].resize(m);
  }
}
struct inf {
  int pmin, pmax, smin, smax, id;
};
void solve() {
  int n, m;
  cin >> n >> m;
  res(n, m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      pmin[i][j] = a[i][j];
      pmax[i][j] = a[i][j];
      if (j) {
        pmin[i][j] = min(pmin[i][j], pmin[i][j - 1]);
        pmax[i][j] = max(pmax[i][j], pmax[i][j - 1]);
      }
    }
    for (int j = m - 1; j >= 0; j--) {
      smin[i][j] = a[i][j];
      smax[i][j] = a[i][j];
      if (j != m - 1) {
        smin[i][j] = min(smin[i][j], smin[i][j + 1]);
        smax[i][j] = max(smax[i][j], smax[i][j + 1]);
      }
    }
  }
  vector<inf> b(n);
  for (int raz = 0; raz + 1 < m; raz++) {
    for (int i = 0; i < n; i++) {
      b[i].pmax = pmax[i][raz];
      b[i].pmin = pmin[i][raz];
      b[i].smax = smax[i][raz + 1];
      b[i].smin = smin[i][raz + 1];
      b[i].id = i;
    }
    sort(b.begin(), b.end(), [](inf x, inf y) { return x.pmax < y.pmax; });
    vector<inf> q(n);
    for (int i = n - 1; i >= 0; i--) {
      q[i] = b[i];
      if (i != n - 1) {
        q[i].pmin = min(q[i].pmin, q[i + 1].pmin);
        q[i].pmax = max(q[i].pmax, q[i + 1].pmax);
        q[i].smin = min(q[i].smin, q[i + 1].smin);
        q[i].smax = max(q[i].smax, q[i + 1].smax);
      }
    }
    vector<char> s(n + n, 'R');
    inf cur = b[0];
    for (int i = 0; i + 1 < n; i++) {
      cur.pmin = min(cur.pmin, b[i].pmin);
      cur.pmax = max(cur.pmax, b[i].pmax);
      cur.smin = min(cur.smin, b[i].smin);
      cur.smax = max(cur.smax, b[i].smax);
      if (cur.pmax < q[i + 1].pmin && cur.smin > q[i + 1].smax) {
        for (int ii = 0; ii <= i; ii++) {
          s[b[ii].id] = 'B';
        }
        cout << "YES\n";
        for (int ii = 0; ii < n; ii++) {
          cout << s[ii];
        }
        cout << " " << raz + 1 << "\n";
        res(n, 0);
        return;
      }
    }
  }
  cout << "NO\n";
  res(n, 0);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tests = 1;
  cin >> tests;
  while (tests--) {
    solve();
  }
  return 0;
}
