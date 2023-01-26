#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, i, e = 0, f = 0;
    cin >> n;
    char a[n], b[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(a, a + n);
    for (i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        e++;
      }
    }
    cout << e << endl;
  }
}
