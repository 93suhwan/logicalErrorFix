#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n = 3;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  if (a[0] + a[1] == a[2])
    cout << "YES\n";
  else if (a[0] == a[1] && a[2] % 2 == 0)
    cout << "YES" << endl;
  else if (a[1] == a[2] && a[0] % 2 == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
