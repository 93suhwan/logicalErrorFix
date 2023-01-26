#include <bits/stdc++.h>
using namespace std;
long long n, g[203], x;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> x;
  while (x--) {
    cin >> n;
    for (long long i = 0; i < n; i++) {
      cin >> g[i];
      if (i > 0) {
        g[i] &= g[i - 1];
      }
    }
    cout << g[n - 1] << endl;
  }
  return 0;
}
