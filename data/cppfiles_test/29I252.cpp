#include <bits/stdc++.h>
using namespace std;
int MAX = 1e6 + 100;
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long o = 0, sum = 0, z = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      sum += x;
      if (x == 1) o++;
      if (x == 0) z++;
    }
    if (o == 0) cout << 0 << endl;
    if (o >= 1 and z == 0)
      cout << o << endl;
    else if (o == 1 and z >= 1)
      cout << z * 2 << endl;
    else if (o >= 1 and z >= 1)
      cout << z * 2 + o << endl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
