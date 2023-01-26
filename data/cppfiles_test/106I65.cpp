#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int p = 2;
  for (int i = 0; i < n; i++) {
    cout << p << " ";
    p = (p * 2) + 1;
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
