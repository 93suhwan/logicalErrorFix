#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int k;
  cin >> k;
  if (k == 1) {
    cout << "1 1" << endl;
  } else if (k == 2) {
    cout << "1 2" << endl;
  } else if (k == 3) {
    cout << "2 2" << endl;
  } else if (k == 4) {
    cout << "2 1" << endl;
  } else {
    int i = sqrt(k);
    if (i * i == k) {
      cout << "1 " << i << endl;
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
