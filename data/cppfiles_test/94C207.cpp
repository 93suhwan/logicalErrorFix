#include <bits/stdc++.h>
using namespace std;
int a[12];
long long b[12];
long long pre[12];
long long mul[21];
void init() {
  long long x = 1;
  for (int i = 0; i <= 20; i++) {
    mul[i] = x;
    x *= 10;
  }
}
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = mul[a[i]];
  }
  long long dps = k + 1, pos = 1;
  long long ans = 0;
  while (dps > 0 and pos <= n) {
    long long tmp = pos < n ? min(dps, b[pos + 1] / b[pos] - 1) : dps;
    ans += b[pos] * tmp;
    pos++;
    dps -= tmp;
  }
  cout << ans << endl;
}
int main() {
  init();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
