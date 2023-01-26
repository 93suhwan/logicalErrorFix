#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    long long int x, n;
    cin >> x >> n;
    if (x % 2 == 0) {
      if (n % 4 == 2)
        x += 1;
      else if (n % 4 == 0)
        x = x;
      else if (n % 4 == 1)
        x -= n;
      else
        x += (n + 1);
    } else {
      if (n % 4 == 0)
        x = x;
      else if (n % 4 == 2)
        x -= 1;
      else if (n % 4 == 1)
        x += n;
      else
        x -= (n + 1);
    }
    cout << x << endl;
  }
  return 0;
}
