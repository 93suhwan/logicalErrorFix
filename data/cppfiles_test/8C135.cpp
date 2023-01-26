#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int k = (n + 1) / 3;
  cout << n - k * 2 << " " << k << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
