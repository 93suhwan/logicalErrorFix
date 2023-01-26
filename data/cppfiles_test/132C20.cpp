#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long a[7];
    for (int i = 0; i < 7; i++) {
      cin >> a[i];
    }
    if (a[0] + a[1] + a[2] == a[6]) {
      cout << a[0] << " " << a[1] << " " << a[2] << '\n';
    } else {
      cout << a[0] << " " << a[1] << " " << a[3] << '\n';
    }
  }
  return 0;
}
