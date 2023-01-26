#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, k;
  cin >> t;
  while (t--) {
    cin >> k;
    long long s = ceil(sqrt(k));
    long long x = s * s;
    if (x == k)
      cout << s << " " << 1 << endl;
    else if (s - x + k == 1)
      cout << s << " " << s << endl;
    else if (s - x + k < 1)
      cout << k - (s - 1) * (s - 1) << " " << s << endl;
    else
      cout << s << " " << s * s - k + 1 << endl;
  }
  return 0;
}
