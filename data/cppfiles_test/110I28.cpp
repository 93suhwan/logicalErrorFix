#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;
int Bit(int mask, int b) { return (mask >> b) & 1; }
template <class T>
bool ckmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool ckmax(T &a, const T &b) {
  if (b > a) {
    a = b;
    return true;
  }
  return false;
}
const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 2e5;
const int LG = 30;
struct fenwick {
  int n{};
  vector<ll> fenw{};
  void build(int k) {
    n = k;
    fenw.resize(n);
  }
  void upd(int i, ll x) {
    for (; i < n; i = i | (i + 1)) fenw[i] += x;
  }
  ll get(int i) {
    ll res = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) res += fenw[i];
    return res;
  }
};
int lower_bound(fenwick &f1, fenwick &f2) {
  int r = -1;
  ll x = f2.get(f2.n - 1);
  for (int j = 20; j >= 0; --j) {
    int t = (1 << j);
    if (r + t >= f1.n) continue;
    if (f2.fenw[r + t] + f1.fenw[r + t] >= x) continue;
    r += t;
    x -= f2.fenw[r] + f1.fenw[r];
  }
  return r + 1;
}
void solve() {
  int n;
  cin >> n;
  vector<array<int, 3>> a(n);
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (3); ++j) cin >> a[i][j];
  vector<int> xx, yy;
  for (int i = 0; i < (n); ++i) {
    xx.push_back(a[i][0]);
    yy.push_back(a[i][1]);
    a[i][2]--;
  }
  sort((xx).begin(), (xx).end());
  sort((yy).begin(), (yy).end());
  xx.resize(unique((xx).begin(), (xx).end()) - xx.begin());
  yy.resize(unique((yy).begin(), (yy).end()) - yy.begin());
  for (int i = 0; i < (n); ++i) {
    a[i][0] = lower_bound((xx).begin(), (xx).end(), a[i][0]) - xx.begin();
    a[i][1] = lower_bound((yy).begin(), (yy).end(), a[i][1]) - yy.begin();
  }
  int ans = 0;
  for (int _ = 0; _ < (2); ++_) {
    sort((a).begin(), (a).end());
    for (int __ = 0; __ < (2); ++__) {
      vector<fenwick> ct(3);
      for (int i = 0; i < (3); ++i) ct[i].build(n);
      for (int i = 0; i < (n - 1); ++i) {
        auto [x, y, c] = a[i];
        ct[c].upd(y, 1);
        if (a[i + 1][0] == x) continue;
        for (int colR = 0; colR < (3); ++colR) {
          for (int colD = 0; colD < (3); ++colD) {
            if (colD == colR) continue;
            int colU = 3 ^ (colD ^ colR);
            int ctR = n / 3 - ct[colR].get(n - 1);
            int j = lower_bound(ct[colD], ct[colU]);
            for (int k = j - 2; k <= j + 2; ++k) {
              if (k <= 0 || k >= n) continue;
              int ctD = ct[colD].get(k - 1);
              int ctU = ct[colU].get(n - 1) - ct[colU].get(k - 1);
              ans = max(ans, min({ctD, ctU, ctR}));
            }
          }
        }
      }
      reverse((a).begin(), (a).end());
    }
    for (int i = 0; i < (n); ++i) swap(a[i][0], a[i][1]);
  }
  cout << ans * 3 << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  for (int i = 0; i < (t); ++i) {
    solve();
  }
  return 0;
}
