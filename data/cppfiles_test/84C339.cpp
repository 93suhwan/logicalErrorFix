#include <bits/stdc++.h>
using namespace std;
void go() {
  long long int n, s, o = 0, e = 0, k;
  cin >> n >> s;
  if (n % 2 == 0)
    e = 1;
  else
    o = 1;
  if (e == 1)
    k = ((n - 1) / 2 + 1) + 1;
  else
    k = ((n - 1) / 2 + 1);
  cout << s / k << "\n";
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    go();
  }
  return 0;
}
