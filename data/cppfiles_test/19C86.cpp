#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int M = 10005;
bool dp[M][2005];
short int vis[M][2005], cur;
int a[M], len, n;
int dpcall(int id, int pos) {
  if (pos > len || pos < 0) return 0;
  if (id == n) return 1;
  bool &ret = dp[id][pos];
  if (vis[id][pos] == cur) return ret;
  vis[id][pos] = cur;
  ret = dpcall(id + 1, pos + a[id]) || dpcall(id + 1, pos - a[id]);
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, tt = 1;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int lw = 0, hi = 2001, mid, ans = 2000;
    while (lw <= hi) {
      mid = (lw + hi) / 2;
      len = mid;
      cur++;
      bool flg = 0;
      for (int i = 0; i <= len; i++) {
        flg |= dpcall(0, i);
        if (flg) break;
      }
      if (flg) {
        ans = mid;
        hi = mid - 1;
      } else {
        lw = mid + 1;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
