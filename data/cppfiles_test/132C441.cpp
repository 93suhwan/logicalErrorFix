#include <bits/stdc++.h>
const double eps = 1e-2;
using namespace std;
void solve() {
  vector<int> b(7);
  for (int i = 0; i < 7; i++) {
    cin >> b[i];
  }
  cout << b[0] << " " << b[1] << " " << b[6] - b[0] - b[1] << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
