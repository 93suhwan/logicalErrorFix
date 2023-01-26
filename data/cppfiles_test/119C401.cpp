#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, i, s = 0;
    cin >> n;
    long long int a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
      s += a[i];
    }
    if (s % n == 0)
      cout << "0\n";
    else
      cout << "1\n";
  }
}
