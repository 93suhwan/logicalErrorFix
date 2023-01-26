#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long dx[] = {0, 0, -1, 1};
long long dy[] = {1, -1, 0, 0};
long long inf = 1e18;
bool check(long long a, long long b) {
  if (a % b == 0) return 1;
  return 0;
}
long long fgcd(long long a, long long b) {
  if (b == 0) return a;
  return fgcd(b, a % b);
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n + 1);
  long long lc = 2;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if (a[1] % 2 == 0) {
    cout << "NO\n";
    return;
  }
  for (long long i = 2; i <= n; i++) {
    long long gc = fgcd(i + 1, lc);
    lc = (lc * (i + 1)) / gc;
    if (check(a[i], lc)) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t_c = 1;
  cin >> t_c;
  for (long long t_case = 1; t_case <= t_c; t_case++) {
    solve();
  }
  return 0;
}
