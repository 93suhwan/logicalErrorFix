#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
void solve() {
  int T;
  cin >> T;
  while (T--) {
    int64_t N, D;
    cin >> N >> D;
    auto m = [&](int i, int k = 1) -> int { return (i + N * k - D * k) % N; };
    vector<int> A(N);
    for (auto &x : A) cin >> x;
    const int H = ceil(log2(N));
    vector<vector<bool>> shift(H + 1, vector<bool>(N));
    for (int i = 0; i < N; ++i) {
      shift[0][i] = A[i] & A[m(i)];
    }
    int cur = 1;
    for (int i = 1; i <= H; ++i) {
      for (int j = 0; j < N; ++j) {
        shift[i][j] = shift[i - 1][j] & shift[i - 1][m(j, cur)];
      }
      cur <<= 1;
    }
    auto ok = [&](int x, int i) -> bool {
      int res = A[i];
      int cur = i;
      int k = 1;
      for (int j = 0; j <= H && res; ++j) {
        if (x & 1) {
          res &= shift[j][cur];
          cur = m(cur, k);
        }
        x >>= 1;
        k <<= 1;
      }
      return !res;
    };
    int ans = 0;
    for (int i = 0; i < N && ans <= N; ++i) {
      int l = ans - 1;
      int r = N + 1;
      while (r - l > 1) {
        int mid = l + (r - l) / 2;
        if (ok(mid, i)) {
          r = mid;
        } else {
          l = mid;
        }
      }
      ans = max(ans, r);
    }
    if (ans == N + 1) {
      cout << "-1\n";
    } else {
      cout << ans << "\n";
    }
  }
}
