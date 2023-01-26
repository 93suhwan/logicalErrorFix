#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long dx8[] = {1, 1, 0, -1, -1, -1, 0, 1};
long long dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};
long long dx4[] = {1, 0, -1, 0};
long long dy4[] = {0, 1, 0, -1};
void solve(long long t) {
  long long n;
  cin >> n;
  string str;
  cin >> str;
  long long a1 = -1, b1 = -1, mx = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      if (abs(i - j) > 1) {
        long long a = 0, b = 0;
        for (long long k = min(j, i); k <= max(j, i); k++) {
          if (str[k] == 'a') {
            a++;
          } else {
            b++;
          }
        }
        if (a == b) {
          cout << min(i + 1, j + 1) << " " << max(i + 1, j + 1) << "\n";
          return;
        }
      }
    }
  }
  cout << a1 << " " << b1 << "\n";
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long t = 1;
  cin >> t;
  long long x = 1;
  while (t--) {
    solve(x);
    x++;
  }
}
