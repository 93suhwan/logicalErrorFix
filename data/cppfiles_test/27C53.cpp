#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
void solve() {
  k = k - 2;
  long long res = n * (n - 1) / 2;
  if (n == 1) {
    if (m != 0)
      cout << "NO" << endl;
    else if (k < 0)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
    return;
  } else {
    if (m > res || m < n - 1 || k < 1)
      cout << "NO" << endl;
    else if (k == 1 && m == res)
      cout << "YES" << endl;
    else if (k == 1 && m != res)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    long long ans = 0x3f3f3f;
    solve();
  }
  return 0;
}
