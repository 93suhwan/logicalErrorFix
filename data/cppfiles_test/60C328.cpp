#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, i, j;
    cin >> n;
    long long v[n];
    for (i = 0; i < n; i++) {
      cin >> v[i];
      if (i)
        j &= v[i];
      else
        j = v[i];
    }
    cout << j << '\n';
  }
  return 0;
}
