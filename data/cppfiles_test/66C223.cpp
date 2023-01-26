#include <bits/stdc++.h>
using namespace std;
void fast_io(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void solve(void) {
  int k;
  cin >> k;
  int a = 1;
  while (1) {
    if (a % 10 != 3 && a % 3 != 0) {
      k--;
    }
    a++;
    if (k == 0) {
      break;
    }
  }
  cout << a - 1 << "\n";
}
int main(void) {
  fast_io();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
