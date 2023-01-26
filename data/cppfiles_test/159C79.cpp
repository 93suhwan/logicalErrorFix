#include <bits/stdc++.h>
using namespace std;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1000006, m = 60;
int n;
int u[N];
long long h[N];
long long p[N];
bool solv(int n) {
  for (int i = 1; i <= n; ++i) u[i] = h[i] = p[i] = 0;
  u[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (u[i]) continue;
    for (int j = i; j <= n; j += i) {
      if (!u[j]) u[j] = i;
    }
  }
  for (int i = 1; i <= n; ++i) h[i] = rnd();
  for (int i = 1; i <= n; ++i) {
    int x = i;
    while (x > 1) {
      p[i] ^= h[u[x]];
      x /= u[x];
    }
  }
  for (int i = 1; i <= n; ++i) p[i] ^= p[i - 1];
  long long hh = 0;
  for (int i = 1; i <= n; ++i) hh ^= p[i];
  if (hh == 0) {
    cout << n << "\n";
    for (int i = 1; i <= n; ++i) cout << i << ' ';
    cout << "\n";
    return true;
  }
  for (int i = 1; i <= n; ++i) {
    if (p[i] == hh) {
      cout << n - 1 << "\n";
      for (int j = 1; j <= n; ++j) {
        if (i == j) continue;
        cout << j << ' ';
      }
      cout << "\n";
      return true;
    }
  }
  unordered_map<long long, int> mp;
  for (int i = 1; i <= n; ++i) mp[p[i]] = i;
  for (int i = 1; i <= n; ++i) {
    if (mp.find((hh ^ p[i])) != mp.end()) {
      cout << n - 2 << "\n";
      for (int j = 1; j <= n; ++j) {
        if (j == i || j == mp[(hh ^ p[i])]) continue;
        cout << j << ' ';
      }
      cout << "\n";
      return true;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int tt = 1;
  while (tt--) {
    int n;
    cin >> n;
    if (!solv(n)) solv(n - 1);
  }
  return 0;
}
