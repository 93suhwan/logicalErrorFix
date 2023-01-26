#include <bits/stdc++.h>
using namespace std;
int main() {
  long int N;
  cin >> N;
  while (N--) {
    long int n;
    cin >> n;
    long int a[n];
    long int y = 0, x = 0;
    for (long int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 0)
        y++;
      else if (a[i] == 1)
        x++;
    }
    if (y > 0)
      cout << x + (x * y) + y - 1 << endl;
    else
      cout << x << endl;
  }
  return 0;
}
