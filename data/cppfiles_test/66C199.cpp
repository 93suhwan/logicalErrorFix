#include <bits/stdc++.h>
using namespace std;
void solve() {
  int k;
  cin >> k;
  int i = 1;
  while (k != 0) {
    if (i % 10 != 3 && i % 3 != 0) k--;
    i++;
  }
  i--;
  cout << i << "\n";
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
