#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a[7];
    for (int i = 0; i < 7; i++) {
      cin >> a[i];
    }
    cout << a[0] << ' ' << a[1] << ' ';
    if (a[2] == a[0] + a[1]) {
      cout << a[3] << '\n';
    } else {
      cout << a[2] << '\n';
    }
  }
  return 0;
}
