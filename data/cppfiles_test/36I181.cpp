#include <bits/stdc++.h>
using namespace std;
long long v[100005];
int main() {
  ios_base::sync_with_stdio(false);
  long long t, n, i, j, k, m;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n % 2) {
      cout << 'c';
      --n;
    }
    for (i = 1; i < n / 2; ++i) cout << 'a';
    cout << 'b';
    for (i = 1; i <= n / 2; ++i) cout << 'a';
    cout << '\n';
  }
  return 0;
}
