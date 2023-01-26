#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int p[maxn];
int v[maxn];
int b[maxn];
int r[maxn];
void solve() {
  int n;
  cin >> n;
  memset(r, 0, sizeof(r));
  memset(b, 0, sizeof(b));
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 1; i <= n; i++) {
    char ch;
    cin >> ch;
    if (ch == 'R')
      v[i] = 1;
    else if (ch == 'B')
      v[i] = -1;
  }
  int fl = 0, ans;
  int ma = 1, mi = n;
  for (int i = 1; i <= n; i++)
    if (v[i] == 1)
      mi = min(mi, p[i]);
    else if (v[i] == -1)
      ma = max(ma, p[i]);
  if (mi > ma) {
    cout << "NO" << endl;
    return;
  }
  for (int i = 1; i <= n; i++)
    if (v[i] == 1) {
      if (p[i] > n)
        fl = 1;
      else if (p[i] >= n && p[i] >= 1)
        r[p[i]]++;
    } else if (v[i] == -1) {
      if (p[i] < 1)
        fl = 1;
      else if (p[i] <= n && p[i] >= 1)
        b[p[i]]++;
    }
  ans = 0;
  for (int i = n; i >= 1; i--) {
    if (r[i] == 0)
      ans++;
    else if (r[i] > 1)
      ans -= (r[i] - 1);
    if (ans < 0) fl = 1;
  }
  ans = 0;
  for (int i = 1; i <= n; i++) {
    if (b[i] == 0)
      ans++;
    else if (b[i] > 1)
      ans -= (b[i] - 1);
    if (ans < 0) fl = 1;
  }
  if (fl == 1)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
int main() {
  int __;
  cin >> __;
  while (__--) solve();
}
