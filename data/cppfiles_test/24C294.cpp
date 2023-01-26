#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  if (n < 9) {
    cout << 0 << endl;
  } else {
    n = n + 1;
    cout << n / 10 << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t != 0) {
    t--;
    solve();
  }
  return 0;
}
