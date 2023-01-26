#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
const int N = 400 + 10;
int a[N][N], pref[N][N], val[N];
int get(int l, int r, int u, int d) {
  if (l > r || u > d) return 0;
  return pref[d][r] - pref[d][l - 1] - pref[u - 1][r] + pref[u - 1][l - 1];
}
int black(int l, int r, int u, int d) {
  return (r - l + 1) * (d - u + 1) - get(l, r, u, d);
}
int white(int l, int r, int u, int d) { return get(l, r, u, d); }
int solve(int n, int m) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pref[i][j] =
          a[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
    }
  }
  int ans = n * m;
  for (int i = 1; i <= m; i++) {
    for (int j = i + 3; j <= m; j++) {
      int mn = 1e9;
      for (int k = 1; k <= n; k++) {
        int cur = black(i + 1, j - 1, k, k);
        cur += black(i, i, 1, k - 1) + black(j, j, 1, k - 1);
        cur += white(i + 1, j - 1, 1, k - 1);
        if (k >= 5) {
          ans = min(ans, cur + mn);
        }
        val[k] = -black(i, i, 1, k) - black(j, j, 1, k) -
                 white(i + 1, j - 1, 1, k) + black(i + 1, j - 1, k, k);
        if (k >= 4) {
          mn = min(mn, val[k - 3]);
        }
      }
    }
  }
  return ans;
}
int slow(int n, int m) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pref[i][j] =
          a[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
    }
  }
  int ans = n * m;
  for (int l = 1; l <= m; l++) {
    for (int r = l + 3; r <= m; r++) {
      for (int u = 1; u <= n; u++) {
        for (int d = u + 4; d <= n; d++) {
          int cur = black(l + 1, r - 1, u, u);
          cur += black(l + 1, r - 1, d, d);
          cur += black(l, l, u + 1, d - 1);
          cur += black(r, r, u + 1, d - 1);
          cur += white(l + 1, r - 1, u + 1, d - 1);
          ans = min(ans, cur);
          if (cur == 5) {
            cout << l << " " << r << " " << u << " " << d << "\n";
          }
        }
      }
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        char ch;
        cin >> ch;
        a[i][j] = ch == '1';
      }
    }
    cout << solve(n, m) << "\n";
  }
  return 0;
}
