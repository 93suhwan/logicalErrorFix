#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int M = 2e3 + 5;
const int moh = 1e9 + 3;
const long long mod = 1e9 + 7;
const int base = 311;
const int oi = 2e9;
const long long oo = 1e18;
const double eps = 1e-9;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {-1, 0, 1, 0, -1, 1, -1, 1};
int n, k;
long long po[N];
void solve() {
  cin >> n >> k;
  po[0] = 1;
  for (int i = 1; i <= 30; i++) {
    po[i] = po[i - 1] * n % mod;
  }
  long long ans = 0;
  for (int i = 30; i >= 0; i--) {
    if (k >> i & 1) {
      ans += po[i];
      ans %= mod;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test;
  cin >> test;
  while (test--) {
    solve();
  }
}
