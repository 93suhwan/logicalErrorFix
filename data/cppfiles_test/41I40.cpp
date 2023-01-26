#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
constexpr long long INF = 200000000000000001LL;
constexpr int INF32 = 2100000001;
size_t seed42 = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 rng(seed42);
std::uniform_int_distribution<int> unidistrib;
int randint() { return unidistrib(rng); }
using namespace std;
unsigned long long modulo = 998244353;
int modulo32 = 998244353;
unsigned long long poww(unsigned long long x, unsigned long long n) {
  if (n == 0) return 1;
  unsigned long long answ = poww(x, n / 2);
  answ = (answ * answ) % modulo;
  if (n % 2) answ = (answ * x) % modulo;
  return answ;
}
pair<int, int> operator+(const pair<int, int>& lhs, pair<int, int>& rhs) {
  return {lhs.first + rhs.first, lhs.second + rhs.second};
}
template <class T>
ostream& operator<<(ostream& lhs, pair<T, T>& rhs) {
  return (lhs << rhs.first << ":" << rhs.second);
}
struct Node {
  Node(int p, int a, int c) : p(p), a(a), c(c), p2(1, p) {}
  int p;
  int a;
  int c;
  vector<int> p2;
};
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n, m, t;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<vector<vector<int>>> dp(n + 2,
                                 vector<vector<int>>(3, vector<int>(3, INF32)));
  for (int j = 0; j < 3; ++j) {
    for (int k = 0; k < 3; ++k) {
      dp[0][j][k] = 0;
      dp[1][j][k] = 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        if (k == j) continue;
        int minn = INF32;
        for (int l = 0; l < 3; ++l) {
          if (l != j) minn = min(minn, dp[i + 2 - 1][k][j]);
        }
        dp[i + 2][j][k] = minn + (s[i] - 'a' == j ? 0 : 1);
      }
    }
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    --l;
    --r;
    int minn = INF32;
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        minn = min(minn, dp[r + 2][j][k]);
      }
    }
    if (l == 0) {
      cout << minn << "\n";
      continue;
    }
    if (l == r) {
      cout << 0 << "\n";
      continue;
    }
    int maxx = INF32;
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        if (dp[l + 2][j][k] != INF32) maxx = min(maxx, dp[l + 2][j][k]);
      }
    }
    cout << minn - maxx << "\n";
  }
  return 0;
}
