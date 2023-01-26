#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T cei(T x, T y) {
  T t = (x + y - 1) / y;
  return t;
}
template <typename T>
inline T power(T base, T powerRaised) {
  if (powerRaised != 0)
    return (base * power(base, powerRaised - 1));
  else
    return 1;
}
template <typename T>
inline T gcd(T a, T b) {
  while (b) {
    b ^= a ^= b ^= a %= b;
  }
  return a;
}
template <typename T>
inline T lcm(T x, T y) {
  return x * y / gcd(x, y);
}
template <typename T>
inline T findLessPower(T base, T n) {
  if (n == 1) {
    return 0;
  }
  T temp = log(n) / log(base);
  if (power(base, temp) == n) {
    return temp - 1;
  } else {
    return temp;
  }
}
const int maxn = 1e5 + 5;
const int MOD = 998244353;
const int INF = 1e9;
const char min_char = 'a';
const int alphabet = 26;
template <typename T_out, typename T_in>
vector<T_out> mobius_transform(int n, const vector<T_in> &values) {
  assert(int(values.size()) == 1 << n);
  vector<T_out> dp(values.begin(), values.end());
  for (int i = 0; i < n; i++)
    for (int base = 0; base < 1 << n; base += 1 << (i + 1))
      for (int mask = base; mask < base + (1 << i); mask++)
        dp[mask + (1 << i)] -= dp[mask];
  return dp;
}
void solve() {
  int n;
  cin >> n;
  vector<vector<int> > S(n, vector<int>(26, 0));
  for (int i = 0; i < n; ++i) {
    string str;
    cin >> str;
    for (char c : str) {
      S[i][c - min_char]++;
    }
  }
  vector<int> dp(1 << n, 0);
  for (int mask = 1; mask < 1 << n; mask++) {
    vector<int> mins(26, INF);
    for (int i = 0; i < n; i++) {
      if (mask >> i & 1) {
        for (int c = 0; c < 26; c++) {
          mins[c] = min(mins[c], S[i][c]);
        }
      }
    }
    dp[mask] = 1;
    for (auto c : mins) {
      dp[mask] *= c + 1;
      dp[mask] %= MOD;
    }
  }
  dp = mobius_transform<int>(n, dp);
  for (int i = 1; i < 1 << n; i++) {
    if (__builtin_popcount(i) % 2 == 0) {
      dp[i] = -dp[i];
    }
  }
  int ans = 0;
  for (int mask = 1; mask < 1 << n; mask++) {
    int k = __builtin_popcount(mask);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (1 << i & mask) {
        sum += i + 1;
      }
    }
    ans ^= sum * k * dp[mask];
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
