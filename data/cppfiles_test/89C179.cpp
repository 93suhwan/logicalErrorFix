#include <bits/stdc++.h>
using namespace std;
void hehe() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  if (v[0] % 2 == 0) {
    cout << "NO\n";
    return;
  }
  for (long long i = 0; i < n; i++) {
    if (v[i] % 2 == 0) {
      long long x = 0;
      for (long long j = 2; j < 50; j++) {
        if (v[i] % j != 0 && j <= i + 2) {
          x = 1;
          break;
        }
      }
      if (!x) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) hehe();
  return 0;
}
