#include <bits/stdc++.h>
using namespace std;
const long long int maxn = 1e5 + 5;
const long long int modn = 1e9 + 7;
void solve() {
  long long int n;
  cin >> n;
  if (n <= 26) {
    for (long long int i = 0; i < n; i++) cout << (char)(i + 'a');
    cout << '\n';
    return;
  }
  for (long long int i = 1; i <= n / 2; i++) {
    cout << 'h';
  }
  cout << 'x';
  if (n % 2) cout << 'y';
  for (long long int i = 1; i < n / 2; i++) {
    cout << 'h';
  }
  cout << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long int tc = 1;
  cin >> tc;
  for (long long int i = 1; i < tc + 1; i++) {
    solve();
  }
  return 0;
}
