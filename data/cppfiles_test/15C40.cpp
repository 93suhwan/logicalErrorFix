#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int rnd(int l, int r) {
  uniform_int_distribution<int> uid(l, r);
  return uid(rng);
}
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int N = 3e5 + 5;
inline long long pow_mod(long long x, long long n, const int MOD = ::MOD) {
  n %= (MOD - 1);
  long long res = 1;
  while (n) {
    if (n & 1) res = (res * x) % MOD;
    x = (x * x) % MOD;
    n >>= 1;
  }
  return res;
}
int n, m, k;
string *s;
bool marked[10 + 5][19 + 5];
inline bool go(int i, int j) {
  if (i < 0 || n <= i) return 0;
  if (j < 0 || m <= j) return 0;
  return (s[i][j] == '*');
}
inline void solve() {
  cin >> n >> m >> k;
  for (int i = 0; i < n + 5; i++)
    for (int j = 0; j < m + 5; j++) marked[i][j] = 0;
  s = new string[n];
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (s[i][j] == '*') {
        int delta = 1;
        while (go(i - delta, j - delta) && go(i - delta, j + delta)) delta++;
        if (delta > k) {
          for (int t = 0; t < delta; t++) {
            marked[i - t][j - t] = 1;
            marked[i - t][j + t] = 1;
          }
        }
      }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (s[i][j] == '*' && !marked[i][j]) {
        cout << "NO\n";
        return;
      }
  cout << "YES\n";
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
