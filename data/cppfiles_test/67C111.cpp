#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    if (a > b) {
      swap(a, b);
    }
    long long int total = 2 * (b - a);
    if (a * 2 > b || total < c) {
      cout << -1 << "\n";
      continue;
    }
    long long int d = c + (c > (b - a) ? -(b - a) : (b - a));
    if (d == b || d == a) {
      cout << -1 << "\n";
      continue;
    }
    cout << d << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << "\n";
  return 0;
}
