#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    int a[8];
    for (int i = 0; i < 7; i++) {
      cin >> a[i];
    }
    cout << a[0] << " " << a[1] << " ";
    if (a[0] + a[1] != a[2])
      cout << a[2] << "\n";
    else {
      cout << a[3] << "\n";
    }
  }
}
