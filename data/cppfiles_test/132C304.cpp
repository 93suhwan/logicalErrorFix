#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, b, c;
  long long arr[7];
  for (long long i = 0; i < 7; i++) cin >> arr[i];
  a = arr[0];
  b = arr[1];
  if (arr[2] == a + b)
    c = arr[3];
  else
    c = arr[2];
  cout << a << " " << b << " " << c << endl;
  return;
}
signed main() {
  long long i, t;
  cin >> t;
  while (t--) solve();
  return 0;
}
