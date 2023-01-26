#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long INF = 1e18;
long long my_pow(long long n, long long k) {
  long long ans = 1;
  while (k) {
    if (k & 1) {
      (ans *= n) %= mod;
    }
    (n *= n) %= mod;
    k /= 2;
  }
  return ans;
}
void precompute() {}
void test_case() {
  long long k;
  cin >> k;
  vector<vector<long long>> dp(k + 1, vector<long long>(6));
  for (long long i = 0; i < 6; i++) {
    dp[1][i] = 1;
  }
  auto get = [&](string s) {
    if (s[0] == 'w') return 0;
    if (s[0] == 'y') return 1;
    if (s[0] == 'g') return 2;
    if (s[0] == 'b') return 3;
    if (s[0] == 'r') return 4;
    if (s[0] == 'o') return 5;
  };
  long long n;
  cin >> n;
  map<long long, long long> mp;
  set<long long> unlucky;
  for (long long i = 0; i < n; i++) {
    long long v;
    string s;
    cin >> v >> s;
    mp[v] = get(s);
    while (v) {
      unlucky.insert(v);
      v /= 2;
    }
  }
  vector<vector<long long>> bad = {
      {1, 1, 0, 0, 0, 0}, {1, 1, 0, 0, 0, 0}, {0, 0, 1, 1, 0, 0},
      {0, 0, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 1}, {0, 0, 0, 0, 1, 1},
  };
  for (long long i = 2; i <= k; i++) {
    for (long long c = 0; c < 6; c++) {
      for (long long c1 = 0; c1 < 6; c1++) {
        for (long long c2 = 0; c2 < 6; c2++) {
          if (bad[c][c1] == 0 && bad[c][c2] == 0) {
            dp[i][c] += (dp[i - 1][c1] * dp[i - 1][c2]) % mod;
            dp[i][c] %= mod;
          }
        }
      }
    }
  }
  function<vector<long long>(long long, long long)> dfs = [&](long long u,
                                                              long long h) {
    if (!unlucky.count(u)) {
      return dp[h];
    } else {
      if (mp.count(u)) {
        long long col = mp[u];
        if (h == 1) {
          vector<long long> ret(6);
          ret[col] = 1;
          return ret;
        }
        vector<long long> left = dfs(2 * u, h - 1);
        vector<long long> right = dfs(2 * u + 1, h - 1);
        vector<long long> ret(6);
        for (long long c1 = 0; c1 < 6; c1++) {
          for (long long c2 = 0; c2 < 6; c2++) {
            if (bad[col][c1] == 0 && bad[col][c2] == 0) {
              ret[col] += (left[c1] * right[c2]) % mod;
              ret[col] %= mod;
            }
          }
        }
        return ret;
      } else {
        if (h == 1) {
        }
        vector<long long> left = dfs(2 * u, h - 1);
        vector<long long> right = dfs(2 * u + 1, h - 1);
        vector<long long> ret(6);
        for (long long c = 0; c < 6; c++) {
          for (long long c1 = 0; c1 < 6; c1++) {
            for (long long c2 = 0; c2 < 6; c2++) {
              if (bad[c][c1] == 0 && bad[c][c2] == 0) {
                ret[c] += (left[c1] * right[c2]) % mod;
                ret[c] %= mod;
              }
            }
          }
        }
        return ret;
      }
    }
  };
  vector<long long> ans = dfs(1, k);
  long long ret = 0;
  for (long long i = 0; i < 6; i++) {
    ret += ans[i];
    ret %= mod;
  }
  cout << ret << endl;
}
int main() {
  srand(time(0));
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(15) << fixed;
  precompute();
  long long T = 1;
  for (long long TT = 1; TT <= T; TT++) {
    test_case();
  }
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
}
