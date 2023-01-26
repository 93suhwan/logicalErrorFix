#include <bits/stdc++.h>
long long const N = 1e5 + 9, MOD = 1e9 + 7, INF = 1e18;
using namespace std;
void test(int tc);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1, tc = 1;
  cin >> t;
  while (t--) test(tc++);
}
void test(int tc) {
  long long n, m;
  cin >> n >> m;
  long long g = 1;
  long long ans = 0;
  while (g < m) {
    g += g;
    ans++;
  }
  n -= g;
  long long gg = 0;
  if (n >= 1) {
    gg = (n / m);
    if (n % m != 0) gg++;
  }
  cout << ans + gg << "\n";
}
