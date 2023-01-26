#include <bits/stdc++.h>
using namespace std;
void io(string in = "", string out = "", string err = "") {
  if (fopen(in.c_str(), "r")) {
    freopen(in.c_str(), "r", stdin);
    freopen(out.c_str(), "w", stdout);
  }
}
void conv();
int main() {
  io(""
     ".inp",
     ""
     ".out");
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int Q = 1;
  cin >> Q;
  while (Q--) {
    conv();
  }
  return 0;
}
template <typename T>
bool ckmin(T& a, T b) {
  return a > b ? a = b, 1 : 0;
}
const int N = 1000010;
const int INF = 0x3f3f3f3f;
int n, a[N], dp[N][2][2];
pair<int, int> trc[N][2][2];
void conv() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  memset(dp, INF, 4 * n * sizeof ***dp);
  dp[0][0][0] = dp[0][0][1] = -INF;
  for (int i = 0; i + 1 < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        int y = dp[i][j][k];
        if (y == INF) continue;
        int x = k ? -a[i] : a[i];
        if (j) swap(x, y);
        for (int nk = 0; nk < 2; ++nk) {
          int z = nk ? -a[i + 1] : a[i + 1];
          if (z > x) {
            if (ckmin(dp[i + 1][0][nk], y)) {
              trc[i + 1][0][nk] = make_pair(j, k);
            }
          } else if (z > y) {
            if (ckmin(dp[i + 1][1][nk], x)) {
              trc[i + 1][1][nk] = make_pair(j, k);
            }
          }
        }
      }
    }
  }
  int t = -1, sgn = -1;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      if (dp[n - 1][i][j] < INF) {
        t = i;
        sgn = j;
      }
    }
  }
  if (t < 0) {
    cout << "NO" << '\n';
  } else {
    for (int i = n - 1; i >= 0; --i) {
      if (sgn) a[i] = -a[i];
      tie(t, sgn) = trc[i][t][sgn];
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
    cout << '\n';
  }
}
