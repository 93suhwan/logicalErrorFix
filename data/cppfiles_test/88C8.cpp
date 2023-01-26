#include <bits/stdc++.h>
using namespace std;
const long long N = 100010, fact = 402653189, MAX = -1e10;
long long ar[N], n, k, a, b, yes, t, mx, pos;
int main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    yes = 0;
    for (int i = 1; i <= n; i++) {
      cin >> ar[i];
      if (ar[i] <= ar[i - 1]) yes = 1;
    }
    if (n % 2 == 0 || ((n % 2 == 1) && yes)) {
      cout << "YES\n";
      continue;
    }
    cout << "NO\n";
  }
}
