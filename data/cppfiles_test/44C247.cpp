#include <bits/stdc++.h>
using namespace std;
long long int x, t, n, k, m, c, a, b, i, j, cc = 0, sum = 0, cnt = 0;
void intit_code() {}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  intit_code();
  long long int t;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    int x = abs(a - b);
    int ans;
    if (a == 0 && b == 0)
      ans = 0;
    else if (x == 0)
      ans = 1;
    else if (x % 2 == 0)
      ans = 2;
    else
      ans = -1;
    cout << ans << endl;
  }
  return 0;
}
