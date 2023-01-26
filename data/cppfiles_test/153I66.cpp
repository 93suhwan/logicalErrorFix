#include <bits/stdc++.h>
using namespace std;
void err() { cout << endl; }
template <class T, class... Ts>
void err(T arg, Ts &...args) {
  cout << arg << ' ';
  err(args...);
}
const int N = 1 << 24;
const long long mod = 998244353;
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
long long rng(long long l, long long r) {
  uniform_int_distribution<long long> uni(l, r);
  return uni(mt);
}
string s[31];
int cnt[31][26];
long long g[N];
long long ans[N];
int ct[26];
long long qpow(long long a, long long b) {
  long long ret = 1;
  a %= mod;
  while (b) {
    if (b & 1) ret = ret * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return ret;
}
void run(int tCase) {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    for (char ch : s[i]) {
      cnt[i][ch - 'a']++;
    }
  }
  for (int f = 1; f < 1 << n; ++f) {
    for (int &j : ct) {
      j = 1e9;
    }
    for (int i = 0; i < n; ++i) {
      if (f >> i & 1) {
        for (int j = 0; j < 26; ++j) {
          ct[j] = min(ct[j], cnt[i][j]);
        }
      }
    }
    g[f] = 1;
    for (int j : ct) {
      g[f] = g[f] * (j + 1) % mod;
    }
  }
  long long sum = 0;
  for (int f = 1; f < 1 << n; ++f) {
    int b = __builtin_popcount(f) % 2;
    for (int i = 0; i < n; ++i) {
      if (f >> i & 1) {
        if (b) {
          ans[f] = (ans[f] + ans[f - (1 << i)] - g[f - (1 << i)] + mod) % mod;
        } else {
          ans[f] = (ans[f] + ans[f - (1 << i)] + g[f - (1 << i)]) % mod;
        }
      }
    }
    ans[f] = ans[f] * qpow(b - 1, mod - 2) % mod;
    if (b) {
      ans[f] = (ans[f] + g[f]) % mod;
    } else {
      ans[f] = (ans[f] - g[f] + mod) % mod;
    }
  }
  for (int f = 0; f < 1 << n; ++f) {
    long long k = 0;
    long long si = 0;
    for (int i = 0; i < n; ++i) {
      if (f >> i & 1) {
        k++;
        si += i + 1;
      }
    }
    ans[f] = ans[f] * k % mod * si % mod;
    sum ^= ans[f];
  }
  cout << sum << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  int T = 1;
  for (int t = 1; t <= T; ++t) {
    run(t);
  }
  return 0;
}
