#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  for (long long j = 0; j < t; j++) {
    long long a[1002], i = 1, q = 1, k;
    cin >> k;
    while (i <= k) {
      if (q % 3 != 0 && q % 10 != 3) {
        a[i] = q;
        q++;
        i++;
      } else
        q++;
    }
    cout << a[i - 1] << endl;
  }
  return 0;
}
