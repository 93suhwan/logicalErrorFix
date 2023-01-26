#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    if ((n - 1) % 2 == 1) {
      cout << (n - 1) / 2 << " " << (n - 1) / 2 + 1 << " "
           << "1" << endl;
      continue;
    }
    if ((n - 1) % 4 == 0) {
      cout << (n - 1) / 2 - 1 << " " << (n - 1) / 2 + 1 << " "
           << "1" << endl;
      continue;
    }
    cout << (n - 1) / 2 - 2 << " " << (n - 1) / 2 + 2 << " "
         << "1" << endl;
  }
}
