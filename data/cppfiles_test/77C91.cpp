#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 1e9 + 7;
void solve() {
  int n;
  cin >> n >> mod;
  vector<ll> a(n + 1);
  a[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (i == 2) {
      a[i] = 2;
    } else {
      a[i] = (a[i] + 2 * a[i - 1] + a[1]) % mod;
    }
    for (int j = 2 * i; j <= n; j += i) {
      a[j] = (a[j] - a[i - 1] + a[i]) % mod;
    }
  }
  if (a[n] < 0) {
    a[n] += mod;
  }
  cout << a[n] << endl;
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  auto start = clock();
  int t = 1;
  for (int i = 0; i < t; i++) {
    solve();
  }
  double used = (double)(clock() - start);
  used = (used * 1000) / CLOCKS_PER_SEC;
  cerr << fixed << setprecision(2) << used << " ms" << endl;
  return 0;
}
