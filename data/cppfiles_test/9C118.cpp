#include <bits/stdc++.h>
using namespace std;
template <typename T>
void umax(T &a, const T b) {
  if (a < b) a = b;
}
template <typename T>
void umin(T &a, const T b) {
  if (a > b) a = b;
}
const int N = 1005;
const int M = 1005;
const int K = 1e5 + 5;
int g[N][M];
int c[K];
int n, m, k;
int solve(int pos) {
  for (int i = 0; i < n; ++i) {
    int &cur = g[i][pos];
    if (cur == 1) {
      pos++;
      i--;
    } else if (cur == 3) {
      pos--;
      i--;
    }
    cur = 2;
  }
  return pos + 1;
}
void darkkcyan_orz() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> g[i][j];
    }
  }
  for (int i = 0; i < k; ++i) {
    cin >> c[i];
  }
  for (int i = 0; i < k; ++i) {
    cout << solve(c[i] - 1) << ' ';
  }
  cout << ("") << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.exceptions(cin.failbit);
  cin.tie(0);
  int T = 1;
  for (int tc = 0; tc < T; ++tc) {
    darkkcyan_orz();
  }
}
