#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, y, n;
  cin >> t;
  while (t--) {
    cin >> n;
    char a[n];
    char b[n];
    scanf("%s", a);
    scanf("%s", b);
    y = 0;
    for (int i = 1; i < n - 1; i++) {
      if (a[i] == '1' && b[i] == '1') {
        break;
      } else {
        y++;
      }
    }
    if (y == n - 2)
      cout << "YES\n";
    else
      cout << "NO \n";
  }
}
