#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  string a;
  int sum = 0, sum0 = 0;
  cin >> t;
  while (t--) {
    cin >> n;
    sum = 0;
    sum0 = 0;
    cin >> a;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] != '0') {
        sum0++;
      }
      sum += (int)(a[i] - '0');
    }
    sum += sum0;
    sum += (int)(a[n - 1] - '0');
    cout << sum << endl;
  }
  return 0;
}
