#include <bits/stdc++.h>
using namespace std;
int n, k, t, p[100010], minn, d, maxn;
int dig(int x) {
  int ans = 0;
  while (x) {
    ans++;
    p[ans] = x % 10;
    maxn = max(maxn, p[ans]);
    x = x / 10;
  }
  return ans;
}
void dfs(int id, int x, int sum) {
  if (id == 1) {
    if (sum >= n) minn = min(minn, sum);
    return;
  }
  dfs(id - 1, x, sum * 10 + x);
  dfs(id - 1, x, sum * 10 + p[d]);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    minn = 0x3f3f3f3f;
    maxn = 0;
    d = dig(n);
    if (k == 1) {
      int s;
      for (int i = 1; i <= 9; i++) {
        s = 0;
        for (int j = 1; j <= d; j++) {
          s = s * 10 + i;
        }
        if (s >= n) minn = min(minn, s);
      }
      cout << minn << "\n";
      continue;
    }
    for (int i = 0; i <= 9; i++) dfs(d, i, p[d]);
    cout << minn << "\n";
  }
}
