#include <bits/stdc++.h>
using namespace std;
long long int t, i, p, n, l, k, j, a[1000000], b[1000000], c, d;
int main() {
  cin >> t;
  while (t--) {
    for (i = 0; i < 7; i++) cin >> a[i];
    sort(a, a + n);
    cout << a[0] << " " << a[1] << " ";
    c = a[0] + a[1];
    if (a[2] != c || a[2] == a[3])
      cout << a[2] << endl;
    else
      cout << a[3] << endl;
  }
}
