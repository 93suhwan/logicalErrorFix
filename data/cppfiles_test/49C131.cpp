#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline void chkmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
inline void chkmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int Mod = 1000000007;
int sum(int a, int b) { return (a + b >= Mod ? a + b - Mod : a + b); }
int mul(int a, int b) { return ((ll)a * b) % Mod; }
int powm(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
int inv(int a) { return powm(a, Mod - 2); }
const int MAXN = 15;
int n;
int a[MAXN];
int p[MAXN][MAXN];
int dp[1 << MAXN][MAXN][MAXN];
int who[MAXN];
unordered_map<int, int> val[1 << MAXN];
int whos[1 << MAXN];
int kek[1 << MAXN];
int g[6000228];
int pref[1 << MAXN];
int pos[1 << MAXN];
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      p[i][j] = mul(a[i], powm(a[i] + a[j], Mod - 2));
    }
    p[i][i] = 1;
  }
  int uk = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    vector<int> gg;
    for (int t = 0; t < n; t++) {
      if (mask & (1 << t)) {
        gg.push_back(t);
        who[t] = (int)(gg).size() - 1;
      }
    }
    pref[mask] = uk;
    for (int mask1 = 0; mask1 < (1 << (int)(gg).size()); mask1++) {
      int sub = 0;
      for (int k = 0; k < (int)(gg).size(); k++) {
        if (mask1 & (1 << k)) {
          sub |= (1 << gg[k]);
        }
      }
      whos[mask1] = sub;
      int nsub = mask ^ sub;
      int res = 1;
      for (int k = 0; k < n; k++) {
        if (sub & (1 << k)) {
          for (int k1 = 0; k1 < n; k1++) {
            if (nsub & (1 << k1)) {
              res = mul(res, p[k1][k]);
            }
          }
        }
      }
      g[uk] = res;
      pos[sub] = uk - pref[mask];
      uk++;
    }
    for (auto i : gg) {
      if ((int)(gg).size() == 1) {
        for (int j = 0; j <= n; j++) {
          dp[mask][i][j] = 1;
        }
      } else {
        for (int mask1 = 0; mask1 < (1 << (int)(gg).size()); mask1++) {
          int sub = whos[mask1];
          if (sub & (1 << i)) {
            continue;
          }
          int nsub = mask ^ (1 << i) ^ sub;
          int npos = 0;
          int tp = 1;
          for (int k = 0; k < (int)(gg).size(); k++) {
            if (sub & (1 << gg[k])) {
              npos += tp;
            }
            if ((sub | nsub) & (1 << gg[k])) {
              tp <<= 1;
            }
          }
          kek[mask1] = g[pref[sub | nsub] + npos];
        }
        for (int j = n - 1; j >= 0; j--) {
          if (i != j && (mask & (1 << j))) {
            for (int mask1 = 0; mask1 < (1 << (int)(gg).size()); mask1++) {
              int sub = whos[mask1];
              if (sub & (1 << i)) {
                continue;
              }
              if (!(sub & (1 << j))) {
                continue;
              }
              int nsub = mask ^ (1 << i) ^ sub;
              dp[mask][i][j] =
                  sum(dp[mask][i][j],
                      mul(kek[mask1],
                          mul(dp[sub][j][0], dp[nsub | (1 << i)][i][j + 1])));
            }
            dp[mask][i][j] = mul(dp[mask][i][j], p[i][j]);
          }
          dp[mask][i][j] =
              sum(dp[mask][i][j],
                  mul(dp[mask][i][j + 1],
                      (i == j || !(mask & (1 << j)) ? 1 : p[j][i])));
        }
      }
    }
  }
  int ans = 0;
  for (int t = 0; t < n; t++) {
    ans = sum(ans, dp[(1 << n) - 1][t][0]);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
