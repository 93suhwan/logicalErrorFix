#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 100;
const long long mod = 1e9 + 7;
const long long inf = 1000000000;
long long a, b, c;
long long get(long long x, long long y) {
  cout << "? " << x << " " << y << "\n";
  cout.flush();
  long long ans;
  cin >> ans;
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  a = get(0, 0);
  b = get(0, inf);
  c = get(inf, 0);
  long long l = 0, r = inf, mid;
  while (r - l > 1) {
    mid = (l + r) >> 1;
    if (get(0, mid) == a - mid)
      l = mid;
    else
      r = mid;
  }
  cout << "! " << a - l << " " << l << " " << inf - (c - l) << " "
       << inf - (b - (a - l)) << "\n";
  cout.flush();
  return 0;
}
