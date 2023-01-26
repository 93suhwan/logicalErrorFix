#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 5;
const int P = 1e9 + 7;
int t, n;
void solve() {
  if (n % 3 == 0) {
    cout << n / 3 << " " << n / 3 << endl;
  } else if ((n + 2) % 3 == 0) {
    cout << (n + 2) / 3 << " " << (n + 2) / 3 - 1 << endl;
  } else {
    cout << (n - 2) / 3 << " " << (n - 2) / 3 + 1 << endl;
  }
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    solve();
  }
  return 0;
}
