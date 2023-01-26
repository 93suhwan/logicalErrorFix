#include <bits/stdc++.h>
using namespace std;
void kaam() {
  long long int x, n, ans = 0, ctr = 1;
  cin >> x >> n;
  ans = x;
  if (x % 2 == 0) {
    if (n % 4 == 0)
      ans = x;
    else if (n % 4 == 2)
      ans = x + 1;
    else if (n % 4 == 1)
      ans = (x - 1) - 4 * (n / 4);
    else
      ans = ((n / 4) + 1) * 4 + x;
  } else {
    if (n % 4 == 0)
      ans = x;
    else if (n % 4 == 2)
      ans = x - 1;
    else if (n % 4 == 1)
      ans = (x + 1) + 4 * (n / 4);
    else
      ans = x - ((n / 4) + 1) * 4;
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) kaam();
  return 0;
}
