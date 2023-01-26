#include <bits/stdc++.h>
using namespace std;
long long n, m, k, x, y, z;
long long ar[300005];
deque<long long> pos[300005];
void solve() {
  cin >> n >> m;
  if (n > m) {
    cout << "0\n";
    return;
  }
  int ans = 0;
  for (int i = 30; i >= 0; i--) {
    if (m & (1ll << i) && !(n & (1ll << i))) ans |= (1ll << i);
    if ((n ^ ans) > m) {
      cout << ans << "\n";
      return;
    }
  }
  if ((n ^ ans) <= m) ans++;
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
