#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n % 2)
      cout << n / 2 << " " << n / 2 + 1 << endl;
    else {
      for (long long int i = 2; i < n; i++) {
        if ((n - i) % (i + 1) == 0) {
          long long int l = (n - i) / (i + 1);
          cout << l << " " << l + i << endl;
          break;
        }
      }
    }
  }
}
