#include <bits/stdc++.h>
using namespace std;
const int N = 505;
long long n, sum, a[N];
void solve() {
  sum = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sum %= n;
  if (sum) {
    cout << 1 << '\n';
  } else
    cout << 0 << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test = 1;
  cin >> test;
  while (test--) solve();
}
