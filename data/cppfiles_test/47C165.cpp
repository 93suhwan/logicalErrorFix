#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k, x = 0, y = 0;
  cin >> n >> k;
  vector<long long> a, b;
  for (long long i = 0; i < n; i++) {
    cin >> x;
    if (x > 0)
      a.push_back(x);
    else
      b.push_back(abs(x));
  }
  x = a.size();
  y = b.size();
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  long long sum = 0;
  for (long long i = x - 1; i >= 0; i -= k) {
    sum += a[i];
  }
  for (long long i = y - 1; i >= 0; i -= k) {
    sum += b[i];
  }
  sum *= 2;
  if (x == 0)
    sum -= b[y - 1];
  else if (y == 0)
    sum -= a[x - 1];
  else
    sum -= max(a[x - 1], b[y - 1]);
  cout << sum << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
