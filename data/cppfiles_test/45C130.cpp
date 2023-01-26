#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
const long long int maxn = 2e5 + 16, md = 1e9 + 7, inf = 2e16;
long long int gcd(long long int a, long long int b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
inline long long int tav(long long int n, long long int k) {
  long long int res = 1;
  while (k > 0) {
    if (k & 1) {
      res *= n;
      res %= md;
    }
    n *= n;
    n %= md;
    k >>= 1;
  }
  return res;
}
long long int a[maxn];
void solve() {
  long long int n, cur = 1;
  bool dead = false;
  cin >> n;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    if (i) {
      if (!a[i] && !a[i - 1]) {
        dead = true;
      }
    }
    cur += a[i];
    cur += 4 * (a[i] == 1 && a[i - 1] == 1);
  }
  if (dead) {
    cout << "-1\n";
    return;
  }
  cout << cur << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
