#include <bits/stdc++.h>
template <typename T>
void print(T x) {
  std::cout << x << '\n';
}
template <typename T, typename TT>
void print(T x, TT y) {
  std::cout << x << ' ' << y << '\n';
}
template <typename T, typename TT>
void print(std::pair<T, TT> x) {
  std::cout << x.first << ' ' << x.second << '\n';
}
template <typename T>
void print(std::vector<T> v) {
  for (auto z : v) std::cout << z << ' ';
  std::cout << '\n';
}
template <typename T>
void print(T x[], int n) {
  for (int i = 0; i++ < n;) std::cout << *x++ << (i < n ? ' ' : '\n');
}
using namespace std;
const int N = 105;
int n, m, k, dp[N][N * N];
int rfs(int row, int col, int p) {
  if (p == 0) {
    if ((col - 1 == m or row % 2 == 0) and (n - row) % 2 == 0) return 1;
    return 0;
  }
  if (col > m or p < 0) return 0;
  auto &ret = dp[col][p];
  if (ret != -1) return ret;
  ret = 0;
  for (int i = 1; i <= n; i++) {
    if ((n - i) % 2 == 0) {
      ret |= rfs(i, col + 2, p - i);
    }
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n >> m >> k;
    memset(dp, -1, sizeof dp);
    int f = rfs(0, 1, k);
    f ? cout << "YES\n" : cout << "NO\n";
  }
  return 0;
}
