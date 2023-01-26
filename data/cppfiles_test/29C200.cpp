#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5, INF = 1e9 + 5, mod = 1e9 + 7;
long long n, sum, z, o, in, ans;
void doWork() {
  ans = sum = z = o = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> in;
    sum += in;
    z += (in == 0);
    o += (in == 1);
  }
  if (sum == 1)
    ans = pow(2, z);
  else {
    if (!z)
      ans = o;
    else
      ans = o + (o * (pow(2, z) - 1));
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int test = 1;
  cin >> test;
  while (test--) doWork();
}
