#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, k;
  cin >> t;
  for (int z = 0; z < t; ++z) {
    int n = 0, r, c, temp;
    cin >> k;
    while (k - n * n > 0) ++n;
    temp = (n - 1) * (n - 1) + 1;
    r = 1;
    c = n;
    for (int i = 0; i < k - temp; ++i) {
      if (r < n)
        ++r;
      else
        --c;
    }
    cout << r << " " << c << endl;
  }
  return 0;
}
