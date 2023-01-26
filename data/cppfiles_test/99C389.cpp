#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long TT, n, x, r;
  cin >> TT;
  while (TT--) {
    cin >> x >> n;
    if (n % 4 == 0)
      r = 0;
    else if (n % 4 == 1)
      r = -n;
    else if (n % 4 == 2)
      r = 1;
    else
      r = (n / 4 + 1) * 4;
    if (abs(x) % 2 == 1) r = -r;
    cout << x + r << '\n';
  }
  return 0;
}
