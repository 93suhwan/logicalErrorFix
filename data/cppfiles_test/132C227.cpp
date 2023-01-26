#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  int a[7];
  cin >> T;
  while (T--) {
    for (int i = 0; i < 7; i++) {
      cin >> a[i];
    }
    cout << a[0] << " " << a[1] << " " << (a[6] - (a[0] + a[1])) << "\n";
  }
  return 0;
}
