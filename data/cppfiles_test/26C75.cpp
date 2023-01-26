#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010];
int t, n;
long long sum = 0;
const int mod = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  long long res = 1;
  for (int i = 3; i <= 2 * n; i++) res = res * i % mod;
  cout << res << endl;
}
int main() {
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
