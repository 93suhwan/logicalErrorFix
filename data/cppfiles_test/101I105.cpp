#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int p[maxn];
int v[maxn];
int r[maxn];
int b[maxn];
void solve() {
  int n, ma, mi, fl = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> p[i], r[i] = b[i] = v[i] = 0;
  ma = 1, mi = n;
  for (int i = 1; i <= n; i++) {
    char ch;
    cin >> ch;
    if (ch == 'R')
      v[i] = 1;
    else if (ch == 'B')
      v[i] = -1;
    if (v[i] == 1)
      mi = min(mi, p[i]);
    else if (v[i] == -1)
      ma = max(ma, p[i]);
    if (v[i] == 1 && p[i] > n) fl = 1;
    if (v[i] == -1 && p[i] < 1) fl = 1;
    if (v[i] == 1 && p[i] <= n && p[i] >= 1) r[p[i]]++;
    if (v[i] == -1 && p[i] <= n && p[i] >= 1) b[p[i]]++;
  }
  if (ma < mi) fl = 1;
  int rr = 0, bb = 0;
  for (int i = 1; i <= n; i++) {
    rr += r[n - i + 1];
    bb += b[i];
    if (rr > i || bb > i) fl = 1;
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
