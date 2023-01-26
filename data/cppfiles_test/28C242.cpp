#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long a, b, c, sum;
  int t;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    sum = 0;
    sum += a * 1;
    sum += b * 2;
    sum += c * 3;
    if (sum % 2)
      cout << 1 << '\n';
    else
      cout << 0 << '\n';
  }
  return 0;
}
