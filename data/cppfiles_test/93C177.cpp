#include <bits/stdc++.h>
using namespace std;
long long xr[300005];
void find_xor() {
  xr[0] = 0;
  for (long long i = 1; i < 300005; ++i) xr[i] = xr[i - 1] ^ i;
}
void solve() {
  long long a, b, ans = 0;
  cin >> a >> b;
  ans += a;
  long long curr_xor = xr[a - 1];
  long long tmp = curr_xor ^ b;
  if (curr_xor == b)
    cout << ans << "\n";
  else if (tmp == a)
    cout << ans + 2 << "\n";
  else
    cout << ans + 1 << "\n";
}
int main() {
  find_xor();
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
