#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  if (n % 3 == 0) {
    cout << n / 3 << " " << n / 3;
  } else if (n % 3 == 1) {
    cout << (n / 3) + 1 << " " << n / 3;
  } else if (n % 3 == 2) {
    cout << n / 3 << " " << (n / 3) + 1;
  }
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
