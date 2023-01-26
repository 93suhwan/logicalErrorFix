#include <bits/stdc++.h>
using namespace std;
int mod1 = 998244353;
int mod2 = 1000000007;
int MOD = mod2;
long long int gcd(long long int a, long long int b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int power(long long int a, long long int n) {
  long long int res = 1;
  while (n > 0) {
    if (n & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    n /= 2;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, u, v, q, t;
  cin >> n >> m;
  vector<int> big(n + 1, 0), neigh(n + 1, 0);
  int ans = n;
  while (m--) {
    cin >> u >> v;
    neigh[u]++;
    neigh[v]++;
    if (u < v) {
      if (big[u] == 0) ans--;
      big[u]++;
    } else {
      if (big[v] == 0) ans--;
      big[v]++;
    }
  }
  cin >> q;
  while (q--) {
    cin >> t;
    if (t == 1) {
      cin >> u >> v;
      neigh[u]++;
      neigh[v]++;
      if (u < v) {
        if (big[u] == 0) ans--;
        big[u]++;
      } else {
        if (big[v] == 0) ans--;
        big[v]++;
      }
    } else if (t == 2) {
      cin >> u >> v;
      neigh[u]--;
      neigh[v]--;
      if (u < v) {
        big[u]--;
        if (big[u] == 0 && neigh[u] > 0) ans++;
      } else {
        big[v]--;
        if (big[v] == 0 && neigh[v] > 0) ans++;
      }
    } else
      cout << ans << "\n";
  }
  return 0;
}
