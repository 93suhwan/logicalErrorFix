#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  bool ans;
  if (n == 1) {
    if (m != 0)
      ans = false;
    else if (k < 2)
      ans = false;
    else
      ans = true;
  } else {
    if (k < 2)
      ans = false;
    else if (k == 2) {
      if (n == 1)
        ans = true;
      else
        ans = false;
    } else if (k == 3) {
      long long t = (n * (n - 1)) / 2;
      if (m == t)
        ans = true;
      else
        ans = false;
    } else {
      long long t = (n * (n - 1)) / 2;
      if (m >= n - 1 && m <= t)
        ans = true;
      else
        ans = false;
    }
  }
  if (ans)
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) solve();
}
