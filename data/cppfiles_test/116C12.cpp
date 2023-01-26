#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
void solve() {
  int n;
  cin >> n;
  vector<long long> d0(n + 5);
  vector<long long> d1(n + 5);
  vector<long long> e0(n + 5);
  vector<long long> e1(n + 5);
  d0[0] = 1;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    if (x > 0) e1[x - 1] += d0[x - 1];
    e0[x + 1] += d0[x];
    e0[x + 1] += d0[x + 1];
    if (x > 0) e1[x - 1] += d1[x - 1];
    e1[x + 1] += d1[x + 1];
    for (int y = x - 1; y <= x + 1; y++) {
      if (y < 0) continue;
      d0[y] = (d0[y] + e0[y]) % mod;
      d1[y] = (d1[y] + e1[y]) % mod;
      e0[y] = e1[y] = 0;
    }
  }
  long long r = 0;
  for (int i = 0; i <= n; i++) r = (r + d0[i] + d1[i]) % mod;
  r = (r - 1 + mod) % mod;
  cout << r << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test_case;
  cin >> test_case;
  while (test_case--) solve();
}
