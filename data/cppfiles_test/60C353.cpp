#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, a[101], i, b;
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    b = a[0];
    for (i = 1; i < n; i++) {
      b = b & a[i];
    }
    cout << b << endl;
  }
}
