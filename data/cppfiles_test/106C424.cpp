#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int j = 1;
  for (int i = 0; i < n; i++, j += 1) cout << j + 1 << " ";
  cout << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
