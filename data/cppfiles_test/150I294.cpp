#include <bits/stdc++.h>
using namespace std;
const long double scale = 1e+6;
const long long mod = 1000000007;
int ispower(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = res * x;
    y = y >> 1;
    x = x * x;
  }
  return res;
}
const long long N = 100001;
using namespace std;
long long t;
cin >> t;
while (t--) {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort((a).begin(), (a).end());
  long long p = 0, q = 0, r = 0, rem;
  for (long long i = n - 2; i >= 0; i--) {
    if (a[i] == a[n - 1]) continue;
    if (a[i] % 3 == 1 && r == 0)
      r = 1;
    else if (a[i] % 3 == 2 && q == 0)
      q = 1;
  }
  rem = a[n - 1] % 3;
  if (rem != 0) rem = 1;
  p = a[n - 1] / 3;
  if (r == 0 && q == 0 && rem == 0)
    cout << p << endl;
  else if (r == 1 && q == 1 && rem == 1)
    cout << p + 2 << endl;
  else if (r == 1 && q == 1 && rem == 0)
    cout << p + 1 << endl;
  else if (p == 0) {
    if (a[n - 1] % 3 == 2 && r == 1)
      cout << 2 << endl;
    else if (a[n - 1] % 3 == 1 && q == 1)
      cout << 2 << endl;
    else if (r == 1 && q == 1)
      cout << 2 << endl;
  } else
    cout << p + 1 << endl;
}
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(25);
  cerr << fixed << setprecision(10);
  auto start = std::chrono::high_resolution_clock::now();
  solve();
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
  return 0;
}
