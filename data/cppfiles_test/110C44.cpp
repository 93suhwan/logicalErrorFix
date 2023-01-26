#include <bits/stdc++.h>
using namespace std;
struct fast_ios {
  fast_ios() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  };
} fast_ios_;
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
  for (int i = 0; i < (int)v.size(); i++) {
    cout << v[i];
    if (i != (int)v.size() - 1) cout << endl;
  };
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
  cout << '(' << p.first << ',' << p.second << ')';
  return os;
}
template <typename T>
void Out(T x) {
  cout << x << endl;
}
template <typename T1, typename T2>
void chOut(bool f, T1 y, T2 n) {
  if (f)
    Out(y);
  else
    Out(n);
}
using vec = vector<int>;
using mat = vector<vec>;
using Pii = pair<int, int>;
using v_bool = vector<bool>;
using v_Pii = vector<Pii>;
const int mod = 998244353;
const int INF = 1000000000;
signed main() {
  int n;
  cin >> n;
  vec x(n), y(n), c(n);
  for (int i = (0); i < (n); i++) {
    cin >> x[i] >> y[i] >> c[i];
    c[i]--;
  }
  int ans1 = 0;
  for (int r = (0); r < (4); r++) {
    vec X(n), Y(n);
    for (int i = (0); i < (n); i++) {
      X[i] = x[i];
      Y[i] = y[i];
      if ((r >> 1) & 1) swap(X[i], Y[i]);
      if (r & 1) Y[i] *= -1;
    }
    vec p({0, 1, 2});
    do {
      int k0 = p[0], k1 = p[1], k2 = p[2];
      vec y0;
      v_Pii xy1, xy2;
      for (int i = (0); i < (n); i++) {
        if (c[i] == k0) y0.push_back(Y[i]);
        if (c[i] == k1) xy1.push_back(Pii(X[i], Y[i]));
        if (c[i] == k2) xy2.push_back(Pii(X[i], Y[i]));
      }
      sort(y0.begin(), y0.end());
      sort(xy1.begin(), xy1.end());
      sort(xy2.begin(), xy2.end());
      int ok = 0, ng = n / 3 + 1;
      while (ng - ok > 1) {
        int mid = (ng + ok) / 2;
        int Yth = y0[mid - 1];
        int Xl = INF, Xr = -INF;
        int cntl = 0, cntr = 0;
        for (int i = (0); i < (n / 3); i++)
          if (xy1[i].second > Yth) {
            cntl++;
            if (cntl == mid) {
              Xl = xy1[i].first;
              break;
            }
          }
        for (int i = (n / 3) - 1; i >= (0); i--)
          if (xy2[i].second > Yth) {
            cntr++;
            if (cntr == mid) {
              Xr = xy2[i].first;
              break;
            }
          }
        if (Xl < Xr)
          ok = mid;
        else
          ng = mid;
      }
      ans1 = max(ans1, ok);
    } while (next_permutation(p.begin(), p.end()));
  }
  int ans2 = 0;
  for (int r = (0); r < (2); r++) {
    vec p({0, 1, 2});
    do {
      mat X(3);
      for (int i = (0); i < (n); i++) {
        int xx = (r == 0 ? x[i] : y[i]);
        X[p[c[i]]].push_back(xx);
      }
      for (int k = (0); k < (3); k++) sort(X[k].begin(), X[k].end());
      for (int i = (0); i < (n / 3); i++) {
        if (X[0][i] < X[2][n / 3 - 1 - i] &&
            (int)distance(X[1].begin(), lower_bound(X[1].begin(), X[1].end(),
                                                    X[2][n / 3 - 1 - i])) -
                    (int)distance(
                        X[1].begin(),
                        upper_bound(X[1].begin(), X[1].end(), X[0][i])) >=
                i + 1) {
          ans2 = max(ans2, i + 1);
        }
      }
    } while (next_permutation(p.begin(), p.end()));
  }
  Out(max(ans1, ans2) * 3);
  return 0;
}
