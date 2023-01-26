#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long moD = 998244353;
const long long INF = 1e18;
const long long inf = 1e9;
long double pi = 2 * acos(0.0);
long long expo_mania(long long y, long long x) {
  if (x == 0) return 1;
  if (x == 1)
    return y;
  else if (!(x & 1))
    return expo_mania(y * y, x / 2);
  else
    return expo_mania(y * y, x / 2) * y;
}
int tarr[1];
void vuid() {
  tarr[1] = 1;
  for (long long i = 2; i * 2 <= 9999998; i++) {
    tarr[i * 2] = 1;
  }
  for (long long i = 3; i <= 9999; i += 2) {
    for (long long j = 2; j * i <= 9999999; j++) {
      tarr[j * i] = 1;
    }
  }
}
double radian(double x) {
  double ans = x * pi;
  ans = ans / (double)180;
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      sum += x;
    }
    if (sum % n == 0)
      cout << 0 << endl;
    else
      cout << 1 << endl;
  }
}
