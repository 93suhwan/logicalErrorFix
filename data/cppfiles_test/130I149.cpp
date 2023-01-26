#include <bits/stdc++.h>
using namespace std;
int ask(int a, int b, int c) {
  cout << "? " << a << " " << b << " " << c << '\n';
  int r;
  cin >> r;
  return r;
}
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> z, o;
  vector<bool> vis(n + 1);
  for (int i = 1; i <= n; i += 3) {
    int res = ask(i, i + 1, i + 2);
    if (res == 0)
      z.push_back(vector<int>{i, i + 1, i + 2});
    else
      o.push_back(vector<int>{i, i + 1, i + 2});
  }
  vector<int> zero, one;
  auto a = z[0];
  auto b = o[0];
  int imp, crew;
  vector<int> r;
  for (int i = 0; i < 3; i++) {
    int res;
    res = ask(b[0], b[1], a[i]);
    r.push_back(res);
  }
  if ((accumulate((r).begin(), (r).end(), 0ll)) == 3) {
    r.clear();
    for (int i = 0; i < 3; i++) {
      r.push_back(ask(b[0], b[2], a[i]));
    }
    if ((accumulate((r).begin(), (r).end(), 0ll)) == 3) {
      one.push_back(b[0]);
      zero.push_back(b[1]);
      imp = b[1];
      crew = b[0];
    } else {
      zero.push_back(b[0]);
      one.push_back(b[1]);
      imp = b[0];
      crew = b[1];
    }
  } else {
    r.clear();
    for (int i = 0; i < 3; i++) {
      int res;
      res = ask(b[0], a[i], a[(i + 1) % 3]);
      if (res == 0) {
        crew = b[0];
        imp = a[(i + 1) % 3];
        one.push_back(b[0]);
        zero.push_back(crew);
        break;
      }
    }
  }
  int i2, c2;
  vector<int> idx;
  for (auto a : z[0]) idx.push_back(a);
  for (auto a : o[0]) idx.push_back(a);
  for (auto a : idx) {
    if (a == imp or a == crew) continue;
    int res = ask(imp, crew, a);
    if (res == 1)
      one.push_back(a);
    else
      zero.push_back(a);
  }
  for (int i = 1; i < int(z.size()); i++) {
    int j;
    for (j = 0; j < 2; j++) {
      int res = ask(z[i][j], imp, crew);
      if (res == 1) {
        for (int k = 0; k < 3; k++) {
          if (k == j)
            one.push_back(z[i][j]);
          else
            zero.push_back(z[i][j]);
        }
        break;
      }
    }
    if (j == 2) {
      for (int k = 0; k < 3; k++) {
        zero.push_back(z[i][j]);
      }
    }
  }
  for (int i = 1; i < int(o.size()); i++) {
    int j = 0;
    for (j = 0; j < 2; j++) {
      int res = ask(o[i][j], imp, crew);
      if (res == 0) {
        for (int k = 0; k < 3; k++) {
          if (k == j)
            zero.push_back(z[i][j]);
          else
            one.push_back(z[i][j]);
        }
        break;
      }
    }
    if (j == 2) {
      for (int k = 0; k < 3; k++) {
        one.push_back(z[i][j]);
      }
    }
  }
  cout << "! " << int(zero.size()) << " ";
  for (auto z : zero) cout << z << " ";
  cout << '\n';
}
signed main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
