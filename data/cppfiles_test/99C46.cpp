#include <bits/stdc++.h>
using namespace std;
long long tc, x0, n;
int main() {
  cin >> tc;
  for (long long t = 0; t < tc; t++) {
    cin >> x0 >> n;
    long long tmp;
    if (abs(x0) % 2) {
      if (n == 1) x0 += 1;
      if ((n - 2) % 4 == 0) x0 += -1;
      if ((n - 2) % 4 == 1) x0 += (n + 1) * -1;
      if ((n - 2) % 4 == 2) x0 += 0;
      if ((n - 2) % 4 == 3) x0 += n;
    } else {
      if (n == 1) x0 += -1;
      if ((n - 2) % 4 == 0) x0 += 1;
      if ((n - 2) % 4 == 1) x0 += (n + 1);
      if ((n - 2) % 4 == 2) x0 += 0;
      if ((n - 2) % 4 == 3) x0 += n * -1;
    }
    cout << x0 << endl;
  }
}
