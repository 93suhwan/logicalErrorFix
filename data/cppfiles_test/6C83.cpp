#include <bits/stdc++.h>
using namespace std;
const long long N = 3 * 1e5 + 1;
vector<bool> resh(int n) {
  vector<bool> v(n + 1, false);
  for (int i = 3; i * i <= n; i += 2) {
    if (!v[i]) {
      for (int j = i * i; j <= n; j += i) {
        v[j] = true;
      }
    }
  }
  return v;
}
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
int binpow(int a, int n) {
  int res = 1;
  while (n) {
    if (n & 1) res *= a;
    a *= a;
    n >>= 1;
  }
  return res;
}
int ei(int n) {
  int result = n;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      result -= result / i;
    }
  if (n > 1) result -= result / n;
  return result;
}
int a[N];
void solve() {
  int n, m, ans = 0;
  cin >> n >> m;
  ans = n;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    int ma = min(u, v);
    if (a[ma] == 0) {
      ans--;
    }
    a[ma]++;
  }
  int t;
  cin >> t;
  while (t--) {
    int ok, u, v;
    cin >> ok;
    if (ok == 3) {
      cout << ans << endl;
    } else {
      int ma = 0;
      cin >> u >> v;
      if (ok == 1) {
        ma = min(u, v);
        if (a[ma] == 0) {
          ans--;
        }
        a[ma]++;
      } else {
        ma = min(v, u);
        if (a[ma] == 1) {
          ans++;
        }
        a[ma]--;
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  while (t--) solve();
  return 0;
}
