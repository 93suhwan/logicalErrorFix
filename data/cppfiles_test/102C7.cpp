#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long n, p[50], pw[21], k, BS, Val;
vector<string> AP[11];
map<long long, string> mp1, mp2;
inline long long HA(string &S, long long l, long long r) {
  long long res = 0;
  for (long long i = 0; i <= (long long)S.size() - 1; ++i)
    (res += (i + l) * pw[S[i] - 64] % mod) %= mod;
  return res;
}
inline void work(long long N, long long n) {
  AP[0].clear();
  string s0;
  s0 += ((1 << N - 1) + 65);
  AP[0].push_back(s0);
  for (long long i = 1; i <= n; ++i) {
    AP[i].clear();
    for (auto x : AP[i - 1])
      for (auto y : AP[i - 1]) {
        string NS = x + y;
        for (long long j = 0; j <= (long long)NS.size() - 1; ++j)
          if (NS[j] == (1 << N - i) + 65) {
            if (i == N)
              NS[j] = 65;
            else
              NS[j] = (1 << N - i - 1) + 65;
            AP[i].push_back(NS);
            NS[j] = (1 << N - i) + 65;
          }
      }
  }
  for (auto x : AP[n]) {
    long long X = (1 << n);
    mp1[HA(x, 1, X)] = x, mp2[HA(x, X + 1, X << 1)] = x;
    for (long long i = 0; i <= (long long)x.size() - 1; ++i)
      if (x[i] == 66) {
        x[i] = 65;
        break;
      }
    mp1[HA(x, 1, X)] = x, mp2[HA(x, X + 1, X << 1)] = x;
  }
}
inline void solve() {
  for (auto p : mp1) {
    long long Q = (Val + mod - p.first) % mod;
    if (mp2.find(Q) != mp2.end()) {
      string ans = p.second + mp2[Q];
      for (long long i = 0; i <= (long long)ans.size() - 1; ++i)
        printf("%d ", ans[i] - 'A' + 1);
      exit(0);
    }
  }
  puts("-1");
}
signed main() {
  cin >> k >> BS >> Val;
  pw[0] = 1;
  for (long long i = 1; i <= 20; ++i) pw[i] = pw[i - 1] * BS % mod;
  work(k, k - 1);
  solve();
}
