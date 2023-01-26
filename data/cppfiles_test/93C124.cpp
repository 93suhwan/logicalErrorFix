#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print(T &xxx) {
  for (auto &it : xxx) cout << it << " ";
  cout << "\n";
}
long long computeXOR(long long n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}
void solve(long long tc) {
  long long a, b;
  cin >> a >> b;
  long long ans = a;
  long long xr = computeXOR(a - 1);
  if (xr == b) {
    cout << ans << "\n";
    return;
  }
  xr = xr ^ b;
  if (xr == a)
    ans += 2;
  else
    ans += 1;
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long tc = 1; tc <= t; tc++) {
    solve(tc);
  }
  return 0;
}
