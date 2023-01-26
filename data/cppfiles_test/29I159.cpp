#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int64_t s0 = 0, s1 = 0;
    int64_t a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 0) s0++;
      if (a[i] == 1) s1++;
    }
    cout << ((1 << s0) * s1) << endl;
  }
  return 0;
}
