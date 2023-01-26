#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int md = 1e9 + 7;
const int maxn = 2e5 + 5;
const int maxm = 1e9;
int n, m;
int a[maxn], b[maxn], c[maxn];
string s;
void init() {}
inline void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0')
      b[i] = ++cnt;
    else
      b[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') continue;
    b[i] = ++cnt;
  }
  for (int i = 0; i < n; i++) cout << b[i] << " ";
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int __ = 1;
  cin >> __;
  while (__--) solve();
  return 0;
}
