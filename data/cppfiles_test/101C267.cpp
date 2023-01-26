#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2 * 1e5 + 10, maxm = 8 * maxn + 2 * maxn, mod = 1e9 + 7;
const long long inf32 = 0x3f3f3f3f;
const long long inf64 = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1), eps = 1e-7;
long long T;
long long n;
pair<long long, long long> a[maxn];
bool solve() {
  sort(a + 1, a + 1 + n);
  for (long long i = 1; i <= n; i++) {
    if (a[i].second > i && a[i].first == 1) return false;
    if (a[i].second < i && a[i].first == 0) return false;
  }
  return true;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i].second;
    for (long long i = 1; i <= n; i++) {
      char c;
      cin >> c;
      if (c == 'R')
        a[i].first = 1;
      else
        a[i].first = 0;
    }
    if (solve())
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}
