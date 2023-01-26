#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k, mod = 1e9 + 7, i;
  cin >> n >> k;
  long long a[50];
  a[0] = 1;
  for (i = 1; i <= 45; i++) {
    a[i] = a[i - 1] * n;
    a[i] %= mod;
  }
  vector<long long> bt;
  while (k) {
    bt.push_back(k % 2);
    k /= 2;
  }
  long long ans = 0;
  for (i = 0; i < bt.size(); i++) {
    ans += bt[i] * a[i];
    ans %= mod;
  }
  cout << ans << "\n";
}
int main() {
  long long n;
  cin >> n;
  while (n--) {
    solve();
  }
  return 0;
}
