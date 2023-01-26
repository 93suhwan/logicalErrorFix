#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e4 + 43;
int facts[MAXN];
int bfacts[MAXN];
const int mod = 998244353;
int ml(int a, int b) { return (a * 1ll * b) % mod; }
int cNr(int n, int r) {
  if (n < r) return 0;
  return ml(facts[n], ml(bfacts[r], bfacts[n - r]));
}
int b_p(int b, int p) {
  if (p == 0) return 1;
  if (p & 1) return ml(b, b_p(b, p - 1));
  int v = b_p(b, p >> 1);
  return ml(v, v);
}
int add(int a, int b) {
  int res = a + b;
  if (res >= mod) res -= mod;
  return res;
}
int sub(int a, int b) { return add(a, mod - b); }
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> xi;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      xi.push_back(x);
    }
    vector<string> tst;
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      tst.push_back(s);
    }
    vector<int> answr(m, 0);
    for (int i = 0; i < m; ++i) {
      answr[i] = i + 1;
    }
    int mx = -1;
    for (int mask = 0; mask < (1 << n); ++mask) {
      int cr = 0;
      vector<int> coef(m, 0);
      for (int j = 0; j < n; ++j) {
        if ((1 << j) & mask) {
          cr -= xi[j];
          for (int k = 0; k < m; ++k) {
            if (tst[j][k] == '1') {
              coef[k]++;
            }
          }
        } else {
          cr += xi[j];
          for (int k = 0; k < m; ++k) {
            if (tst[j][k] == '1') {
              coef[k]--;
            }
          }
        }
      }
      vector<pair<int, int>> vp;
      for (int i = 0; i < m; ++i) {
        vp.push_back({coef[i], i});
      }
      sort(vp.begin(), vp.end());
      vector<int> cur_a(m, 0);
      for (int j = m; j >= 1; --j) {
        cur_a[vp[j - 1].second] = j;
        cr += vp[j - 1].first * j;
      }
      if (cr > mx) {
        mx = cr;
        answr = cur_a;
      }
    }
    for (auto e : answr) {
      cout << e << " ";
    }
    cout << "\n";
  }
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  solve();
}
