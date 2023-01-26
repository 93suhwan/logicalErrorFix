#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  long long n, x;
  cin >> n;
  x = n;
  vector<long long> a(n + 1, 1);
  if (n % 2) a[n] = 0, x--;
  a[x / 2] = 0;
  if ((x % 4)) a[2] = 0;
  a[0] = 0;
  if (n == 1) a[n] = 1;
  cout << accumulate(a.begin(), a.end(), 0) << '\n';
  for (long long i = 1; i <= n; i++) {
    if (a[i]) cout << i << ' ';
  }
}
