#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long mod = 1e9 + 7;
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
int a[307], b[307], c[307];
unordered_map<int, int> mp;
void solve() {
  memset(c, 0, sizeof c);
  mp.clear();
  int n, m;
  cin >> n >> m;
  n *= m;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    mp[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    int j = mp[b[i]];
    for (int k = 1; k <= j; k++) ans += c[k];
    c[j] = 1;
    mp[b[i]]--;
  }
  cout << ans << "\n";
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
