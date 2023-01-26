#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long mod = 1e9 + 7;
const int pp = 6e5 + 1;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
int sum[MAXN];
set<int> v[MAXN * 5];
void solve() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    int f = 1;
    if (s[i] == '-') f *= -1;
    if ((i + 1) % 2 == 0) f *= -1;
    sum[i + 1] = sum[i] + f;
  }
  for (int i = 1; i <= n; i++) {
    v[sum[i] + sum[i - 1] + pp].insert(i);
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (sum[r] - sum[l - 1] == 0) {
      cout << 0 << "\n";
      continue;
    }
    if ((r - l + 1) % 2 == 0) {
      cout << 2 << "\n";
      cout << r-- << " ";
    } else {
      cout << 1 << "\n";
    }
    int p = sum[r] + sum[l - 1] + pp;
    auto it = v[p].lower_bound(l);
    cout << (*it) << "\n";
  }
  for (int i = 1; i <= n; i++) v[sum[i] + sum[i - 1] + pp].clear();
  for (int i = 0; i <= n; i++) sum[i] = 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
