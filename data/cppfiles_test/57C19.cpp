#include <bits/stdc++.h>
using namespace std;
void solve() {
  int64_t s, n, k;
  cin >> s >> n >> k;
  if (s == k) {
    cout << "YES" << endl;
    return;
  }
  int64_t block_size = 2 * k;
  int64_t ans = s - (s / block_size) * block_size + 1;
  if (min(ans, k) + s / block_size * k > n) {
    cout << "NO" << endl;
  } else
    cout << "YES" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t > 0) {
    t--;
    solve();
  }
}
