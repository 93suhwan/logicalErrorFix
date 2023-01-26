#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, r, l;
  cin >> n;
  l = -1 * (n - 1);
  r = (n - 1);
  cout << l << ' ';
  cout << r << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
