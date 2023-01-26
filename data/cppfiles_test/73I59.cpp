#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long inv(long long k) {
  long long p = mod - 2;
  long long ans = 1;
  for (; p; p >>= 1) {
    if (p & 1) ans = (ans * k) % mod;
    k = (k * k) % mod;
  }
  return ans;
}
long long power(long long k, long long p) {
  long long ans = 1;
  for (; p; p >>= 1) {
    if (p & 1) ans = (ans * k) % mod;
    k = (k * k) % mod;
  }
  return ans;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  long long level = 0;
  long long cntr = 0;
  long long odd = 1;
  long long flago = 0;
  long long flage = 0;
  while (flago != 1 && flage != 1) {
    cntr = 0;
    if (odd) {
      for (long long i = 0; i < n - 1; i += 2) {
        if (v[i] > v[i + 1]) {
          swap(v[i], v[i + 1]);
          cntr++;
        }
      }
      if (!cntr) flago = 1;
    } else {
      for (long long i = 1; i < n; i += 2) {
        if (v[i] > v[i + 1]) {
          swap(v[i], v[i + 1]);
          cntr++;
        }
      }
      if (!cntr) flage = 1;
    }
    odd = odd ^ 1;
    level++;
  }
  cout << level - 1 << endl;
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
