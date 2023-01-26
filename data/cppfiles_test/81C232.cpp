#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const int M = 2e5 + 5;
const int mod = 1e9 + 7;
int _, n, k, m;
char s[N], t[N];
int a[N];
void solve() {
  cin >> n >> m >> s + 1;
  for (int i = int(1); i <= int(n); i++) {
    if (i & 1) {
      if (s[i] == '+')
        a[i] = 1;
      else
        a[i] = -1;
    } else {
      if (s[i] == '+')
        a[i] = -1;
      else
        a[i] = 1;
    }
  }
  for (int i = int(1); i <= int(n); i++) a[i] += a[i - 1];
  for (int i = int(1); i <= int(m); i++) {
    int l, r;
    cin >> l >> r;
    int p = a[r] - a[l - 1];
    if (p == 0)
      cout << 0 << endl;
    else if (p & 1)
      cout << 1 << endl;
    else
      cout << 2 << endl;
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  bool multi = 1;
  if (multi)
    cin >> _;
  else
    _ = 1;
  while (_--) {
    solve();
  }
}
