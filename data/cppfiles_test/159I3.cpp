#include <bits/stdc++.h>
using namespace std;
int n;
bool vis[1000003], ans[1000003], ok;
void solve() {
  for (int i = 2; i <= n; i += 2) {
    vis[i] ^= 1;
    if (i != 2) vis[i >> 1] ^= 1;
    ok ^= 1;
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i]) ans[i] ^= 1, ans[i - 1] ^= 1;
  }
  if (ok) {
    if (ans[2] == 0) {
      ans[2] = 1;
      ok = 0;
    }
    for (int i = 2; i <= n && ok; i++)
      if (!ans[i])
        for (int j = i + 1; j <= n && j <= i + 5 && ok; j++) {
          long long res = 1;
          for (int k = i + 1; k <= j; k++) res *= k;
          if (res % 2) continue;
          res >>= 1;
          if (res == int(sqrt(res)) * int(sqrt(res)))
            if (ans[j - 1] == 1) {
              ans[j - 1] = 0;
              ans[i] = 1;
              ok = 0;
            }
        }
    for (int i = 2; i <= n && ok; i++)
      if (!ans[i])
        for (int j = i - 1; j >= 1 && j >= i - 5 && ok; j--) {
          long long res = 1;
          for (int k = j + 1; k <= i; k++) res *= k;
          if (res % 2) continue;
          res >>= 1;
          if (res == int(sqrt(res)) * int(sqrt(res)))
            if (ans[j] == 1) {
              ans[j] = 0;
              ans[i] = 1;
              ok = 0;
            }
        }
    if (ok) ans[2] ^= 1;
  }
  ans[1] = 1;
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (ans[i]) cnt++;
  cout << cnt << endl;
  for (int i = 1; i <= n; i++)
    if (ans[i]) printf("%d ", i);
}
int main() {
  cin >> n;
  solve();
}
