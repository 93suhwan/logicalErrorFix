#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007, inf = (9e17), MAX = 2e5 + 5;
long long n, m, i, j;
void solve() {
  cin >> n;
  cout << -(n - 1) << " " << n;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long loser = 1;
  cin >> loser;
  while (loser--) {
    solve();
    cout << "\n";
  }
  return 0;
}
