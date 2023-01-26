#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int a[n];
    int c = 0, c1 = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] % 2 == 0)
        c++;
      else
        c1++;
    }
    if (c1 > c)
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
}
