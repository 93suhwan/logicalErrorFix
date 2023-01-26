#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 11;
const long long INF = 1e9 + 7;
const long long MOD = 123456789;
const long long LOG = 19;
const long long BASE = 277;
const long long dx[] = {0, 1, 0, -1};
const long long dy[] = {-1, 0, 1, 0};
long long n, H;
long long a[N];
long long b[N];
void solve() {
  cin >> n;
  for (long long i = 1, _b = (n); i <= _b; i++) cin >> a[i];
  long long res = 0;
  for (long long i = 1, _b = (n); i <= _b; i++) {
    if (a[i] > i) res = max(res, a[i] - i);
  }
  cout << res << endl;
}
signed main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long tc = 1;
  cin >> tc;
  while (tc--) solve();
  return 0;
}
