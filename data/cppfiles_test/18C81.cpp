#include <bits/stdc++.h>
using namespace std;
template <typename... T>
void pn(T... args) {
  ((cout << args << " "), ...);
  cout << "\n";
}
template <typename... T>
void ps(T... args) {
  ((cout << args << " "), ...);
  cout << "";
}
long long power(long long a, long long b, long long P = 1000000007) {
  long long res = 1;
  for (; b; b >>= 1, a = 1ll * a * a % P)
    if (b & 1) res = 1ll * res * a % P;
  return res;
}
void solve() {
  long long n, d;
  cin >> n >> d;
  long long arr[n];
  vector<vector<long long>> let(n);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  vector<bool> vis(n, false);
  for (long long i = 0; i < n; i++) {
    if (vis[i]) continue;
    long long j = i;
    while (!vis[j]) {
      vis[j] = true;
      let[i].push_back(arr[j]);
      j = (j - d + n) % n;
    }
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    long long j = 0;
    long long sz = let[i].size();
    if (sz == 0) continue;
    while (j < sz && let[i][j] == 1) let[i].push_back(1), j++;
    if (j == sz) {
      cout << -1 << "\n";
      return;
    }
    while (j < let[i].size()) {
      long long cnt = 0;
      if (let[i][j] == 1) {
        while (j < let[i].size() && let[i][j] == 1) cnt++, j++;
      } else
        j++;
      ans = max(ans, cnt);
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
