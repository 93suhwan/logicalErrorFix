#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
const int INF = 0x3f3f3f3f;
int p[maxn];
int vis[maxn];
int b[maxn];
int r[maxn];
void solve() {
  int n, fl = 0, mi = n, ma = 1;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> p[i], b[i] = r[i] = 0;
  for (int i = 1; i <= n; i++) {
    char ch;
    cin >> ch;
    if (ch == 'B') {
      ma = max(ma, p[i]);
      if (p[i] < 1)
        fl = 1;
      else if (p[i] >= 1 && p[i] <= n)
        b[p[i]]++;
    } else {
      mi = min(mi, p[i]);
      if (p[i] > n)
        fl = 1;
      else if (p[i] >= 1 && p[i] <= n)
        r[p[i]]++;
    }
  }
  if (fl || ma < mi) {
    cout << "NO" << endl;
    return;
  }
  int f1 = 1, f2 = 1, ans1 = 0, ans2 = 0;
  for (int i = 1; i <= n; i++) {
    if (f1 == 1 && r[n - i + 1] == 0) ans1++;
    if (f1 == 1 && r[n - i + 1] > 1) ans1 -= (r[n - i + 1] - 1);
    if (ans1 < 0) f1 = 2;
    if (f2 == 1 && b[i] == 0) ans2++;
    if (f2 == 1 && b[i] > 1) ans2 -= (b[i] - 1);
    if (ans2 < 0) f2 = 2;
    if (f1 == 2 && f2 == 2) break;
  }
  if (f1 == 2 || f2 == 2)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
int main() {
  int __;
  cin >> __;
  while (__--) solve();
}
