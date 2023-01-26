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
        f[s] = f[s] - f[s ^ (1 << d)] % MOD;
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
  vector<ll> f(1 << n, 1);
  vector<array<int, 26>> str_cnt(1 << n, array<int, 26>{});
  f[0] = 0;
  for (int s = (1); s < int(1 << n); ++s) {
    int at = 0;
    for (int i = (0); i < int(n); ++i)
      if (s & (1 << i)) {
        at = i;
        break;
      }
    if ((s & (s - 1)) == 0) {
      str_cnt[s] = char_cnt[at];
    } else {
      for (int ch = (0); ch < int(26); ++ch) {
        str_cnt[s][ch] = min(str_cnt[s & (s - 1)][ch], char_cnt[at][ch]);
      }
    }
    for (int ch = (0); ch < int(26); ++ch) {
      if (str_cnt[s][ch] > 0) {
        f[s] = f[s] * (str_cnt[s][ch] + 1) % MOD;
      }
    }
  }
  mobius_transform(n, f);
  ll ans = 0;
  for (int s = (0); s < int(1 << n); ++s) {
    ans ^= abs(f[s]) * kIndexSum(s);
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
