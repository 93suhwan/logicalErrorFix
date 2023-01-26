#include <bits/stdc++.h>
long long T, U;
using namespace std;
long long a[1000005];
int main() {
  ios::sync_with_stdio(false);
  srand(time(NULL));
  cin >> T;
  while (T--) {
    long long n, ok = 0;
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    if (n % 2 == 0) {
      cout << (1 ? "YES" : "NO") << "\n";
      continue;
    }
    for (long long i = 2; i <= n; i++) {
      if (a[i - 1] >= a[i]) ok = 1;
    }
    cout << (ok ? "YES" : "NO") << "\n";
  }
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms";
  return 0;
}
