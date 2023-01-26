#include <bits/stdc++.h>
using namespace std;
const long long maxn = 5e5 + 10;
const long long maxm = 1e3 + 10;
const long long INF = 0x3f3f3f3f;
const long long dx[] = {0, 0, -1, 1};
const long long dy[] = {1, -1, 0, 0};
const long long P = 1e9 + 7;
void solve() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long ans = a + b * 2 + c * 3;
  if (ans & 1) {
    cout << 1 << '\n';
  } else
    cout << 0 << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  while (T--) solve();
  return 0;
}
