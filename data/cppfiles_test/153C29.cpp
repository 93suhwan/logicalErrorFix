#include <bits/stdc++.h>
template <typename T>
inline T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const ll MOD = 998244353;
template <typename T>
void mobius_transform(int n, vector<T>& f) {
  for (int d = 0; d < n; ++d) {
    for (int s = 0; s < (1 << n); ++s) {
      if (s & (1 << d)) {
        f[s] = (f[s] - f[s ^ (1 << d)] + MOD) % MOD;
      }
    }
  }
}
void run_test_case() {
  int n;
  cin >> n;
  vector<string> str(n);
  vector<array<int, 26>> char_cnt(n, array<int, 26>{});
  for (int i = (0); i < int(n); ++i) {
    cin >> str[i];
    for (int j = (0); j < int(int(str[i].size())); ++j) {
      char_cnt[i][str[i][j] - 'a'] += 1;
    }
  }
  auto countBit = [](int s) -> int {
    int res = 0;
    while (s) {
      res += s & 1;
      s /= 2;
    }
    return res;
  };
  auto kIndexSum = [&](int s) -> ll {
    ll sum = 0;
    ll bit = 0;
    ll cnt = 0;
    while (s) {
      if (s & 1) {
        sum += bit + 1;
        cnt++;
      }
      s /= 2;
      ++bit;
    }
    return cnt * sum;
  };
  vector<ll> f(1 << n, 0);
  int mcnt[26];
  for (int s = (1); s < int(1 << n); ++s) {
    memset(mcnt, -1, sizeof(mcnt));
    for (int i = (0); i < int(n); ++i) {
      if (s & (1 << i)) {
        for (int ch = (0); ch < int(26); ++ch) {
          if (mcnt[ch] == -1) {
            mcnt[ch] = char_cnt[i][ch];
          } else {
            mcnt[ch] = min(mcnt[ch], char_cnt[i][ch]);
          }
        }
      }
    }
    f[s] = 1;
    for (int ch = (0); ch < int(26); ++ch) {
      if (mcnt[ch] > 0) {
        f[s] = f[s] * (mcnt[ch] + 1) % MOD;
      }
    }
  }
  mobius_transform(n, f);
  ll ans = 0;
  ;
  for (int s = (0); s < int(1 << n); ++s) {
    int bits = countBit(s);
    if (bits % 2 == 0) {
      f[s] = (-f[s] + MOD) % MOD;
    }
    ans ^= f[s] * kIndexSum(s);
  }
  cout << ans << endl;
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int t = 1;
  bool read_t = false;
  if (read_t) {
    cin >> t;
  }
  while (t--) {
    run_test_case();
  }
  return 0;
}
