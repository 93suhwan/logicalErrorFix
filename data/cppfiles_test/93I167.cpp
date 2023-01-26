#include <bits/stdc++.h>
using namespace std;
template <typename T>
static inline void sd(vector<T> &x) {
  sort((x).begin(), (x).end(), greater<T>());
}
void solve() {
  long long a, b;
  cin >> a >> b;
  long long ans = a - 1;
  long long x = 0;
  long long r = (a - 1 % 4);
  if (r == 0)
    x = a - 1;
  else if (r == 1)
    x = 1;
  else if (r == 2)
    x = a;
  else
    x = 0;
  if (x == b) {
    cout << ans + 1 << '\n';
    return;
  } else {
    long long p = x ^ b;
    if (p == a)
      cout << ans + 3 << '\n';
    else
      cout << ans + 2 << '\n';
  }
  return;
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long testcases = 1;
  cin >> testcases;
  while (testcases--) {
    solve();
  }
  return 0;
}
