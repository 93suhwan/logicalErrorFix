#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a[7];
    for (long long i = 0; i < 7; i++) {
      cin >> a[i];
    }
    sort(a, a + 7);
    cout << a[0] << " " << a[1] << " " << a[6] - (a[0] + a[1]) << '\n';
  }
  return 0;
}
