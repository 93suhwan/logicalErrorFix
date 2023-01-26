#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int k;
  cin >> k;
  if (k == 1) {
    cout << "1 1" << endl;
  } else {
    int i = sqrt(k);
    if (i * i == k) {
      cout << i << " 1" << endl;
    } else {
      int j;
      if (k - i * i < i + 1) {
        cout << k - i * i << " " << i + 1 << endl;
      } else {
        cout << i + 1 << " " << ((i + 1) - (k - i * i - (i + 1))) << endl;
      }
    }
  }
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
