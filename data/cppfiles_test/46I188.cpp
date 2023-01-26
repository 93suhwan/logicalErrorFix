#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, p = 1, c = 0;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
      if (a[i] != a[i + 1]) p = 0;
      break;
    }
    if (p == 1)
      cout << 0 << endl;
    else {
      for (int i = n - 2; i >= 0; i--) {
        if (a[i] >= a[n - 1]) c++;
        a[n - 1] = a[i];
      }
      cout << c - 1 << endl;
    }
  }
}
