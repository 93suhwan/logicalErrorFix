#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
const int maxm = 1e9;
int n, m;
int a[maxn], b[maxn], r[maxn];
void init() {}
string s;
bool cmp(int a, int b) { return a > b; }
inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cin >> s;
  s = " " + s;
  int cnt1 = 0, cnt2 = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'R')
      r[++cnt1] = a[i];
    else
      b[++cnt2] = a[i];
  }
  sort(b + 1, b + 1 + cnt2);
  sort(r + 1, r + 1 + cnt1, cmp);
  for (int i = 1; i <= cnt2; i++) {
    if (b[i] < i) {
      cout << "NO" << '\n';
      return;
    }
  }
  for (int i = 1; i <= cnt1; i++) {
    if (r[i] > n - i + 1) {
      cout << "NO" << '\n';
      return;
    }
  }
  cout << "YES" << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  clock_t c1 = clock();
  int __ = 1;
  cin >> __;
  while (__--) {
    solve();
  }
  return 0;
}
