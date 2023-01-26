#include <bits/stdc++.h>
using namespace std;
int a[100], sum;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    sum = 0;
    int y = 0, l = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum += a[i];
      if (a[i] == 1) y++;
      if (a[i] == 0) l++;
    }
    if (y == 0)
      cout << 0 << endl;
    else if (l == 0)
      cout << y << endl;
    else
      cout << y * pow(2, l) << endl;
  }
}
