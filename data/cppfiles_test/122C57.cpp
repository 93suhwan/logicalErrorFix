#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;
int par[200020], sz[200020], flp[200020];
vector<int> cld[200020];
int fnd(int a) {
  if (par[a] == a) {
    return a;
  }
  return par[a] = fnd(par[a]);
}
int uni(int a, int b, int c) {
  int pa = fnd(a), pb = fnd(b);
  if (pa == pb) {
    if ((flp[a] ^ flp[b]) != c) {
      return -1;
    }
    return 0;
  }
  if (sz[pa] > sz[pb]) {
    swap(pa, pb);
    swap(a, b);
  }
  bool chk = ((flp[b] ^ flp[a]) != c);
  for (int x : cld[pa]) {
    cld[pb].push_back(x);
    if (chk) {
      flp[x] ^= 1;
    }
  }
  cld[pa].clear();
  sz[pb] += sz[pa];
  par[pa] = pb;
  return 0;
}
vector<pair<pi2, int> > qry;
void Main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      par[i] = i;
      flp[i] = 0;
      sz[i] = 1;
      cld[i].push_back(i);
    }
    for (int i = 1; i < n; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      if (z != -1) {
        int a = 0;
        for (int b = 0; b <= 30; b++) {
          int bit = 1 << b;
          if (z & bit) {
            a ^= 1;
          }
        }
        uni(x, y, a);
        qry.push_back({{x, y}, z});
      } else {
        qry.push_back({{x, y}, -1});
      }
    }
    bool flg = 1;
    while (m--) {
      int a, b, c;
      cin >> a >> b >> c;
      int res = uni(a, b, c);
      if (res == -1) {
        flg = 0;
      }
    }
    if (!flg) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
      for (pair<pi2, int> q : qry) {
        int a = q.first.first, b = q.first.second;
        int c = q.second;
        cout << a << ' ' << b << ' ';
        if (c != -1) {
          cout << c << '\n';
        } else {
          cout << (flp[a] ^ flp[b]) << '\n';
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      cld[i].clear();
      qry.clear();
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.precision(0);
  Main();
}
