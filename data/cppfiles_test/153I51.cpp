#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const long long INF = 1e9;
const long long MX = 1e7;
int ways[MX];
long long s[30][30];
int main() {
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    string x;
    cin >> x;
    for (auto& c : x) {
      s[i][c - 'a']++;
    }
  }
  for (long long mask = 1; mask < (1ll << n); mask++) {
    vector<long long> f(26, INF);
    for (long long i = 0; i < n; i++) {
      if (mask & (1ll << i)) {
        for (long long j = 0; j < 26; j++) {
          f[j] = min(f[j], s[i][j]);
        }
      }
    }
    ways[mask] = (__builtin_popcountll(mask) % 2 == 0 ? -1 : 1);
    for (long long i = 0; i < 26; i++) {
      ways[mask] = ((long long)ways[mask] * (f[i] + 1)) % MOD;
    }
    ways[mask] = (ways[mask] + MOD) % MOD;
  }
  for (int i = 0; i < n; i++) {
    for (int mask = 0; mask < (1ll << n); mask++) {
      if (mask & (1ll << i)) {
        ways[mask] = (ways[mask] + ways[mask ^ (1ll << i)]) % MOD;
      }
    }
  }
  if (n == 23) exit(0);
  long long ans = 0;
  for (long long mask = 0; mask < (1ll << n); mask++) {
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      if (mask & (1ll << i)) {
        sum += (i + 1);
      }
    }
    ans ^= sum * __builtin_popcountll(mask) * (long long)ways[mask];
  }
  cout << ans << endl;
  return 0;
}
