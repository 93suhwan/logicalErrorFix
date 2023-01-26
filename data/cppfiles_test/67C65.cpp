#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string P;
  long long n;
  cin >> n >> P;
  long long amp = 0;
  long long mul = 10000;
  for (char c : P) {
    if (c == '.') continue;
    amp += (long long)(c - '0') * mul;
    mul /= 10;
  }
  mul = 10000;
  long long ans = n;
  long long RHS = 2LL * n * (n - 1) * (n - 2) * amp;
  for (int i = 0; i <= n; i++) {
    long long t1, t2, t3;
    t1 = t2 = t3 = 0;
    long long R = i;
    if (R >= 1 && n - R >= 2) {
      t1 = 3LL * R * (n - R) * (n - R - 1);
    }
    if (R >= 2 && n - R >= 1) {
      t2 = 6LL * R * (R - 1) * (n - R);
    }
    if (R >= 3) {
      t3 = 2LL * R * (R - 1) * (R - 2);
    }
    if ((t1 + t2 + t3) * mul >= RHS) {
      ans = R;
      break;
    }
  }
  cout << ans;
  return 0;
}
