#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long countab(long long n) {
  if (n <= 6) return 15;
  if (n <= 8) return 20;
  if (n <= 10) return 25;
  if (n <= 12) return 30;
  if (n <= 14) return 35;
  if (n <= 16) return 40;
  if (n <= 18) return 45;
  return 50;
}
void solve() {
  long long n;
  cin >> n;
  long long a = 0;
  long long b = 0;
  long long c = 0;
  if (n > 20) {
    cout << 25 * ((n - 10) / 10) + countab(n % 10 + 10) << '\n';
  } else {
    cout << countab(n) << '\n';
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
