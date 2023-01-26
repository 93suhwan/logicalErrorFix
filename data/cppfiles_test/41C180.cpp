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
  map<string, vector<int>> dp;
  vector<string> ss = {"abc", "acb", "bac", "bca", "cab", "cba"};
  for (auto mask : ss) {
    dp[mask] = vector<int>(n);
    for (int i = 0; i < n; ++i) {
      dp[mask][i] = (i > 0 ? dp[mask][i - 1] : 0) + (s[i] != mask[i % 3]);
    }
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    --r;
    --l;
    int minn = INF32;
    for (auto mask : ss) {
      minn = min(minn, dp[mask][r] - (l > 0 ? dp[mask][l - 1] : 0));
    }
    cout << minn << endl;
  }
  return 0;
}
