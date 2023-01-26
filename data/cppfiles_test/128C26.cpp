#include <bits/stdc++.h>
using namespace std;
long long mod = pow(10, 9) + 7;
long long power(long long n, long long k) {
  long long res = 1;
  while (k) {
    if (k % 2 != 0) {
      res *= n;
    }
    n = n * n;
    k /= 2;
  }
  return res;
}
void solve() {
  long long n;
  cin >> n;
  long long x = n - 1;
  long long y = x / 2;
  if (x % 2 == 1) {
    cout << y + 1 << " " << y << " 1";
  } else {
    if (y % 2 == 1) {
      cout << y + 2 << " " << y - 2 << " 1";
    } else
      cout << y + 1 << " " << y - 1 << " 1";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
