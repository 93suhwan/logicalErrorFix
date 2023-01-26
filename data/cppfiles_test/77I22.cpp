#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long f[4000005], sum[4000005];
void solve() {
  cin >> n >> m;
  f[n] = 1;
  sum[n] = 1;
  for (int i = n - 1; i >= 1; i--) {
    f[i] = sum[i + 1];
    for (int j = 2; j <= n / i; j++) {
      f[i] = (f[i] + (sum[i * j] - sum[i * j + j] + m)) % m;
    }
    sum[i] = (sum[i + 1] + f[i]) % m;
  }
  cout << f[1] % m;
}
int main() {
  ios::sync_with_stdio(false);
  solve();
}
