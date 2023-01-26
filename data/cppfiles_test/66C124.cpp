#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int k;
    cin >> k;
    for (int i = 0;; i++) {
      if (i % 3 == 0 || i % 10 == 3) {
        continue;
      }
      if (--k == 0) {
        cout << i << endl;
        break;
      }
    }
  }
}
int main() {
  solve();
  return 0;
}
